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
int X[4]={0,0,1,-1};
int Y[4]={1,-1,0,0};
int main(){
	int n,m,p,q;
	scanf("%d %d %d %d",&n,&m,&p,&q);
	char c[255][255];
	int ans[255][255];
	MEM(ans);
	for(int i=1;i<=n;i++)
	scanf("%s",c[i]+1);
	int vis[255][255];
	MEM(vis);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(c[i][j]!='.'&&c[i][j]!='*'){
			//	printf("%d %d\n",i,j);
				queue<pair<pii,int> > q;
				q.push(mp(mp(i,j),(c[i][j]-'A'+1)*p));
				vis[i][j]=i*255+j;
				ans[i][j]+=(c[i][j]-'A'+1)*p;
				while(!q.empty()){
					pair<pii,int> p=q.front();
					q.pop();
					int x=p.x.x;
					int y=p.x.y;
				//	printf("%d %d %d\n",x,y,p.y);
					if(p.y==1)
					continue;
					for(int k=0;k<4;k++){
						if(x+X[k]>0&&x+X[k]<=n&&y+Y[k]>0&&y+Y[k]<=m){
							if(vis[x+X[k]][y+Y[k]]!=i*255+j&&c[x+X[k]][y+Y[k]]!='*'){
								vis[x+X[k]][y+Y[k]]=i*255+j;
								ans[x+X[k]][y+Y[k]]+=p.y/2;
								q.push(mp(mp(x+X[k],y+Y[k]),p.y/2));
							}
						}
					}
				}
			}
		}
	int tot=0;
	for(int i=1;i<=n;i++)//,printf("\n"))
		for(int j=1;j<=m;j++)//printf("%d ",ans[i][j]),j++)
			if(ans[i][j]>q)
				tot++;
	printf("%d\n",tot);
}