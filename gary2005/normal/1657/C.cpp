/**
 *    author:  gary
 *    created: 22.03.2022 22:28:49
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=5e5+10;
struct stringhash{
    int A, MOD;
    int quick(int k1, int k2) {
        int k3 = 1;

        for (; k2; k2 >>= 1, k1 = 1LL * k1 * k1 % MOD)
            if (k2 & 1)
                k3 = 1LL * k3 * k1 % MOD;

        return k3;
    }
    int inv(int A) {
        return quick(A, MOD - 2);
    }
    int pw[MAXN], ipw[MAXN];
    void add(int &A, int B) {
        A += B;

        if (A >= MOD)
            A -= MOD;
    }
    void sub(int &A, int B) {
        A += MOD - B;

        if (A >= MOD)
            A -= MOD;
    }
    int val[MAXN];
    string S;
    stringhash(int _, int __) {
        memset(val, 0, sizeof(val));
        A = _;
        MOD = __;
        pw[0] = 1;
        rb(i, 1, MAXN - 1) pw[i] = 1ll * A * pw[i - 1] % MOD;
        ipw[MAXN - 1] = inv(pw[MAXN - 1]);
        rl(i, MAXN - 2, 0) ipw[i] = 1ll * A * ipw[i + 1] % MOD;
    }
    void gen(string s) {
        S = s;
        rep(i, s.length()) {
            val[i + 1] = s[i];
        }
        rb(i, 1, s.length()) {
            val[i] = (1ll * A * val[i - 1] + val[i]) % MOD;
        }
    }
    int query(int l, int r) {
        if (r > S.length())
            return MOD;
        return (val[r] - 1ll * val[l - 1] * pw[r - l + 1] % MOD + MOD) % MOD;
    }
}A(500,998244353),B(500,998244353);
string s;
mp solve(int f){
    if(f>=s.length()) return II(0,0);
    if(f==s.length()-1) return II(0,1);
    if(s[f]=='('){
        auto rest=solve(f+2);
        rest.first++;
        return rest;
    }
    rb(i,f+1,s.length()-1){
        if(A.query(f+1,i+1)==B.query(s.length()-i,s.length()-f)){
            auto rest=solve(i+1);
            rest.first++;
            return rest;
        }
    }
    return II(0,s.length()-f);
}
void solve(){
    int n;
    cin>>n>>s;
    A.gen(s);
    reverse(ALL(s));
    B.gen(s);
    reverse(ALL(s));
    auto rest=solve(0);
    cout<<rest.first<<" "<<rest.second<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}