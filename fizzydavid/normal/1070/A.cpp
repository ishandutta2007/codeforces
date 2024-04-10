// This amazing code is by Eric Sunli Chen.
#include<bits/stdc++.h>
using namespace std;
template<typename T> bool get_int(T &x)
{
	char t=getchar();
	bool neg=false;
	x=0;
	for(; (t>'9'||t<'0')&&t!='-'&&t!=EOF; t=getchar());
	if(t=='-')neg=true,t=getchar();if(t==EOF)return false;
	for(; t<='9'&&t>='0'; t=getchar())x=x*10+t-'0';
	if(neg)x=-x;return true;
}
template<typename T> void print_int(T x)
{
	if(x<0)putchar('-'),x=-x;
	short a[20]= {},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1; i>=0; i--)putchar('0'+a[i]);
}
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define get1(a) get_int(a)
#define get2(a,b) (get1(a)&&get1(b))
#define get3(a,b,c) (get1(a)&&get2(b,c))
#define printendl(a) print_int(a),puts("")
typedef long long LL;
typedef unsigned long long uLL;
typedef pair<int,int> pii;
const int inf=0x3f3f3f3f;
const LL Linf=1ll<<61;
const double pi=acos(-1.0);

int d,s,pw10[3000111];

int dist[5111][511];
int q[5111*511*2],fr,rr;

void go(int x,int v)
{
	if(dist[x][v]==0)return;
//	printf("x= %d v= %d d= %d\n",x,v,dist[x][v]);
	for(int nxt=0;nxt<10;nxt++)
	{
		int nx=x-nxt,nv=(v-pw10[dist[x][v]-1]*nxt%d+d)%d;
		if(nx>=0&&dist[nx][nv]!=-1&&dist[nx][nv]<dist[x][v])
		{
			putchar(nxt+'0');
			for(int i=dist[nx][nv];i<dist[x][v]-1;i++)putchar('0');
			go(nx,nv);
			return;
		}
	}
}

int main()
{
	get2(d,s);
	pw10[0]=1;for(int i=1;i<3000111;i++)pw10[i]=pw10[i-1]*10%d;
	
	memset(dist,-1,sizeof(dist));
	dist[0][0]=0;
	fr=rr=0;q[rr++]=0;q[rr++]=0;
	for(;fr<rr;fr+=2)
	{
		int x=q[fr],v=q[fr+1];
		for(int nxt=0;nxt<10;nxt++)
		{
			int nx=x+nxt,nv=(v*10+nxt)%d;
			if(nx<=s&&dist[nx][nv]==-1)
			{
				dist[nx][nv]=dist[x][v]+1;
				q[rr++]=nx;q[rr++]=nv;
			}
		}
	}
	
	if(dist[s][0]==-1)
	{
		puts("-1");
		return 0;
	}
	
	go(s,0);
	
	return 0;
}