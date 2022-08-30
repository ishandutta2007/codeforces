//Let's join Kaede Takagaki Fan Club !!
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define mp make_pair
#define pb push_back
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)

const ll mod = 1000000007;
ll F[50], R[50];
ll modpow(ll a, ll n){
    ll ret = 1;
    while(n){
        if(n & 1) ret = ret * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ret;
}
void init(){
    F[0] = 1;
    for(int i=1;i<50;i++) F[i] = F[i-1] * i % mod;
    rep(i, 50) R[i] = modpow(F[i], mod-2);
}
ll C(int a, int b){
    if(b < 0 || a < b) return 0LL;
    return F[a] * R[b] % mod * R[a-b] % mod;
}

int n, go[42], vis[42];
vector<int>cmp;
ll coef[42][42][42];
ll solve(int old, int pre, vector<P>part);
ll make(int old, int pre, vector<P>cur, vector<P>&part, ll mm, int sz){
    int id = cur.size();
    ll sum = 0;
	if(id == part.size()){
		if(sz){
		    return solve(old+pre, sz, cur) * mm % mod;
		}
		else return 0LL;
	}
	for(int x=part[id].fi;x>=0;x--){
		ll mm2 = mm * C(part[id].fi, x) % mod;
		cur.pb(mp(x, part[id].sc));
		sum += make(old, pre, cur, part, mm2, sz+(part[id].fi-x)*part[id].sc);
		cur.pop_back();
		mm = mm * coef[old][pre][part[id].sc] % mod;
	}
	return sum%mod;
}
unordered_map<ll, ll>M[42][42];
ll solve(int old, int pre, vector<P>part){
	for(auto at:part) if(at.fi) goto nxt;
	return 1LL; nxt:;
	ll enc = 0;
	for(auto at:part) enc = enc * 41LL + (at.fi + 1);
	if(M[old][pre].find(enc) != M[old][pre].end()) return M[old][pre][enc];
	return M[old][pre][enc] = make(old, pre, vector<P>(), part, 1, 0);
}
int main(){
    init();
	cin >> n;
	repn(i, n) cin >> go[i];
	repn(i, n){
		if(vis[i]) continue;
		int cur = i, cnt = 0;
		while(!vis[cur]){
			vis[cur] = 1;
			cnt ++;
			cur = go[cur];
		}
		cmp.pb(cnt);
	}
	sort(cmp.begin(), cmp.end());
	vector<int>mm(n+1, 0);
	rep(i, cmp.size()) mm[cmp[i]] ++;
	vector<P>m;
	rep(i, n+1) if(mm[i]) m.pb(mp(mm[i], i));
	rep(x, n+1){
		repn(y, n-x){
			repn(z, n-x-y){
				ll sum = 0;
				ll sum2 = 0;
				rep(i, x+1) {
					sum += C(x, i) * C(y, 0) % mod * F[i+0] % mod * F[n-1-i-0] % mod;
				}
				rep(i, x+1) rep(j, y+1){
				    sum2 += C(x, i) * C(y, j) % mod * F[i+j] % mod * F[n-1-i-j] % mod;
				}
				sum %= mod;
				sum2 %= mod;
				coef[x][y][z] = modpow(sum2, z) - modpow(sum, z);
				if(coef[x][y][z] < 0) coef[x][y][z] += mod;
			}
		}
	}
	repn(x, n) coef[0][0][x] = modpow(F[n-1], x);
	cout << solve(0, 0, m) << endl;
}