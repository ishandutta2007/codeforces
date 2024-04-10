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
const int MAXN=3e5+233;
int n,a[MAXN],b[MAXN],c[MAXN],depth[MAXN],depth_a[MAXN],cnt,son[MAXN],fa[MAXN];
vector<int> g[MAXN];
bool cmp(int A,int B){
	return a[A]<a[B];
}
void dfs(int now,int pre){
	fa[now]=pre;
	for(auto it:g[now]){
		depth[it]=depth[now]+1;
		dfs(it,now);
	}
}
void lab(int now,int pre){
	b[now]=++cnt;
	sort(ALL(g[now]),cmp);
	for(auto it:g[now]) if(it!=pre) lab(it,now);
}
void work(int now,int num){
	c[now]=num++;
	for(auto it:g[now]) if(!c[it]){
		work(it,num);
		break;
	}
}
void run(){
	priority_queue<mp,vector<mp>,greater<mp> > heap;
	rb(i,1,n){
		son[i]=g[i].size();
	}
	rb(i,1,n) if(son[i]==0) heap.push(II(b[i],i));
	int C=1;
	while(!heap.empty()){
		if(C>=a[1]-1) break;
		mp now=heap.top();
		heap.pop();
		c[now.SEC]=C;
		if(!(--son[fa[now.SEC]])){
			heap.push(II(b[fa[now.SEC]],fa[now.SEC]));
		}
		C++;
	}
	work(1,C);
	int stay=1;
	while(a[stay]!=c[stay]){
		bool ok=0;
		for(auto it:g[stay]){
			if(c[it]>=C){
				ok=1;
				swap(c[it],c[stay]);
				stay=it;
				break;
			}
		}
		if(!ok) break;
	}
	rb(i,1,n) if(!c[i]) c[i]=b[i];
}
int main(){
	scanf("%d",&n);
	rb(i,1,n) scanf("%d",&a[i]);
	rb(i,1,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].PB(v);
	}
	dfs(1,0);
	rb(i,1,n) depth_a[a[i]]=depth[i];
	lab(1,0);
	LL step=0;
	rb(i,1,a[1]-1){
		step+=depth_a[i];
	}
	run();
	rb(i,1,n) if(c[i]!=a[i]){
		puts("NO");
		return 0;
	}
	puts("YES");
	printf("%lld\n",step);
	rb(i,1,n) printf("%d ",b[i]);puts("");
	return 0;
}