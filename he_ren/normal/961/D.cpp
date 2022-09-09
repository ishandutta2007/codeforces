#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
typedef long double ldb;
const int MAXN = 1e5 + 5;
const int TESTS = 1e2;
const ldb eps = 1e-10;

inline int Abs(int x){ return x<0? -x: x;}
inline ldb Fabs(ldb x){ return x<0? -x: x;}
inline bool eq(ldb x,ldb y){ return Fabs(x-y)<=eps;}
int gcd(int a,int b){ return b? gcd(b,a%b): a;}
inline void YES(void){ printf("YES"); exit(0);}

struct Node
{
	int x,y;
	bool operator == (const Node &b){ return x==b.x && y==b.y;}
	bool operator != (const Node &b){ return !(*this==b);}
}p[MAXN];
typedef Node Data;

inline Data slope(Node u,Node v)
{
	v.x-=u.x;
	v.y-=u.y;
	if(!v.x) v.y = 2e9 + 5;
	else
	{
		int t=gcd(v.x,v.y);
		v.x/=t; v.y/=t;
	}
	return v;
}

bool is[MAXN];

int main(void)
{
	srand(time(0));
	
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d%d",&p[i].x,&p[i].y);
	
	if(n<=4) YES();
	
	for(int ti=1; ti<=3; ++ti)
	for(int tj=1; tj<ti; ++tj)
	{
		memset(is,0,sizeof(is));
		
		int u=ti,v=tj;
		Data slp = slope(p[u],p[v]);
		is[u]=is[v]=1;
		for(int i=1; i<=n; ++i)
			if(!is[i]) is[i] = (slp==slope(p[u],p[i]));
		
		u=v=0;
		for(int i=1; i<=n; ++i)
			if(!is[i])
			{
				if(!u) u=i;
				else{ v=i; break;}
			}
		if(!v) YES();
		slp = slope(p[u],p[v]);
		is[u]=is[v]=1;
		bool flag=1;
		for(int i=1; i<=n; ++i)
			if(!is[i] && slp!=slope(p[u],p[i]))
			{
				flag=0;
				break; 
			}
		if(flag) YES();
	}
	printf("NO");
	return 0;
}