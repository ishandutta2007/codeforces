#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef long long lint;
typedef pair<int,int> P;
//typedef tuple<int,int,int> TP;
typedef tuple<int,int,int,int> TP;
const int N=1e5+5,M=1e6+5;
const ll MOD=1e9+7,MOD2=1e9+6,mod=1e9+6;
ll mypow(ll a,ll b,ll mod)
{
    if(!b) return 1;
    ll t=mypow(a,b/2,mod);
    if(b&1) return t*t%mod*a%mod;
    return t*t%mod;
}
ll ipow(ll a,ll b)
{
    return mypow(a,b,MOD2);
}
vector<int> berlekamp_massey(vector<int> x){
	vector<int> ls, cur;
	int lf, ld;
	for(int i=0; i<x.size(); i++){
		lint t = 0;
		for(int j=0; j<cur.size(); j++){
			t = (t + 1ll * x[i-j-1] * cur[j]) % mod;
		}
		if((t - x[i]) % mod == 0) continue;
		if(cur.empty()){
			cur.resize(i+1);
			lf = i;
			ld = (t - x[i]) % mod;
			continue;
		}
		lint k = -(x[i] - t) * ipow(ld, mod - 2) % mod;
		vector<int> c(i-lf-1);
		c.push_back(k);
		for(auto &j : ls) c.push_back(-j * k % mod);
		if(c.size() < cur.size()) c.resize(cur.size());
		for(int j=0; j<cur.size(); j++){
			c[j] = (c[j] + cur[j]) % mod;
		}
		if(i-lf+(int)ls.size()>=(int)cur.size()){
			tie(ls, lf, ld) = make_tuple(cur, i, (t - x[i]) % mod);
		}
		cur = c;
	}
	for(auto &i : cur) i = (i % mod + mod) % mod;
	return cur;
}
int get_nth(vector<int> rec, vector<int> dp, lint n){
	int m = rec.size();
	vector<int> s(m), t(m);
	s[0] = 1;
	if(m != 1) t[1] = 1;
	else t[0] = rec[0];
	auto mul = [&rec](vector<int> v, vector<int> w){
		int m = v.size();
		vector<int> t(2 * m);
		for(int j=0; j<m; j++){
			for(int k=0; k<m; k++){
				t[j+k] += 1ll * v[j] * w[k] % mod;
				if(t[j+k] >= mod) t[j+k] -= mod;
			}
		}
		for(int j=2*m-1; j>=m; j--){
			for(int k=1; k<=m; k++){
	
    			t[j-k] += 1ll * t[j] * rec[k-1] % mod;
				if(t[j-k] >= mod) t[j-k] -= mod;
			}
		}
		t.resize(m);
		return t;
	};
	while(n){
		if(n & 1) s = mul(s, t);
		t = mul(t, t);
		n >>= 1;
	}
	lint ret = 0;
	for(int i=0; i<m; i++) ret += 1ll * s[i] * dp[i] % mod;
	return ret % mod;
}
int guess_nth_term(vector<int> x, lint n){
	if(n < x.size()) return x[n];
	//vector<int> v = berlekamp_massey(x);
    vector<int> v={3,MOD2-2,0,MOD2-1,1};
	if(v.empty()) return 0;
	return get_nth(v, x, n);
}
typedef vector<vector<ll>> matrix;
matrix operator * (const matrix &a, const matrix &b) {
    int n = a.size();
    matrix c(n, vector<ll>(n,0));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                (c[i][j] += a[i][k] * b[k][j]) %=MOD2;
            }
            c[i][j] %= MOD2;
        }
    }
    return c;
}
ll n,f1,f2,f3,c,ans=1;
matrix matpow(matrix a,ll b)
{
    if(!b) return {{1,0,0},{0,1,0},{0,0,1}};
    matrix t=matpow(a,b/2);
    if(b&1) return t*t*a;
    return t*t;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>f1>>f2>>f3>>c;
    matrix mat={{1,1,1},{1,0,0},{0,1,0}};
    mat=matpow(mat,n-3);
    matrix v1={{0},{0},{1}};
    matrix res=mat*v1;
    (ans*=mypow(f1,res[0][0],MOD))%=MOD;
    matrix v2={{0},{1},{0}};
    matrix res2=mat*v2;
    (ans*=mypow(f2,res2[0][0],MOD))%=MOD;
    matrix v3={{1},{0},{0}};
    matrix res3=mat*v3;
    (ans*=mypow(f3,res3[0][0],MOD))%=MOD;
    //cout<<res[0][0]<<" "<<res2[0][0]<<" "<<res3[0][0]<<" "<<ans<<endl;
    vector<int> v={0,0,0,0};
    for(int i=4;i<=10;i++) v.push_back(v[i-1]+v[i-2]+v[i-3]+2*i-6);
    (ans*=mypow(c,guess_nth_term(v,n),MOD))%=MOD;
    cout<<ans;
    return 0;
}