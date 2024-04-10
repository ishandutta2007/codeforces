//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
vector<int> each[100000+10];
int n;
int a[100000+10];
int s[100000+10];
int father[100000+10];
int OK=1;
void dfs(int now,int color){
	if(color==1){
		int SZ=each[now].size();
		a[now]=s[now]-s[father[now]];
		rep(i,SZ){
			int to=each[now][i];
			dfs(to,color^1);
		} 
	}
	else{
		int SZ=each[now].size();
		if(SZ==0) return;
		int minimum=INF;
		rep(i,SZ){
			int to=each[now][i];
			minimum=min(s[to],minimum);
		}
		a[now]=minimum-s[father[now]];
		if(a[now]<0) OK=false;
		s[now]=s[father[now]]+a[now];
		rep(i,SZ){
			int to=each[now][i];
			dfs(to,color^1);
		}
	}
}
int main(){
	scanf("%d",&n);
	rb(i,2,n){
		int parent;
		scanf("%d",&parent);
		each[parent].PB(i);
		father[i]=parent;
	}
	rb(i,1,n) scanf("%d",&s[i]);
	dfs(1,1);
	if(!OK){
		puts("-1");
		return 0;
	}
	LL res=0;
	rb(i,1,n) res+=a[i];
	cout<<res<<endl;
	return 0;
}