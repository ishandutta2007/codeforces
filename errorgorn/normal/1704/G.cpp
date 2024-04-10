//
//
//
//

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int INF=1e18;

const ll mod = (119 << 23) + 1, root = 62; // = 998244353
// For p < 2^30 there is also e.g. 5 << 25, 7 << 26, 479 << 21
// and 483 << 21 (same root). The last two are > 10^9.

ll qexp(ll b,ll p,int m){
    ll res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}


typedef vector<ll> vl;
void ntt(vl &a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vl rt(2, 1);
	for (static int k = 2, s = 2; k < n; k *= 2, s++) {
		rt.resize(n);
		ll z[] = {1, qexp(root, mod >> s, mod)};
		rep(i,k,2*k) rt[i] = rt[i / 2] * z[i & 1] % mod;
	}
	vector<int> rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			ll z = rt[j + k] * a[i + j + k] % mod, &ai = a[i + j];
			a[i + j + k] = ai - z + (z > ai ? mod : 0);
			ai += (ai + z >= mod ? z - mod : z);
		}
}
vl conv(const vl &a, const vl &b) {
	if (a.empty() || b.empty()) return {};
	int s = sz(a) + sz(b) - 1, B = 32 - __builtin_clz(s), n = 1 << B;
	int inv = qexp(n, mod - 2, mod);
	vl L(a), R(b), out(n);
	L.resize(n), R.resize(n);
	ntt(L), ntt(R);
	rep(i,0,n) out[-i & (n - 1)] = (ll)L[i] * R[i] % mod * inv % mod;
	ntt(out);
	return {out.begin(), out.begin() + s};
}

int n,m;
int arr[200005],arr2[200005];
int brr[200005],brr2[200005];
bool bad[200005];
bool ans[200005];

int cnt_odd(int i){
	return (i+1)*(i+1)/4;
}

int cnt_even(int i){
	//0+2+...+i
	return i*(i+2)/4;
}

