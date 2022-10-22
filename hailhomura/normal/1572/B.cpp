#include <bits/stdc++.h>
 
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
 
using namespace std;
#define ll long long
#define ull unsigned long long
#define rep(i,n,N) for(int i=(n);i<=(N);++i)
#define For(i,n,N) for(int i=(n);i< (N);++i)
#define rap(i,n,N) for(int i=(n);i>=(N);--i)
#define rip(i,n,N,V) for(int i=(n);i<=(N);i+=V)
#define mp make_pair
#define pb push_back
#define pob pop_back
#define pf push_front
#define pof pop_front
//#define le left
//#define ri right
#define fi first
#define se second
#define ff fi.fi
#define fs fi.se
#define sf se.fi
#define ss se.se
#define lc (id<<1)
#define rc ((id<<1)|1)
#define db(x) cout << ">>>> " << #x << " -> " << (x) << endl
#define out(x,y) cout << ">> " << (x) << " " << (y) << endl
#define ou3(x,y,z) cout << ">> " << (x) << " " << (y) << " " << (z) << endl
#define mems(x,y) memset(&x,y,sizeof x)
#define memsv(x,y) memset(&x[0], y, sizeof(x[0]) * x.size())
#define popcount __builtin_popcountll
#define all(x) x.begin(),x.end()
#define PQ(T) priority_queue<T>
#define PQr(T) priority_queue<T, vector<T>, greater<T>>
#define vi vector<int>
#define vii vector<pii>
#define vl vector<ll>
#define vll vector<pll>
#define ari(x) array<int,x>
#define arll(x) array<ll,x>
#define ard(x) array<double,x>
#define pii pair<int,int> 
#define pll pair<ll,ll>
#define plll pair<ll,pll>
#define pllll pair<pll,pll>
#define piii pair<int,pii>
#define piiii pair<pii,pii>
#define psi pair<string,int>
#define endl '\n'
const int MAX = 1e6+5;
const ll MOD = 1000000007;
const ll MOD2 = 2010405347;
const ll INF = 2e18;
const int dr[]={1,0,-1,0,1,1,-1,-1,0};
const int dc[]={0,1,0,-1,1,-1,1,-1,0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 315;
inline ll pw(ll x,ll y,ll md=MOD){ll ret=1;x%=md;while(y){if(y&1)ret=ret*x%md;x=x*x%md,y>>=1;}return ret;}
inline void add(int &a,int b,int md=MOD){a=a+b>=md?a+b-md:a+b;}
 
ll tc,n,x[MAX],y[MAX],cnt,hit;
vector<int> ans;

void solve(int le,int ri){
	cnt = x[le]+x[le+1];
	int tmp = 0;
	rep(i,le,ri-2){
		cnt+= x[i+2];
		if(cnt%2==0 && cnt){
			tmp = 0;
			rep(k,0,2)tmp+= x[i+k];
			if(tmp==2){
				ans.pb(i);
				rep(k,0,2)x[i+k] = 0;
				rap(j,i,le){
					tmp = 0;
					rep(k,0,2)tmp+= x[j+k];
					if(tmp==2){
						ans.pb(j);
						rep(k,0,2)x[j+k] = 0;
					}
				}
				rep(j,i,ri-2){
					tmp = 0;
					rep(k,0,2)tmp+= x[j+k];
					if(tmp==2){
						ans.pb(j);
						rep(k,0,2)x[j+k] = 0;
					}
				}
				return;
			}
		}
	}
	return;
}

int main(){
//	cout<<fixed<<setprecision(10);
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>tc;
	rep(ntc,1,tc){
		cin>>n;
		cnt = 0;
		rep(i,1,n){
			cin>>x[i];
			y[i] = x[i];
			cnt+= x[i];
		}
		if((cnt&1) || cnt==n){
			cout<<"NO\n";
			continue;
		}
		ans.clear();
		hit = cnt;
		cnt = 0;
		bool st = 0;
		rep(i,1,n)cnt+=x[i], st|= (cnt%2==0) && (i&1);
		cnt = 0;
		
		rep(i,1,n){
			cnt+= x[i];
			if(cnt && (cnt%2==0) && (i&1)){
				hit-= cnt;
				rep(j,1,i-2)if(x[j]){
					cnt = 0;
					rep(k,0,2)cnt+= x[j+k];
					if(cnt==1){
						rep(k,0,2)x[j+k] = 1;
						ans.pb(j);
					}
				}
				solve(1,i);
				break;
			}
		}
		cnt = 0;
		rap(i,n,1){
			cnt+= x[i];
			if(cnt==hit && (i%2==n%2)){
				rep(j,i,n-2)if(x[j]){
					cnt = 0;
					rep(k,0,2)cnt+= x[j+k];
					if(cnt==1){
						rep(k,0,2)x[j+k] = 1;
						ans.pb(j);
					}
				}
				solve(i,n);
				break;
			}
		}
		cnt = 0;
		rep(i,1,n){
			cnt+= x[i];
		}
		if(cnt){
			cout<<"NO\n";
		}
		else {
			cout<<"YES\n";
			assert(ans.size()<=n);
			cout<<ans.size()<<endl;
			for(int i:ans)cout<<i<<" "; cout<<endl;
		}
	}
	return 0;
}