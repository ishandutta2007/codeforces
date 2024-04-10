#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

const ll mod = 1000000007;

typedef long long unsigned int llui;
typedef long double float64;

llui mul_mod(llui a, llui b, llui m){
   llui y = (llui)((float64)a*(float64)b/m+(float64)1/2);
   y = y * m;
   llui x = a * b;
   llui r = x - y;
   if ( (ll)r < 0 ){
      r = r + m; y = y - 1;
   }
   return r;
}

llui C,a,b;
llui gcd(){
   llui c;
   if(a>b){
      c = a; a = b; b = c;
   }
   while(1){
      if(a == 1LL) return 1LL;
      if(a == 0 || a == b) return b;
      c = a; a = b%a;
      b = c;
   }
}

llui f(llui a, llui b){
   llui tmp;
   tmp = mul_mod(a,a,b);
   tmp+=C; tmp%=b;
   return tmp;
}

llui pollard(llui n){
   if(!(n&1)) return 2;
   C=0;
   llui iteracoes = 0;
   while(iteracoes <= 1000){
      llui x,y,d;
      x = y = 2; d = 1;
      while(d == 1){
          x = f(x,n);
          y = f(f(y,n),n);
          llui m = (x>y)?(x-y):(y-x);
          a = m; b = n; d = gcd();
      }
      if(d != n)
          return d;
      iteracoes++; C = rand();
   }
   return 1;
}

llui pot(llui a, llui b, llui c){
   if(b == 0) return 1;
   if(b == 1) return a%c;
   llui resp = pot(a,b>>1,c);
   resp = mul_mod(resp,resp,c);
   if(b&1)
      resp = mul_mod(resp,a,c);
   return resp;
}

// Rabin-Miller primality testing algorithm
bool isPrime(llui n){
   llui d = n-1;
   llui s = 0;
   if(n <=3 || n == 5) return true;
   if(!(n&1)) return false;
   while(!(d&1)){ s++; d>>=1; }
   for(llui i = 0;i<32;i++){
      llui a = rand();
      a <<=32;
      a+=rand();
      a%=(n-3); a+=2;
      llui x = pot(a,d,n);
      if(x == 1 || x == n-1) continue;
      for(llui j = 1;j<= s-1;j++){
         x = mul_mod(x,x,n);
         if(x == 1) return false;
         if(x == n-1)break;
      }
      if(x != n-1) return false;
   }
   return true;
}
map<llui,int> factors;
// Precondition: factors is an empty map, n is a positive integer
// Postcondition: factors[p] is the exponent of p in prime factorization of n
void fact(llui n){
   if(!isPrime(n)){
      llui fac = pollard(n);
      fact(n/fac); fact(fac);
   }else{
      map<llui,int>::iterator it;
      it = factors.find(n);
      if(it != factors.end()){
         (*it).second++;
      }else{
         factors[n] = 1;
      }
   }
}

ll modPow(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1)(ans *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ans;
}

void multiply(ll a[50][50], ll b[50][50], ll c[50][50], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            c[i][j] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                c[i][k] += (a[i][j]*b[j][k]);
                c[i][k] %= mod;
            }
        }
    }
}

void multiplyMat(ll a[50][50], ll b[50][50], int n, int k){
    ll tm[50][50];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j)b[i][j] = 1;
            else b[i][j] = 0;
        }
    }
    while(k){
        if(k&1){
            multiply(b, a, tm, n);
            for(int i = 0; i < n; i++){
                for(int j = 0; j < n; j++){
                    b[i][j] = tm[i][j];
                }
            }
        }
        multiply(a, a, tm, n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                a[i][j] = tm[i][j];
            }
        }
        k >>= 1;
    }
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n, k;
    cin>>n>>k;
    fact(n);
    ll a[50][50], b[50][50];
    ll ans = 1;
    for(map<llui,int>::iterator it = factors.begin(); it != factors.end(); it++){
        ll p = it->first;
        int cnt = it->second;
        int tmp = cnt + 1;
        for(int i = 0; i <= cnt; i++){
            for(int j = 0; j <= cnt; j++){
                if(j < i){
                    a[j][i] = 0;
                }else{
                    a[j][i] = modPow(tmp, mod-2);
                }
            }
            tmp--;
        }
        multiplyMat(a, b, cnt + 1, k);
        // for(int i = 0; i < n; i++){
        //     for(int j = 0; j < n; j++){
        //         cout<<b[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        ll tmpans = 0;
        for(int i = 0; i <= cnt; i++){
            tmpans += b[i][0]*modPow(p, cnt-i);
            tmpans %= mod;
        }
        ans *= tmpans;
        ans %= mod;
    }
    cout<<ans<<endl;

}