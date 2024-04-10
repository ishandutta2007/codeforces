#include<bits/stdc++.h>
//#define Min(a,b,c) min((a),min((b),(c)))
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb(x) push_back(x)
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-11
#define N 200005
#define pi 3.14159265359
using namespace std;
int color[N];
vector<int> v[N];
void dfs(int n,int f,int c){
	color[n]=c;
	int i=1;
	for(vector<int>::iterator it=v[n].begin();it!=v[n].end();it++){
		if(*it!=f){
			if(i==c)
			i++;
			if(i==color[f])
			i++;
			if(i==c)
			i++;
			dfs(*it,n,i);
			i++;
		}
	}
}
int main()
{	
	int n;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		v[a].pb(b);
		v[b].pb(a);
	}
	color[0]=0;
	dfs(1,0,1);
	int ans=0;
	for(int i=0;i<=n;i++)
	ans=max(ans,color[i]);
	printf("%d\n",ans);
	printf("%d",color[1]);
	for(int i=2;i<=n;i++)
	printf(" %d",color[i]);
}