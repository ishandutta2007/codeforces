#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<__float128,__float128>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
LL f_pow(LL a,LL b,LL mod){
    __int128 res=1,tmp=a;
    while(b){
        if(b&1)res=res*tmp%mod;
        tmp=tmp*tmp%mod;
    }
    return res;
}
bool Isprime(LL n)
{
    if (n == 2) return true;
    if (n < 2 || n % 2 == 0) return false;
    LL u = n - 1, t = 0;
    while (u % 2 == 0) {u >>= 1; t++;}
    LL sprp[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
    for (int k=0; k<7; ++k)
    {
        LL a = sprp[k] % n;
        if (a == 0 || a == 1 || a == n-1) continue;
        long long x = f_pow(a, u, n);
        if (x == 1 || x == n-1) continue;
        for (int i = 0; i < t-1; i++)
        {
            x = f_pow(x, 2, n);
            if (x == 1) return false;
            if (x == n-1) break;
        }
        if (x == n-1) continue;
        return false;
    }
    return true;
}
inline LL f(LL x , LL mod) {
return (x * x % mod + 1) % mod;
}
inline LL pollard_rho(LL n) {
	if(!(n&1)) return 2;
	while(true) {
		LL y = 2 , x = rand() % (n - 1) + 1 , res = 1;
		for(int sz = 2; res == 1; sz *= 2) {
			for(int i = 0; i < sz && res <= 1; i++) {
				x = f(x , n);
				res = __gcd(abs(x - y) , n);
			}
			y = x;
		}
		if (res != 0 && res != n) return res;
	}
}

void solve(){
    LL n;
    scanf("%lld",&n);
    LL pro=1,res=n;
    while(res%2==0){
        pro=pro*2;
        res=res/2;
    }
    pro=pro*2;
    if(2*n/pro-pro-1>=0){
        printf("%lld\n",pro);
    }
    else if(res!=1&&2*n/res-res-1>=0){
        printf("%lld\n",res);
    }
    else{
        if(Isprime(res)||res==1){
            printf("-1\n");
        }
        else{
            LL a=pollard_rho(res);
            if(2*n/a-a-1>=0){
                printf("%lld\n",a);
            }
            else{
                printf("%lld\n",res/a);
            }
        }
    }
}


int main(){
    int t=10000;
  scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*

*/