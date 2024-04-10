//
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl;

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

//kactl zzz
typedef complex<double> C;
typedef vector<double> vd;
#define vi vector<int>
void fft(vector<C>& a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vector<complex<long double>> R(2, 1);
	static vector<C> rt(2, 1);  // (^ 10% faster if double)
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n); rt.resize(n);
		auto x = polar(1.0L, acos(-1.0L) / k);
		rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
			auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
			C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
		}
}
vd conv(const vd& a, const vd& b) {
	if (a.empty() || b.empty()) return {};
	vd res(sz(a) + sz(b) - 1);
	int L = 32 - __builtin_clz(sz(res)), n = 1 << L;
	vector<C> in(n), out(n);
	copy(all(a), begin(in));
	rep(i,0,sz(b)) in[i].imag(b[i]);
	fft(in);
	for (C& x : in) x *= x;
	rep(i,0,n) out[i] = in[-i & (n - 1)] - conj(in[i]);
	fft(out);
	rep(i,0,sz(res)) res[i] = imag(out[i]) / (4 * n);
	return res;
}

string s,t;
int par[125005][6];
int num[125005];

int find(int i,int j){
	if (par[i][j]==j) return j;
	else return find(i,par[i][j]);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	rep(x,0,125005) rep(y,0,6) par[x][y]=y;
	
	cin>>s>>t;
	
	rep(a,0,6){
		rep(b,0,6){
			if (a==b) continue;
			
			vd v1,v2;
			
			rep(x,0,sz(s)){
				if (s[x]-'a'==a) v1.push_back(1);
				else v1.push_back(0);
			}
			rep(x,0,sz(t)){
				if (t[x]-'a'==b) v2.push_back(1);
				else v2.push_back(0);
			}
			reverse(all(v2));
			
			v1=conv(v1,v2);
			
			//cout<<a<<" "<<b<<": "<<endl;
			//for (auto &it:v1) cout<<it<<" "; cout<<endl;
			
			rep(x,0,sz(s)-sz(t)+1) if (v1[x+sz(t)-1]>1e-9){
				//cout<<x<<" "<<v1[x+sz(t)-1]<<endl;
				int aa=find(x,a),bb=find(x,b);
				
				if (aa!=bb){
					//cout<<x<<" "<<aa<<" "<<bb<<endl;
					num[x]++;
					par[x][aa]=bb;
				}
			}
		}
	}
	
	rep(x,0,sz(s)-sz(t)+1){
		cout<<num[x]<<" ";
	}

}