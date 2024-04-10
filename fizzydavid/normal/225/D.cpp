//while(true)rp++;
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<deque>
#include<iostream>
#include<iomanip>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
#define getid(v,x,y) (((x-1)*m+y-1)*(md+1)+v)
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
//0 L 1 R 2 U 3 D
const int dx[4]={0,0,-1,1};
const int dy[4]={-1,1,0,0};
const int revd[4]={1,0,3,2};
int n,m,l,w,md,Cn,gx,gy;
bool g[17][17];
bool hs[14745600];
char c[17][17];
pair<int,int> body[17];
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>c[i][j];
			if(c[i][j]=='@')
			{
				gx=i;
				gy=j;
			}
			else if(c[i][j]>='1'&&c[i][j]<='9')
			{
				body[c[i][j]-'0']=MP(i,j);
				l=max(l,c[i][j]-'0');
			}
			else if(c[i][j]=='#')
			{
				g[i][j]=1;
			}
		}
	}
	md=(1<<(2*(l-1)))-1;
	int v=0,hx,hy;
	int px,py,x=body[1].FF,y=body[1].SS;
	hx=x;hy=y;
	for(int i=2;i<=l;i++)
	{
		px=x;py=y;
		x=body[i].FF,y=body[i].SS;
		if(x==px)
		{
			if(py>y)v=(v<<2)|0;
			else v=(v<<2)|1;
		}
		else
		{
			if(px>x)v=(v<<2)|2;
			else v=(v<<2)|3;
		}
	}
	queue<pair<int,int> >q;
	q.push(MP(getid(v,hx,hy),0));
	hs[getid(v,hx,hy)]=1;
	bool ok=0;
	while(!q.empty())
	{
		int state=q.front().FF,dis=q.front().SS;
		q.pop();
		v=state&md,x=(state>>((l-1)*2))/m+1,y=(state>>((l-1)*2))%m+1;
//			cout<<dis<<" "<<x<<" "<<y<<endl;
		if(x==gx&&y==gy)
		{
			ok=1;
			cout<<dis<<endl;
			break;
		}
		int tx=x,ty=y;
		bool f[4]={};
		for(int i=l-2;i>0;i--)
		{
			int dir=(v>>(2*i))&3;
			tx+=dx[dir];ty+=dy[dir];
			for(int j=0;j<4;j++)
			{
				if(tx==x+dx[j]&&ty==y+dy[j])f[j]=1;
			}
		}
		for(int j=0;j<4;j++)
		{
			if(!f[j])
			{
				int nx=x+dx[j],ny=y+dy[j];
				if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!g[nx][ny])
				{
					int nxt;
					if(l==1)nxt=getid(0,nx,ny);
					else nxt=getid(((v>>2)+(revd[j]<<((l-2)*2))),nx,ny);
					if(!hs[nxt])
					{
//							cout<<"push:"<<nx<<" "<<ny<<endl;
						hs[nxt]=1;
						q.push(MP(nxt,dis+1));
					}
				}
			}
		}
	}
	if(!ok)cout<<-1<<endl;
	return 0;
}