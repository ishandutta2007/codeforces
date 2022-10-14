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
const int MAXN=10000+233;
int m,n=10000;
int fa[MAXN],siz[MAXN],deg[MAXN];
vector<mp> g[MAXN];
int root(int x){
	return fa[x]=(fa[x]==x? x:root(fa[x]));
}
void noans(){
	puts("-1");
	exit(0);
}
vector<int> ret;
int h[MAXN];
bool era[MAXN];
void dfs(int now){
	for(int & i=h[now];i<g[now].size();){
		if(era[g[now][i].SEC]) {i++;continue;};
		mp tmp=g[now][i];
		era[tmp.SEC]=1;
		i++;
		dfs(tmp.FIR);
		ret.PB(tmp.SEC);
	}
}
vector<int> euler(int rt){
	int fk=0;
	memset(era,0,sizeof(era));
	memset(h,0,sizeof(h));
	vector<int> st;
	rb(i,1,n){
		if(root(i)==root(rt)&&(deg[i]&1)){
			fk++;
			st.PB(i);
		}
	}
	if(fk>2) noans();
	ret.clear();
	st.PB(rt);
	dfs(st[0]);
	reverse(ALL(ret));
	return ret;
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&m);
	rb(i,1,n) fa[i]=i;
	rb(i,1,m){
		int u,v;
		scanf("%d%d",&u,&v);
		deg[u]++;
		deg[v]++;
		g[u].PB(II(v,i));
		g[v].PB(II(u,i));
		fa[root(u)]=root(v);
	}
	if(m<2){
		noans();
	}
	rb(i,1,n) siz[root(i)]++;
	int cnt_cc=0;
	rb(i,1,n) if(i==root(i)&&siz[i]>=2) cnt_cc++;
	if(cnt_cc>2) noans();
	if(cnt_cc==2){
		vector<int> rt;
		rb(i,1,n) if(i==root(i)&&siz[i]>=2) rt.PB(i);
		vector<int> ans1,ans2;
		ans1=euler(rt[0]);
		ans2=euler(rt[1]);
		cout<<ans1.size()<<endl;
		for(auto it:ans1) printf("%d\n",it);
		cout<<ans2.size()<<endl;
		for(auto it:ans2) printf("%d\n",it);
	}
	else{
		vector<int> od;
		rb(i,1,n){
			if(deg[i]&1) od.PB(i);
		}
		if(od.size()>4) noans();
		if(od.size()==4){
			g[od[0]].PB(II(od[1],m+1));
			g[od[1]].PB(II(od[0],m+1));
			deg[od[0]]++;
			deg[od[1]]++;
			vector<int> ans=euler(od[0]);
			vector<int> ans1,ans2;
			bool flag=0;
			for(auto it:ans){
				if(it==m+1){
					flag=1;
					continue;
				}
				if(!flag) ans1.PB(it);
				else ans2.PB(it);
			}
			cout<<ans1.size()<<endl;
			for(auto it:ans1) printf("%d\n",it);
			cout<<ans2.size()<<endl;
			for(auto it:ans2) printf("%d\n",it);
		}
		else{
			rb(i,1,n) if(siz[i]>=2) od.PB(i);
			vector<int> ans=euler(od[0]);
			vector<int> ans1,ans2;
			ans1.PB(ans.back());
			ans.POB();
			ans2=ans;
			cout<<ans1.size()<<endl;
			for(auto it:ans1) printf("%d\n",it);
			cout<<ans2.size()<<endl;
			for(auto it:ans2) printf("%d\n",it);
		}
	}
	return 0;
}