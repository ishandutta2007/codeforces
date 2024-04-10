#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
#define INF 2000000000
#define ll long long
#define MAXN 50
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int dis[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
char mp[55][55];
bool b[55][55];
int n,m,k;

struct node{
	int x,y;
};

struct lake{
	int size;
	int pos[2600][2];
}l[2500];
int cc=0;

int p[2500];

bool cmp(int a,int b)
{
	return l[a].size<l[b].size;
}

void bfs(int xxxx,int yyyy)
{
	//cout<<"bfs"<<xxxx<<" "<<yyyy<<endl;
	queue<node> q;
	++cc;
	int size=0;
	bool yes=false;
	while(!q.empty()) q.pop();
	q.push((node){xxxx,yyyy});
	while(!q.empty())
	{
	    node newx=q.front();q.pop();
	    if(b[newx.x][newx.y]==1) continue;
		b[newx.x][newx.y]=1;
	    l[cc].pos[++size][0]=newx.x;
	    l[cc].pos[size][1]=newx.y;
	    if(newx.x==1||newx.x==n||newx.y==m-1||newx.y==0) yes=true;
	    //cout<<"get"<<newx.x<<" "<<newx.y<<endl;
	    for(int i=0;i<=3;i++)
	    {
	    	int xx=newx.x+dis[i][0];
	        int yy=newx.y+dis[i][1];
	       // cout<<"??"<<xx<<" "<<yy<<" "<<n<<" "<<m<<" "<<mp[xx][yy]<<endl;
            if(xx<=n&&xx>=1&&yy<m&&yy>=0)
            {
	            if(mp[xx][yy]=='*'||b[xx][yy]==1) continue;
	            q.push((node){xx,yy});
            }
	    }
	}
	if(yes)
	    cc--;
	else
	   l[cc].size=size;
}

int main()
{
	n=read(),m=read();k=read();
	for(int i=1;i<=n;i++)
	   cin.getline(mp[i],MAXN+5);
	for(int i=1;i<=n;i++)
	   for(int j=0;j<m;j++)
	   {
	   	   if(!b[i][j]&&mp[i][j]=='.') bfs(i,j);
	   }
	for(int i=1;i<=cc;i++)
	   p[i]=i;
	sort(p+1,p+cc+1,cmp);
	int ans=0;
	for(int i=1;i<=cc-k;i++)
	{
		int xy=p[i];
		ans+=l[xy].size;
		for(int j=1;j<=l[xy].size;j++)
		{
			//cout<<l[xy].pos[j][0]<<" "<<l[xy].pos[j][1]<<endl;
			mp[l[xy].pos[j][0]][l[xy].pos[j][1]]='*';
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<m;j++)
		   cout<<mp[i][j];
		cout<<endl;
	}
	return 0;
}