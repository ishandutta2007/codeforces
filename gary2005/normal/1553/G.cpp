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
const int MAXN=150000+1;
const int MAXQ=3e5+1;
int n,q,a[MAXN];
vector<int> fac[1000000+2];
bool vis[1000000+2];
int fa[1000000+2];
int root(int x){
	return fa[x]=(x==fa[x]? x:root(fa[x]));
}
unordered_map<LL,bool> have;
int main(){
	scanf("%d%d",&n,&q);
	rb(i,2,1000001){
		if(!vis[i])
			for(int j=i;j<=1000001;j+=i)
				vis[j]=1,fac[j].PB(i);
	}
	rb(i,2,1000000) fa[i]=i;
	rb(i,1,n){
		scanf("%d",&a[i]);
		rep(j,fac[a[i]].size()){
			if(j){
				fa[root(fac[a[i]][j-1])]=root(fac[a[i]][j]);
			}
		}
	}
	rb(i,1,n){
		vector<int> Tmp;
		for(auto it:fac[a[i]+1]) Tmp.PB(it);
		for(auto it:fac[a[i]]) Tmp.PB(it);
		for(auto it1:Tmp) for(auto it2:Tmp) if(root(it1)!=root(it2)) have[(LL)root(it1)<<21|root(it2)]=1;
	}
	rb(i,1,q){
		int s,t;
		scanf("%d%d",&s,&t);
		s=a[s];
		t=a[t];
		int ans=2;
		for(auto it:fac[s]) for(auto it2:fac[t]) if(root(it)==root(it2)){
			ans=0;
		}
		else{
			if(ans==2&&have[(LL)(root(it))<<21|root(it2)]) ans=1;
		}
		printf("%d\n",ans);
	}
	return 0;
}