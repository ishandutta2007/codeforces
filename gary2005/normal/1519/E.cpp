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
const int MAXN=2e5+233;
int n;
int a[MAXN],b[MAXN],c[MAXN],d[MAXN];
LL gcd(LL A,LL B){
	if(B==0) return A;
	return gcd(B,A%B);
}
pair<LL,LL> Get(LL A,LL B){
	LL g=gcd(A,B);
	return {A/g,B/g};
}
map<pair<LL,LL> ,vector<int> > have;
map<pair<LL,LL> ,int > id;
vector<mp> g[MAXN<<1];
vector<pair<LL,LL> > g_[MAXN];
vector<int> rest[MAXN<<1];
bool vis[MAXN<<1],p[MAXN<<1];
int depth[MAXN<<1];
void dfs(int now,int pre){
	vis[now]=true;
	for(auto it:g[now]){
		if(it.FIR==pre) {pre=-1;continue;}
		if(vis[it.FIR]){
			if(depth[it.FIR]<depth[now]){
				p[it.FIR]^=1;
				rest[it.FIR].PB(it.SEC);
			}
		}
		else{
			depth[it.FIR]=depth[now]+1;
			dfs(it.FIR,now);
			if(p[it.FIR]){
				p[it.FIR]=0;
				rest[it.FIR].PB(it.SEC);
			}
			else{
				p[now]^=1;
				rest[now].PB(it.SEC);
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	rb(i,1,n){
		scanf("%d%d%d%d",&a[i],&b[i],&c[i],&d[i]);
		have[Get(1ll*c[i]*b[i],1ll*(a[i]+b[i])*d[i])].PB(i);
		have[Get(1ll*(c[i]+d[i])*b[i],1ll*a[i]*d[i])].PB(i);
	}
	int cnt=0;
	for(auto ite=have.begin();ite!=have.end();ite++){
		id[ite->FIR]=1;
		for(auto it:ite->SEC) g_[it].PB(ite->FIR);
	}
	for(auto ite=id.begin();ite!=id.end();ite++) ite->SEC=++cnt;
	rb(i,1,n){
		assert(g_[i].size()==2);
		g[id[g_[i][0]]].PB(II(id[g_[i][1]],i));
		g[id[g_[i][1]]].PB(II(id[g_[i][0]],i));
	}
	rb(i,1,cnt) if(!vis[i]) dfs(i,0);
	vector<mp> ans;
	rb(i,1,cnt)
		for(int j=0;j+1<rest[i].size();j+=2){
			ans.PB(II(rest[i][j],rest[i][j+1]));
		}
	printf("%d\n",(int)ans.size());
	for(auto it:ans){
		printf("%d %d\n",it.FIR,it.SEC);
	}
	return 0;
}