ii get(int x,int d){
	//(-0,1)
	//(1,-1)
	//(-2,1)
	//(3,-1)
	//for x=1, we have (0,1) and (1,-1)
	
	int cntp=x/2+1,cntn=(x+1)/2;
	if (d < -cntn || cntp < d) return {INF,-INF};
	
	ii res;
	
	//im too lazy to do math so i will just binary search
	
	//minimum value
	{
	int lo=0,hi=200005,mi;
	while (hi-lo>1){
		mi=hi+lo>>1;
		int l=mi+(d>0?d:0),r=mi+(d<0?-d:0);
		
		if (-1+2*r<cntp*2-2*l) lo=mi;
		else hi=mi;
	}
	
	int l=lo+(d>0?d:0),r=lo+(d<0?-d:0);
	res.fi=-cnt_even(cntp*2-2)+cnt_even(cntp*2-2-2*l)+cnt_odd(-1+2*r);
	}
	
	//maximum value
	{
	int lo=0,hi=200005,mi;
	while (hi-lo>1){
		mi=hi+lo>>1;
		int l=mi+(d>0?d:0),r=mi+(d<0?-d:0);
		
		if (-2+2*l<cntn*2+1-2*r) lo=mi;
		else hi=mi;
	}
	
	int l=lo+(d>0?d:0),r=lo+(d<0?-d:0);
	res.se=cnt_odd(cntn*2-1)-cnt_odd(cntn*2-1-r*2)-cnt_even(2*(l-1));
	}
	
	return res;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,1,n+1) cin>>arr[x];
		cin>>m;
		rep(x,1,m+1) cin>>brr[x];
		
		rep(x,1,n+1) arr2[x]=arr[x];
		rep(x,1,m+1) brr2[x]=brr[x];
		
		rep(x,1,n+1) bad[x]=false;
		
		rep(x,n+1,2) arr[x]+=2*arr[x-1]+arr[x-2];
		rep(x,m+1,2) brr[x]+=2*brr[x-1]+brr[x-2];
		
		// rep(x,1,n+1) cout<<arr[x]<<" "; cout<<endl;
		// rep(x,1,m+1) cout<<brr[x]<<" "; cout<<endl;
		
		if (m>=3){
			map<int,int> id;
			rep(x,3,m+1) id[brr[x]]=rng()%mod;
			
			rep(par,0,2){
				map<int,int> id2;
				rep(x,1,n+1){
					if ((arr[x]&1)!=par) id2[arr[x]+1]=rng()%mod;
					else id2[arr[x]]=rng()%mod;
				}
				
				vector<int> v1;
				vector<int> v2;
								
				rep(x,m+1,3){
					if ((brr[x]&1)==par) v1.pub(id[brr[x]]);
					else v1.pub(0);
				}
				rep(x,1,n+1){
					if ((arr[x]&1)!=par) v2.pub(id2[arr[x]+1]);
					else v2.pub(id2[arr[x]]);
				}
				
				int exp=0,die=0;
				rep(x,3,m+1) if ((brr[x]&1)==par){
					if (!id2.count(brr[x])) die=1;
					else exp=(exp+id[brr[x]]*id2[brr[x]])%mod;
				}
				
				vector<int> v=conv(v1,v2);
				
				rep(x,1,n-m+2) if (v[x+m-2]!=exp || die) bad[x]=true;
			}
		}
		
		bool done=false;
		
		if (m==1){
			int mn=0,mx=0;
			rep(x,1,n+1){
				if (x%2==1) mx+=x;
				else mn-=x;
				
				int v1=brr2[1]-arr2[x];
				
				if (mn<=v1 && v1<=mx){
					vector<int> ans;
					rep(y,x+1,1){
						if (y%2==1) mx-=y;
						else mn+=y;
						
						if (mx<v1){
							ans.pub(x-y+1);
							v1-=y;
						}
						if (v1<mn){
							ans.pub(x-y+1);
							v1+=y;
						}
					}
					
					done=true;
					cout<<sz(ans)<<endl;
					for (auto it:ans) cout<<it<<" "; cout<<endl;
					break;
				}
			}
		}
		else{
			rep(x,1,n-m+2) if (!bad[x] && !done){
				int v1=brr2[1]-arr2[x],v2=brr2[2]-arr2[x+1]+v1;
				
				ii temp=get(x,v2);
				if (temp.fi<=v1 && v1<=temp.se){
					int cntp=x/2+1,cntn=(x+1)/2;
					int l=(v2>0?v2:0),r=(v2<0?-v2:0);
					
					while (true){
						int mn=-cnt_even(cntp*2-2)+cnt_even(cntp*2-2-2*l)+cnt_odd(-1+2*r);
						int mx=cnt_odd(cntn*2-1)-cnt_odd(cntn*2-1-r*2)-cnt_even(2*(l-1));
						
						if (mn<=v1 && v1<=mx && (v1&1)==(mn&1)){
							vector<int> vl,vr;
							rep(x,cntp,0) vl.pub(-2*x);
							rep(x,0,cntn) vr.pub(2*x+1);
							
							// cout<<x<<" "<<v1<<" "<<v2<<" "<<mn<<" "<<mx<<" "<<l<<" "<<r<<endl;
							// for (auto it:vl) cout<<it<<" "; cout<<endl;
							// for (auto it:vr) cout<<it<<" "; cout<<endl;
							
							int steps=(v1-mn)/2;
							set<int> s;
							rep(x,l,0){
								int temp=min(sz(vl)-l,steps);
								s.insert(vl[x]+2*temp);
								steps-=temp;
							}
							rep(x,r,0){
								int temp=min(sz(vr)-r,steps);
								s.insert(vr[x]+2*temp);
								steps-=temp;
							}
							
							//for (auto it:s) cout<<it<<" "; cout<<endl;
							
							vector<int> ans;
							for (auto it:s) ans.pub(x+1-abs(it));
							rep(y,3,m+1) if (brr[y]!=arr[x+y-1]) ans.pub(x+y-1);
							
							// for (auto it:ans){
								// rep(y,it,n+1){
									// if ((y-it)%2==0) arr2[y]+=y-it+1;
									// else arr2[y]-=y-it+1;
								// }
							// }
							// rep(x,1,n+1) cout<<arr2[x]<<" "; cout<<endl;
							
							done=true;
							cout<<sz(ans)<<endl;
							for (auto it:ans) cout<<it<<" "; cout<<endl;
							
							break;
						}
						
						l++,r++;
					}
				}
			}
		}
		
		if (!done) cout<<"-1"<<endl;
	}
}