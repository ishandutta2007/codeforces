#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
int n,m;
#define maxn 1010
ll sumv[2][2][maxn][maxn];
int lowbit(int &x){return x&(-x);}
void Add(int x,int y,ll v){
	for(int i=x;i<=n;i+=lowbit(i))
	for(int j=y;j<=n;j+=lowbit(j))
	sumv[x&1][y&1][i][j]^=v;
}
ll Query(int x,int y){
	ll ans=0;
	for(int i=x;i;i-=lowbit(i))
	for(int j=y;j;j-=lowbit(j))
	ans^=sumv[x&1][y&1][i][j];
	return ans;
}
int opt;
int main(){
	scanf("%d%d",&n,&m);
	int x0,y0,x1,y1;
	ll c;
	for(int i=1;i<=m;++i){
		scanf("%d",&opt);
		if(opt==1){
			ll ans=0;
			scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
			ans^=Query(x1,y1);
			ans^=Query(x1,y0-1);
			ans^=Query(x0-1,y1);
			ans^=Query(x0-1,y0-1);
			printf("%lld\n",ans);
		}else{
			scanf("%d%d%d%d%lld",&x0,&y0,&x1,&y1,&c);
			Add(x0,y0,c);
			Add(x0,y1+1,c);
			Add(x1+1,y0,c);
			Add(x1+1,y1+1,c);
		}
	}
	return 0;
}