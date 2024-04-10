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
const int MAXN=4e5+233;
string s[MAXN];
int n,m,a[MAXN];
vector<vector<bool> > spe;
vector<vector<int> > mx,mn;
vector<vector<vector<mp> > > g;
vector<vector<vector<mp> > > rg;
vector<vector<int> > belong;
vector<vector<bool> > vis;
int cnt;
stack<mp> sta;
void buildedge(){
	g.resize(n+1);
	rb(i,1,n) g[i].resize(m);
	rg=g;
	rep(i,m){
		rl(j,n,1){
			if(s[j][i]=='#'){
				a[i]--;
				if(a[i]==0){
					spe[j][i]=1;
				}
			}
		}
	}
	rb(i,1,n) rep(j,m){
		if(s[i][j]!='#') continue;
		if(i!=1&&s[i-1][j]=='#') g[i][j].PB(II(i-1,j));
		for(int k=i;(k==i||(k<=n&&s[k][j]!='#'));++k){
			if(j!=0&&s[k][j-1]=='#') g[i][j].PB(II(k,j-1));
			if(j!=m-1&&s[k][j+1]=='#') g[i][j].PB(II(k,j+1));
			if(k!=n&&s[k+1][j]=='#') g[i][j].PB(II(k+1,j));
		}
	}
	rb(i,1,n) rep(j,m) for(auto it:g[i][j]) rg[it.FIR][it.SEC].PB(II(i,j));
}
void dfs1(int i,int j){
	vis[i][j]=1;
	for(auto it:g[i][j]){
		int nx,ny;
		nx=it.FIR;
		ny=it.SEC;
		if(!vis[nx][ny]){
			dfs1(nx,ny);
		}
	}
	sta.push(II(i,j));
}
void dfs2(int i,int j){
	belong[i][j]=cnt;
	for(auto it:rg[i][j]){
		int nx,ny;
		nx=it.FIR;
		ny=it.SEC;
		if(!belong[nx][ny]){
			dfs2(nx,ny);
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	rb(i,1,n) cin>>s[i];
	rep(i,m) scanf("%d",&a[i]);
	set<int> S;
	rep(j,m) if(a[j]) S.insert(j);
	if(*max_element(a,a+m)==0){
		puts("0");
		return 0;
	}
	spe.resize(n+1);
	rb(i,1,n) spe[i].resize(m);
	mx=vector<vector<int> > (n+1,vector<int> (m,-INF));
	mn=vector<vector<int> > (n+1,vector<int> (m,INF));
	buildedge();
	vis=vector<vector<bool> > (n+1,vector<bool> (m,0));
	belong=vector<vector<int> > (n+1,vector<int> (m,0));
	rb(i,1,n) rep(j,m) if(!vis[i][j]) dfs1(i,j);
	while(!sta.empty()){
		int i,j;
		i=sta.top().FIR;
		j=sta.top().SEC;
		sta.pop();
		if(!belong[i][j]){
			++cnt;
			dfs2(i,j);
		}
	}
	rb(i,1,n) rep(j,m){
		if(spe[i][j]){
			rb(k,i,n){
				if(belong[k][j]!=belong[i][j]){
					s[k][j]='.';
				}
			}
		}
	}
	g.clear();
	rg.clear();
	buildedge();
	priority_queue<pair<int,mp> > pq;
	rl(j,m-1,0)  {
		rl(i,n,1){
			if(spe[i][j]){
				mx[i][j]=j;
				pq.push(II(j,II(i,j)));
			}
		}
	}
	while(!pq.empty()){
		auto now=pq.top();
		pq.pop();
		int i,j;
		i=now.SEC.FIR;
		j=now.SEC.SEC;
		if(now.FIR!=mx[i][j]){
			continue;
		}
		for(auto it:rg[i][j]){
			int nx,nj;
			nx=it.FIR;
			nj=it.SEC;
			if(mx[nx][nj]<now.FIR){
				mx[nx][nj]=now.FIR;
				pq.push(II(mx[nx][nj],II(nx,nj)));
			}
		}
	}
	priority_queue<pair<int,mp>,vector<pair<int ,mp> > ,greater<pair<int,mp> > > heap;
	rl(j,m-1,0) {
		rl(i,n,1){
			if(spe[i][j]){
				mn[i][j]=j;
				heap.push(II(j,II(i,j)));
			}
		}
	}
	while(!heap.empty()){
		auto now=heap.top();
		heap.pop();
		int i,j;
		i=now.SEC.FIR;
		j=now.SEC.SEC;
		if(now.FIR!=mn[i][j]){
			continue;
		}
		for(auto it:rg[i][j]){
			int ni,nj;
			ni=it.FIR;
			nj=it.SEC;
			if(mn[ni][nj]>now.FIR){
				mn[ni][nj]=now.FIR;
				heap.push(II(now.FIR,II(ni,nj)));
			}
		}
	}
	vector<mp> seg;
	rep(j,m){
		rb(i,1,n){
			if(s[i][j]=='#'){
				seg.PB(II(mn[i][j],mx[i][j]));
				break;
			}
		}
	}
	sort(ALL(seg));
	int z=0;
	int ans=0;
	while(!S.empty()){
		int nd=*S.begin();
		int ZZ=-INF;
		while(z<seg.size()&&seg[z].FIR<=nd){
			++z;
			check_max(ZZ,seg[z-1].SEC);
		}
		++ans;
		while(!S.empty()&&*S.begin()<=ZZ) S.erase(S.begin());
	}
	printf("%d\n",ans);
	return 0;
}