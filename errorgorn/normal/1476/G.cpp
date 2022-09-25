// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ii pair<int,int>
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

const int B=45;

int n,q;
int arr[100005];

int pos[100005];
int v1[100005];
int v2[100005];

int cnt[100005];
int occ[100005];
int Bocc[100005];

struct Q{
	int l,r,k;
	int t;
	int idx;
};
vector<Q> qu;
int ans[100005];

void add(int i,int j){
	occ[cnt[i]]--;
	Bocc[cnt[i]/B]--;
	cnt[i]+=j;
	occ[cnt[i]]++;
	Bocc[cnt[i]/B]++;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>q;
	rep(x,1,n+1) cin>>arr[x];
	
	occ[0]=Bocc[0]=1e9;
	
	int a,b,c;
	int T=0,IDX=0;
	rep(x,0,q){
		cin>>a;
		
		if (a==1){
			cin>>a>>b>>c;
			qu.pub({a,b,c,T,IDX++});
		}
		else{
			cin>>a>>b;
			pos[T]=a;
			v1[T]=arr[a];
			arr[a]=b;
			v2[T]=arr[a];
			T++;
		}
	}
	
	sort(all(qu),[](Q i,Q j){
		if (i.l/(B*B)!=j.l/(B*B)) return i.l<j.l;
		else if (i.r/(B*B)!=j.r/(B*B)){
			if ((i.l/(B*B))%2==0) return i.r<j.r;
			else return i.r>j.r;
		}
		else{
			if ((i.r/(B*B))%2==0) return i.t<j.t;
			else return i.t>j.t;
		}
	});
	
	int l=0,r=-1,t=T;
	for (auto it:qu){
		while (r<it.r) add(arr[++r],1);
		while (l<it.l) add(arr[l++],-1);
		while (it.l<l) add(arr[--l],1);
		while (it.r<r) add(arr[r--],-1);
		
		while (it.t<t){
			t--;
			if (l<=pos[t] && pos[t]<=r){
				add(v2[t],-1);
				add(v1[t],1);
			}
			arr[pos[t]]=v1[t];
		}
		while (t<it.t){
			if (l<=pos[t] && pos[t]<=r){
				add(v1[t],-1);
				add(v2[t],1);
			}
			arr[pos[t]]=v2[t];
			t++;
		}
		
		vector<ii> v;
		rep(x,0,100005/B+1) if (Bocc[x]){
			rep(y,x*B,(x+1)*B) if (y && occ[y]) v.pub({y,occ[y]});
		}
		
		int idx=-1;
		int num=0;
		int val=1e9;
		rep(x,0,sz(v)){
			while (idx+1<sz(v) && num<it.k){
				idx++;
				num+=v[idx].se;
			}
			if (num<it.k) break;
			val=min(val,v[idx].fi-v[x].fi);
			num-=v[x].se;
		}
		
		ans[it.idx]=(val==1e9?-1:val);
	}
	
	rep(x,0,IDX) cout<<ans[x]<<endl;
}