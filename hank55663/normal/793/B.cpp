//#include<stdio.h>
//#include<stdlib.h>
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
#define MEM(x) memset(x,0,sizeof(x))
#define N 200005
#define M
#define pi 3.14159265359
#define count Count
using namespace std;
typedef long long LL;
int x[4]={0,0,1,-1};
int y[4]={1,-1,0,0};
int ok=0;
char ma[1005][1005];
int count[1005][1005];
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int x,y;
	for(int i=0;i<1005;i++)
		for(int j=0;j<1005;j++)
			ma[i][j]='*';
	for(int i=1;i<=n;i++){
		scanf("%s",ma[i]+1);
		for(int j=1;j<=m;j++)
		if(ma[i][j]=='S')
		x=i,y=j;
		ma[i][m+1]='*';
	}
	for(int i=0;i<1005;i++)
		for(int j=0;j<1005;j++)
			count[i][j]=-2;
	queue<pii> q;
	q.push(mp(x,y));
	count[x][y]=-1;
	while(!q.empty()){
		pii p=q.front();
		if(count[p.x][p.y]==1)
		break;
		q.pop();
		for(int i=1;ma[p.x+i][p.y]!='*';i++)
		{
			if(count[p.x+i][p.y]==-2)
			{
				count[p.x+i][p.y]=count[p.x][p.y]+1;
				q.push(mp(p.x+i,p.y));
			}
		}
		for(int i=1;ma[p.x-i][p.y]!='*';i++)
		{
			if(count[p.x-i][p.y]==-2)
			{
				count[p.x-i][p.y]=count[p.x][p.y]+1;
				q.push(mp(p.x-i,p.y));
			}
		}
		for(int i=1;ma[p.x][p.y+i]!='*';i++)
		{
			if(count[p.x][p.y+i]==-2)
			{
				count[p.x][p.y+i]=count[p.x][p.y]+1;
				q.push(mp(p.x,p.y+i));
			}
		}
		for(int i=1;ma[p.x][p.y-i]!='*';i++)
		{
			if(count[p.x][p.y-i]==-2)
			{
				count[p.x][p.y-i]=count[p.x][p.y]+1;
				q.push(mp(p.x,p.y-i));
			}
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			if(ma[i][j]=='T'){
				for(int k=1;ma[i+k][j]!='*';k++)
				{
					if(count[i+k][j]!=-2)
					{
						printf("YES\n");
						return 0;
					}
				}
				for(int k=1;ma[i-k][j]!='*';k++)
				{
					if(count[i-k][j]!=-2)
					{
						printf("YES\n");
						return 0;
					}
				}
				for(int k=1;ma[i][j+k]!='*';k++)
				{
					if(count[i][j+k]!=-2)
					{
						printf("YES\n");
						return 0;
					}
				}
				for(int k=1;ma[i][j-k]!='*';k++)
				{
					if(count[i][j-k]!=-2)
					{
						printf("YES\n");
						return 0;
					}
				}
				printf("NO\n");
				return 0;
			}
		}
	
}

/*90 110
180 220
270 330
360 440
450 550
540 660
630 770
xy=k(x+y)
xy=kx+ky
kx/(x-k)=y 
*/