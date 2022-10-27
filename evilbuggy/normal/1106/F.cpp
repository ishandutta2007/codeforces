#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll extended_euclidean(ll a, ll b, ll &x, ll &y, ll mod){
    ll xx = 0;
    ll yy = 1;
    y = 0; x = 1;
    while(b){
        ll q = a/b;
        ll t = b; b = a%b; a = t;
        t = xx; xx = (mod + (x - q*xx)%mod)%mod; x = t;
        t = yy; yy = (mod + (y - q*yy)%mod)%mod; y = t;
    }
    return a;
}

ll mod_inverse(ll a, ll n){
    ll x, y;
    ll g = extended_euclidean(a, n, x, y, n);
    if(g > 1)return -1;
    return (n + (x%n))%n;
}

const ll mod = 998244353;
const ll gen = 3;

struct Matrix{
    int sz;
    vector<vector<ll> > arr;
    Matrix(int isz = 1){
        sz = isz;
        arr = vector<vector<ll> >(sz + 1, vector<ll>(sz + 1));
    }
    void makeUnit(){
        for(int i = 1; i <= sz; i++){
            for(int j = 1; j <= sz; j++){
                arr[i][j] = (i == j);
            }
        }
    }
    Matrix operator*(const Matrix &a){
        Matrix tmp(sz);
        for(int i = 1; i <= sz; i++){
            for(int j = 1; j <= sz; j++){
                for(int k = 1; k <= sz; k++){
                    (tmp.arr[i][j] += arr[i][k]*a.arr[k][j]) %= (mod - 1);
                }
            }
        }
        return tmp;
    }

    void print(){
        for(int i = 1; i <= sz; i++){
            for(int j = 1; j <= sz; j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
};

ll modPow(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1)(ans *= a) %= mod;
        (a *= a) %= mod;
        b >>= 1;
    }
    return ans;
}

ll discreteLog(ll n){
    ll m = sqrt(double(mod)) + 1;
    map<ll, int> arr;
    ll base = 1;
    for(int i = 0; i < m; i++){
        arr[base] = i;
        (base *= gen) %= mod;
    }
    ll am = modPow(gen, mod - m - 1);
    base = n%mod;
    for(int i = 0; i < m; i++){
        if(arr.find(base) != arr.end()){
            return arr[base] + m*i;
        }
        (base *= am) %= mod;
    }
    return -1;
}

Matrix powerUp(Matrix A, ll b){
    Matrix a(A.sz);
    a.makeUnit();
    while(b){
        if(b&1)a = a*A;
        A = A*A;
        b >>= 1;
    }
    return a;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    int k;
    cin>>k;

    Matrix A(k);
    for(int i = 1; i <= k; i++){
        cin>>A.arr[1][i];
        A.arr[1][i] %= (mod - 1);
    }
    for(int i = 2; i <= k; i++){
        for(int j = 1; j <= k; j++){
            A.arr[i][j] = (i == j + 1);
        }
    }
    // A.print();
    ll n, m;
    cin>>n>>m;
    Matrix B = powerUp(A, n-k);
    // B.print();
    ll hn = discreteLog(m)%(mod - 1);
    ll tt = B.arr[1][1];
    ll x = __gcd(hn, tt);
    if(x == 0){
        cout<<1<<endl;
        return 0;
    }
    hn /= x; tt /= x;
    // cout<<hn<<" "<<tt<<endl;
    ll inv = mod_inverse(tt, mod-1);
    if(inv == -1){
        cout<<-1<<endl;
        return 0;
    }
    ll hk = (hn*inv) % (mod - 1);
    cout<<modPow(gen, hk)<<endl;
}