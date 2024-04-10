//
//
//
//
 
#include <bits/stdc++.h>
using namespace std;
 
#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii tuple<int,int,int>
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
 
const int MOD=998244353;
const int P=177013;
 
int hv[200005];
 
int n,m;
 
struct dat{
	vector<int> r,c;
	int h=0;
};
 
vector<vector<int> > v;
vector<int> ord1[200005];
vector<int> ord2[200005];
 
bool has1[200005];
bool has2[200005];
 
dat get_equiv(vector<int> R,vector<int> C,int X,int Y){
	for (auto it:R) has1[it]=false;
	for (auto it:C) has2[it]=false;
	has1[X]=true;
	has2[Y]=true;
	
	vector<int> r={X},c={Y};
	int idx1=0,idx2=0;
	bool flag=true;
	
	while (idx1<sz(r) || idx2<sz(c)){
		if (flag){
			while (idx1<sz(r)){
				int x=r[idx1++];
				for (auto y:ord1[x]) if (!has2[y]){
					has2[y]=true;
					c.pub(y);
				}
			}
		}
		else{
			while (idx2<sz(c)){
				int y=c[idx2++];
				for (auto x:ord2[y]) if (!has1[x]){
					has1[x]=true;
					r.pub(x);
				}
			}
		}
		
		flag^=true;
	}
	
	int h=0,curr=1;
	for (auto x:r) for (auto y:c){
		h=(h+curr*hv[v[x][y]])%MOD;
		curr=(curr*P)%MOD;
	}
	h=(h+curr*sz(r)+curr*P%MOD*sz(c))%MOD;
	
	return {r,c,h};
}
 
dat solve(){
	rep(x,0,200005){
		ord1[x].clear();
		ord2[x].clear();
	}
	
	rep(x,0,n) rep(y,0,m) if (v[x][y]){
		ord1[x].pub(y);
		ord2[y].pub(x);
	}
	
	rep(x,0,n) sort(all(ord1[x]),[x](int i,int j){
		return v[x][i]>v[x][j];
	});
	rep(y,0,m) sort(all(ord2[y]),[y](int i,int j){
		return v[i][y]>v[j][y];
	});
	
	vector<bool> vis1(n,false);
	vector<bool> vis2(m,false);
	
	// rep(x,0,n){
		// rep(y,0,m) cout<<v[x][y]<<" "; cout<<endl;
	// }
	
	vector<int> R,C;
	int H=0;
	
	rep(x,0,n) rep(y,0,m) if (v[x][y] && !vis1[x]){
		vector<ii> stk;
		vis1[x]=true; stk.pub({0,x});
		vis2[y]=true; stk.pub({1,y});
		
		vector<int> r,c;
		while (!stk.empty()){
			int a,b; tie(a,b)=stk.back(); stk.pob();
			
			if (a==0){
				r.pub(b);
				rep(y,0,m) if (v[b][y] && !vis2[y]){
					vis2[y]=true; stk.pub({1,y});
				}
			}
			else{
				c.pub(b);
				rep(x,0,n) if (v[x][b] && !vis1[x]){
					vis1[x]=true; stk.pub({0,x});
				}
			}
		}
		
		int mx=0;
		for (auto it1:r) for (auto it2:c) mx=max(mx,v[it1][it2]);
		
		vector<dat> res;
		for (auto it1:r) for (auto it2:c) if (v[it1][it2]==mx){
			res.pub(get_equiv(r,c,it1,it2));
		}
		
		for (auto &it:res) if (res[0].h<it.h) swap(res[0],it);
		
		R.insert(R.end(),all(res[0].r));
		C.insert(C.end(),all(res[0].c));
		H=(H+res[0].h)%MOD;
	}
	
	rep(x,0,n) if (!vis1[x]) R.pub(x);
	rep(y,0,m) if (!vis2[y]) C.pub(y);
	
	return {R,C,H};
}
 
vector<ii> generate_moves(vector<int> v1,vector<int> v2){
	vector<int> v(sz(v1));
	rep(x,0,sz(v1)) v[v1[x]]=v2[x];
	
	vector<int> pos(sz(v));
	rep(x,0,sz(v)) pos[v[x]]=x;
	
	vector<ii> res;
	rep(x,0,sz(pos)) if (pos[x]!=x){
		res.pub({x,pos[x]});
		
		int temp=v[x];
		swap(v[x],v[pos[x]]);
		swap(pos[temp],pos[x]);
	}
	
	return res;
}
 
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	rep(x,0,200005) hv[x]=rng()%MOD;
	
	cin>>n>>m;
	
	vector<vector<int> > a(n,vector<int>(m));
	vector<vector<int> > b(n,vector<int>(m));
	rep(x,0,n) rep(y,0,m) cin>>a[x][y];
	rep(x,0,n) rep(y,0,m) cin>>b[x][y];
	
	v=a; dat res1=solve();
	v=b; dat res2=solve();
	
	if (res1.h!=res2.h){
		cout<<"-1"<<endl;
		return 0;
	}
	else{
		vector<ii> v;
		vector<iii> ans;
		
		v=generate_moves(res1.r,res2.r);
		for (auto [a,b]:v) ans.pub({1,a,b});
		
		v=generate_moves(res1.c,res2.c);
		for (auto [a,b]:v) ans.pub({2,a,b});
		
		cout<<sz(ans)<<endl;
		for (auto [a,b,c]:ans) cout<<a<<" "<<b+1<<" "<<c+1<<endl;
	}
}