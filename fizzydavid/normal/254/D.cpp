//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
#define ONLINE
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
struct point
{
	int x,y;
}a[300];
point makep(int x,int y){point ans;ans.x=x;ans.y=y;return ans;}
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
int n,m,num,d,mxr,mk[1011][1011],id[1011][1011],size[300],ord[300];
bool vis[22][22],alive1[300],alive2[300];
pair<point,int>q[150];
vector<point>v1,v2;
const int VECTOR1=1;
const int KILL1=2;
const int VECTOR2=3;
const int KILL2=4;
void bfs(point pt,int op)
{
	memset(vis,0,sizeof(vis));
	memset(q,0,sizeof(q));
	vis[10][10]=1;
	int front=0,rear=0;
	q[rear++]=MP(makep(10,10),0);
	while(front<rear)
	{
		point tp=q[front].FF;
		int x=tp.x,y=tp.y,dis=q[front].SS;front++;
		if(op==VECTOR1)v1.PB(makep(x+pt.x-10,y+pt.y-10));
		else if(op==VECTOR2)v2.PB(makep(x+pt.x-10,y+pt.y-10));
		else if(op==KILL1&&mk[x+pt.x-10][y+pt.y-10]==2)alive1[id[x+pt.x-10][y+pt.y-10]]=1;
		else if(op==KILL2&&mk[x+pt.x-10][y+pt.y-10]==2)alive2[id[x+pt.x-10][y+pt.y-10]]=1;
		if(dis==d)continue;
		for(int i=0;i<4;i++)
		{
			int nx=x+dx[i],ny=y+dy[i];
			if(mk[pt.x+nx-10][pt.y+ny-10]==0||vis[nx][ny])continue;
			q[rear++]=MP(makep(nx,ny),dis+1);
			vis[nx][ny]=1;
		}
	}
}
int livingcount;
int checkliving()
{
	int living=0;livingcount=0;
	for(int j=1;j<=num;j++)if(!alive1[ord[j]]&&!alive2[ord[j]]){living=ord[j];livingcount++;}
	return living;
}
bool comp(int i,int j)
{
	return size[i]<size[j];
}
int main()
{
#ifdef ONLINE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
	scanf("%d %d %d",&n,&m,&d);
	mxr=1+d*(d+1)*2;
	char c;
	for(int i=1;i<=n;i++)
	{
		getchar();
		for(int j=1;j<=m;j++)
		{
			scanf("%c",&c);
			if(c=='R')
			{
				num++;
				if(num>2*mxr){puts("-1");return 0;}
				a[num].x=i,a[num].y=j;id[i][j]=num;mk[i][j]=2;
			}
			else if(c=='.')mk[i][j]=1;
		}
	}
	int mn=INF,mni=0;
	for(int i=1;i<=num;i++)
	{
		bfs(a[i],VECTOR1);size[i]=v1.size();ord[i]=i;
		if(v1.size()<mn)mn=v1.size(),mni=i;
		v1.clear();
	}
	sort(ord+1,ord+num,comp);
	bfs(a[mni],VECTOR1);
	for(int i=0;i<v1.size();i++)
	{
		point ans1=v1[i];
		memset(alive1,0,sizeof(alive1));
		memset(alive2,0,sizeof(alive2));
		bfs(ans1,KILL1);
		int living=checkliving();
		if(living==0)
		{
			for(int t1=1;t1<=n;t1++)for(int t2=1;t2<=m;t2++)
			{
				if(mk[t1][t2]!=0&&t1!=ans1.x&&t2!=ans1.y)
				{
					printf("%d %d %d %d\n",ans1.x,ans1.y,t1,t2);
					return 0;
				}
			}
		}
		else
		{
			v2.clear();
			if(num-livingcount>mxr)continue;
			bfs(a[living],VECTOR2);
			for(int j=0;j<v2.size();j++)
			{
				memset(alive2,0,sizeof(alive2));
				point ans2=v2[j];
				if(ans1.x==ans2.x&&ans1.y==ans2.y)continue;
				bfs(ans2,KILL2);
				living=checkliving();
				if(living==0)
				{
					printf("%d %d %d %d\n",ans1.x,ans1.y,ans2.x,ans2.y);
					return 0;
				}
			}
		}
	}
	puts("-1");
	return 0;
}