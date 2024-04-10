#include<cstdio>
#include<algorithm>
#define N 1<<19
#define INF 1<<29
#define rg register
void re(rg int& x)
{
    rg bool f=false;rg char ch=getchar();x=0;
    while(ch<48)f=(ch=='-'),ch=getchar();
    while(47<ch)x=(x<<3)+(x<<1)+ch-48,ch=getchar();
    if(f)x=-x;
}

using namespace std;
struct data{int t1,t2,t3,t4;}t[N];
int l[N],r[N],mp[2][N];
char ch[N];
//->->->-> 
data merge(data a,data b)
{
	data tmp;
	tmp.t1=min(INF,min(a.t1+b.t1,a.t2+b.t3)+1);
	tmp.t2=min(INF,min(a.t1+b.t2,a.t2+b.t4)+1);
	tmp.t3=min(INF,min(a.t3+b.t1,a.t4+b.t3)+1);
	tmp.t4=min(INF,min(a.t4+b.t4,a.t3+b.t2)+1);
	return tmp;
}
void build(int now,int a,int b)
{
	l[now]=a,r[now]=b;
	if(a == b)
	{
		t[now].t1=t[now].t2=t[now].t3=t[now].t4=INF;
		if(mp[0][a])t[now].t1=0;
		if(mp[1][a])t[now].t4=0;
		if(mp[0][a] && mp[1][a])
			t[now].t2=t[now].t3=1;
		return;
	}
	build(now<<1,a,a+b>>1);
	build(now<<1|1,(a+b>>1)+1,b);
	t[now]=merge(t[now<<1],t[now<<1|1]);
}
data sol(int now,int a,int b)
{
	if(a<=l[now] && b>=r[now])return t[now];
	int mid=l[now]+r[now]>>1;
	if(b <= mid)return sol(now<<1,a,b);
	if(a > mid)return sol(now<<1|1,a,b);
	return merge(sol(now<<1,a,b),sol(now<<1|1,a,b));
}
int n,m;
int ask(int x,int y)
{
	int a=(x-1)%n+1,b=(y-1)%n+1;
	if(a > b)swap(a,b),swap(x,y);
	data tmp=sol(1,a,b);
	if(x<=n && y<=n)return tmp.t1;
	if(x<=n && y>n)return tmp.t2;
	if(x>n && y<=n)return tmp.t3;
	if(x>n && y>n)return tmp.t4;
}
int main()
{
	re(n),re(m);
	for(int i=0;i<2;++i)
	{
		scanf("%s",ch+1);
		for(int j=1;j<=n;++j)
			mp[i][j]=ch[j]=='.';
	}
	build(1,1,n);
	while(m--)
	{
		int x,y;
		re(x),re(y);
		int ans=ask(x,y);
		printf("%d\n",ans<INF?ans:-1);
	}
}