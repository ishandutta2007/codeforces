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

const int MOD=998244353;

vector<int> fac[200005];
bool pk[200005];

int n;
int arr[200005];

vector<int> al[200005];
int parent[200005][20];
int level[200005];
int in[200005],out[200005];
int _TIME=0;

vector<int> pos[200005];

void dfs(int i,int p){
	in[i]=++_TIME;
	for (auto it:fac[arr[i]]) pos[it].pub(i);
	
    int curr;
    for (auto it=al[i].begin();it!=al[i].end();it++){
        if (*it==p) continue;
        level[*it]=level[i]+1;
        parent[*it][0]=i;
        curr=i;
        for (int x=0;parent[curr][x]!=-1;x++){
            curr=parent[*it][x+1]=parent[curr][x];
        }
        dfs(*it,i);
    }
    
    out[i]=_TIME;
}

int mov(int i,int j){
    for (int x=0;x<20;x++){
        if (j&1){
            i=parent[i][x];
        }
        j>>=1;
    }
    return i;
}

int lca(int i,int j){
    if (level[i]<level[j]) swap(i,j);
    i=mov(i,level[i]-level[j]);
    if (i==j) return i;
    for (int x=19;x>=0;x--){
        if (parent[i][x]!=parent[j][x]){
            i=parent[i][x];
            j=parent[j][x];
        }
    }
    return parent[i][0];
}

int dist(int i,int j){
    return level[i]+level[j]-2*level[lca(i,j)];
}

vector<ii> al2[200005];
int cnt[200005];

int SS;
int ans=0;

int dfs2(int i){
	int ss=cnt[i];
	
	for (auto [it,dist]:al2[i]){
		int temp=dfs2(it);
		ss+=temp;
		
		int l=temp,r=SS-temp;
		//cout<<l<<" "<<r<<endl;
		
		int num=l*r*((r-1)+(l-1))/2%MOD;
		ans=(ans+num*dist)%MOD;
	}
	
	return ss;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	rep(x,1,200005){
		if (2<=x && fac[x].empty()){
			pk[x]=true;
			for (int y=x;y<200005;y+=x) fac[y].pub(x);
		}
	}
	
	cin>>n;
	rep(x,1,n+1) cin>>arr[x];
	
	int a,b;
	rep(x,1,n){
		cin>>a>>b;
		al[a].pub(b);
		al[b].pub(a);
	}
	
	memset(parent,-1,sizeof(parent));
	dfs(1,-1);
	
	rep(x,1,200005) if (pk[x] && !pos[x].empty()){
		//for (auto it:pos[x]) cout<<it<<" "; cout<<endl;
		for (auto it:pos[x]) cnt[it]=1;
		
		int ss=sz(pos[x]);
		rep(y,0,ss-1) pos[x].pub(lca(pos[x][y],pos[x][y+1]));
		
		sort(all(pos[x]),[](int i,int j){
			return in[i]<in[j];
		});
		
		pos[x].erase(unique(all(pos[x])),pos[x].end());
		
		//for (auto it:pos[x]) cout<<it<<" "; cout<<endl<<endl;
		
		for (auto it:pos[x]) al2[it].clear();
		vector<int> stk;
		for (auto it:pos[x]){
			if (!stk.empty()){
				while (out[stk.back()]<out[it]) stk.pob();
				al2[stk.back()].pub({it,dist(stk.back(),it)});
			}
			stk.pub(it);
		}
		
		SS=ss;
		dfs2(stk[0]);
		
		//cout<<x<<" "<<ans<<" "<<SS<<endl;
		
		for (auto it:pos[x]) cnt[it]=0;
	}
	
	cout<<ans<<endl;
}