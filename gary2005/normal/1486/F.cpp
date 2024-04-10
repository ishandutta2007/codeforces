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
int n,m;
vector<int> g[MAXN];
int fa[MAXN][19],depth[MAXN];
void getsiz(int now,int pre=0){
	fa[now][0]=pre;
	rb(i,1,18)
		fa[now][i]=fa[fa[now][i-1]][i-1];
	for(auto it:g[now]){
		if(it!=pre){
			depth[it]=depth[now]+1;
			getsiz(it,now);
		}
	}
}
int jump(int now,int dis){
	rep(i,19) if((dis>>i)&1) now=fa[now][i];
	return now;
} 
int lca(int u,int v){
	if(depth[u]<depth[v]) swap(u,v);
	u=jump(u,depth[u]-depth[v]);
	if(u==v) return u;
	rl(i,18,0) if(fa[u][i]!=fa[v][i]){u=fa[u][i],v=fa[v][i];}
	return fa[u][0];
}
int s[MAXN],t[MAXN],as[MAXN],at[MAXN];
vector<int> data[MAXN];
int chafen[MAXN];
LL rest=0;
int cnt_[MAXN];
void calc(int now,int pre){
	vector<int> son;
	for(auto it:g[now]){
		if(it!=pre){
			calc(it,now);
			chafen[now]+=chafen[it];
			son.PB(it);
		}
	}
	sort(ALL(son));
	map<int,int> cnt;
	map<mp,int> cnt2;
	int Sz=0;
	int sum=0;
	for(auto it:data[now]){
		if(as[it]){
			chafen[as[it]]--;
		}
		if(at[it]){
			chafen[at[it]]--;
		}
	}
	for(auto it:son)  sum+=chafen[it];
	for(auto it:data[now]){
		rest+=sum-chafen[as[it]]-chafen[at[it]];
//		cout<<now<<' '<<sum<<' '<<sum-chafen[as[it]]-chafen[at[it]]<<"$\n";
	}
	for(auto it:data[now]){
		rest+=cnt_[now];
//		cout<<now<<' '<<as[it]<<" "<<at[it]<<' '<<Sz<<endl;
		if(as[it]&&at[it]){
			rest+=Sz-cnt[at[it]]-cnt[as[it]]+cnt2[II(as[it],at[it])];
		}
		else{
			if(at[it]){
				rest+=Sz-cnt[at[it]];
			}
			else{
				rest+=Sz;
			}
		}
		cnt[as[it]]++;
		cnt[at[it]]++;
		cnt2[II(as[it],at[it])]++;
		++Sz;
	}
}
int main(){
	scanf("%d",&n);
	rb(i,1,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].PB(v);
		g[v].PB(u);
	}
	getsiz(1,0);
	cin>>m;
	rb(i,1,m){
		scanf("%d%d",&s[i],&t[i]);
		data[lca(s[i],t[i])].PB(i);
		int l=lca(s[i],t[i]);
		chafen[s[i]]++;
		chafen[t[i]]++;
		chafen[l]-=2;
		if(s[i]!=l){
			cnt_[s[i]]++;
		}
		if(t[i]!=l){
			cnt_[t[i]]++;
		}
		if(s[i]!=l){
			as[i]=jump(s[i],depth[s[i]]-depth[l]-1);
		}
		if(t[i]!=l){
			at[i]=jump(t[i],depth[t[i]]-depth[l]-1);
		}
		if(as[i]>at[i]) swap(as[i],at[i]);
	}
	calc(1,0);
	cout<<rest<<endl;
	return 0;
}