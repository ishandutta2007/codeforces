/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
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
int n,m;
int fa[500000+20];
int root(int x){
	if(fa[x]==x) return x;
	return fa[x]=root(fa[x]);
}
int main(){
	scanf("%d%d",&n,&m);
	rb(i,1,m+1) fa[i]=i;
	vector<int> useful;
	rb(i,1,n){
		int k;
		vector<int> v;
		scanf("%d",&k);
		v.resize(k);
		rep(j,k){
			scanf("%d",&v[j]);
		}
		if(k==1){
			if(root(v[0])!=m+1){
				v[0]=root(v[0]);
				useful.PB(i);
				fa[v[0]]=m+1;
			}
		}
		else{
			int r1,r2;
			r1=root(v[0]);
			r2=root(v[1]);
			if(r1==r2) continue;
			if(r1>r2) swap(r1,r2);
			useful.PB(i);
			fa[r1]=r2;
		}
	}
	int sz=useful.size();
	int rest=1;
	rb(i,1,sz){
		rest=(rest+rest)%(1000000000+7);
	}
	cout<<rest<<' '<<sz<<endl;
	for(auto it:useful){
		printf("%d ",it);
	}  
	return 0;
}
/*

4 3
2 1 2
2 2 3
2 1 3
1 1
*/