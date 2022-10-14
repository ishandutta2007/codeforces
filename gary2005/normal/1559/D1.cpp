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
const int MAXN=1e3+1;
struct dsu{
	int fa[MAXN];
	dsu(){
		rep(i,MAXN) fa[i]=i;
	}
	int root(int x){
		if(fa[x]==x) return x;
		return fa[x]=root(fa[x]);
	}
	void merge(int u,int v){
		fa[root(u)]=root(v);
	}
}A,B;
int main(){
	int n,m1,m2;
	cin>>n>>m1>>m2;
	rb(i,1,m1){
		int u,v;
		scanf("%d%d",&u,&v);
		A.merge(u,v);
	}
	rb(i,1,m2){
		int u,v;
		scanf("%d%d",&u,&v);
		B.merge(u,v);
	}
	vector<mp> ans;
	rb(i,1,n) rb(j,i+1,n){
		if(A.root(i)!=A.root(j)&&B.root(i)!=B.root(j)){
			A.merge(i,j);
			B.merge(i,j);
			ans.PB(II(i,j));
		}
	}
	cout<<ans.size()<<endl;
	for(auto it:ans){
		cout<<it.FIR<<" "<<it.SEC<<endl;
	}
	return 0;
}