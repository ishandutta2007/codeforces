/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=3003;
int n,m;
vector<int> g[MAXN];
int deg[MAXN];
vector<int> ans;
void print(){
	cout<<ans.size()<<endl;
	for(auto it:ans) cout<<it<<' ';
	cout<<endl;
	exit(0);
}
map<mp,int> used;
mp p(mp A){
	if(A.FIR>A.SEC) return II(A.SEC,A.FIR);
	return A;
}
void go(int now){
	for(auto it:g[now]){
		if(used[p(II(now,it))]){
			continue;
		}
		used[p(II(now,it))]=1;
		go(it);
	}
	ans.PB(now);
}
map<mp,int> bad;
int low[MAXN];
bool vis[MAXN];
int depth[MAXN];
void dfs(int now,int pre,int deep=0){
	low[now]=depth[now]=deep;
	vis[now]=1;
	for(auto it:g[now]){
		if(it!=pre){
			if(vis[it]){
				check_min(low[now],depth[it]);
			}
			else{
				dfs(it,now,deep+1);
				check_min(low[now],low[it]);
			}
		}
	}
	if(low[now]==depth[now]){
		bad[II(now,pre)]=bad[II(pre,now)]=1;
	}
}
bool chk(){
	int cnt_=0;
	bool ok=0;
	bool pre=0;
	rep(i,ans.size()){
		if(!i) continue;
		if(ans[i]==-1){
			ok=1;
			pre=1;
			continue;
		}
		if(ok){
			if(pre);
			else{
				cnt_++;
			}
			pre^=1;
		}
		else{
			cnt_++;
		}
	}
	return cnt_==m;
}
int main(){
	scanf("%d%d",&n,&m);
	int cnt=0;
	rb(i,1,m){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].PB(v);
		g[v].PB(u);
		deg[u]++;
		deg[v]++;
	}
	dfs(1,0);
	rb(i,1,n){
		cnt+=deg[i]&1;
	}
	rb(i,1,n){
		if(deg[i]==n-1&&m==n-1){
			ans.PB(i);
			ans.PB(-1);
			for(auto it:g[i]){
				ans.PB(it);
				ans.PB(i);
			}
			print();
		}
	}
	if(cnt<=2){
		int z=1;
		rb(i,1,n) if(deg[i]&1) z=i;
		go(z);
		reverse(ALL(ans));
		print();
	}
	rb(i,1,n)
		rb(j,1,n){
			if(i!=j&&(deg[i]&1)){
				vector<int> need;
				for(auto it:g[j]){
					if(it==i) continue;
					if((deg[it]&1)&&(!bad[II(it,j)]||deg[it]==1)){
						need.PB(it);
					}
				}
				int rest=cnt-1-(deg[j]&1)-need.size();
				if(rest==0&&(g[j].size()-need.size())%2==1){
					for(auto it:need) used[p(II(j,it))]=1;
					go(i);
					reverse(ALL(ans));
					ans.PB(-1);
					for(auto it:need){
						ans.PB(it);
						ans.PB(j);
					}
					if(chk())
					print();
					ans.clear();
					used.clear();
				}
			}
		}
	rb(j,1,n){
		vector<int> need;
		for(auto it:g[j]){
			if(deg[it]&1&&(!bad[II(it,j)]||deg[it]==1)){
				need.PB(it);
			}
		}
		int rest=cnt-(deg[j]&1)-need.size();
		if(rest==0&&(g[j].size()-need.size())%2==0){
			for(auto it:need) used[p(II(j,it))]=1;
			go(j);
			reverse(ALL(ans));
			ans.PB(-1);
			for(auto it:need){
				ans.PB(it);
				ans.PB(j);
			}
			if(chk())
			print();
			ans.clear();
		}
	}
	printf("0\n");
	return 0;
}