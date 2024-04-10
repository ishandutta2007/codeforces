#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
//#define pdd pair<double,double>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-8
#define mii map<int,int>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define N 200005
//#define M 1000005
#define pi 3.14159265359
#define cpdd const pdd
#define hash Hash
#define next Next
using namespace std;
typedef long long LL;
int f[100005];
int f1[100005];
int Find(int a){
	if(f[a]==a)
	return a;
	return f[a]=Find(f[a]);
}
int Find2(int a){
	if(f1[a]==a)
	return a;
	return f1[a]=Find2(f1[a]);
}
vector<int> v[100005];
pii index[100005];
int t;
void dfs(int n){
	int a=++t;
	for(vector<int>::iterator it=v[n].begin();it!=v[n].end();it++){
		dfs(*it);
	}
	index[n]=mp(a,t);
}
bool check(int u,int v){
	if(Find(u)==Find(v)){
		if(index[u].x<=index[v].x&&index[u].y>=index[v].x)
			return true;
	}
	return false;
} 
int main(){
	int n;
	t=0;
	scanf("%d",&n);
	pii p[100005];
	for(int i=1;i<=n;i++)
	f[i]=i,f1[i]=i;
	for(int i=1;i<=n;i++){
		int x,t;
		scanf("%d %d",&x,&t);
		p[i]=mp(x,t);
		v[x].pb(i);
		if(t==0)
		f[i]=Find(x);
		if(t==1)
		f1[i]=Find2(x);
	}
	MEM(index);
	for(int i=1;i<=n;i++){
		if(index[i].x==0)
		dfs(i);
	}
	int q;
	scanf("%d",&q);
	while(q--){
		int t,u,v;
		scanf("%d %d %d",&t,&u,&v);
		if(t==1){
			if(check(u,v)&&u!=v){
				printf("YES\n");
			}
			else{
				printf("NO\n");
			}
		}
		if(t==2){
			int fu=Find(u);
			int f2u=Find2(fu);
			int fv=Find2(v);
			if(f2u==fv&&index[fu].x<index[v].x&&index[fu].y>=index[v].x)
			printf("YES\n");
			else if(fv!=v&&check(fv,u))
			printf("YES\n");
			else
			printf("NO\n");
		}
	}
}