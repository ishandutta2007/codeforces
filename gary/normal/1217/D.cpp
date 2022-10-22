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
int a[5001],b[5001],v[5001],OK=1;
vector<int> each[5001];
void Dfs(int now){
	if(!OK) return;
	v[now]=1;
	for(auto it:each[now]) {
	if(v[it]==1)
	{
		OK=0;
		return ;
	}
	else{
		if(!v[it]) Dfs(it);
	}
	}
	v[now]=2;
}
int main(){
	int n,m;
	cin>>n>>m;
	rep(i,m) scanf("%d %d",&a[i],&b[i]),each[a[i]].PB(b[i]);
	rep(i,n) if(!v[i]) Dfs(i);
	if(OK){
		puts("1");
		rep(i,m) printf("1 ");
	}
	else
	{
		puts("2");
		rep(i,m) cout<<(a[i]<b[i]? 1:2)<<" ";
	}
	return 0;
}