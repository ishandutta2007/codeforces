#include <cstdio>
#include <cstring>

template<typename T> bool ckmax(T& a, const T& b) {return a<b?a=b,1:0;}
template<typename T> bool ckmin(T& a, const T& b) {return b<a?a=b,1:0;}

const int MN = 1e3+10;
const int MS = 19713+10;
const int INF = 0x3f3f3f3f;
const int MK = 12;

int N, x, cur[30], psum[30], X, c[MS][MK], g[MS][MK], p[MS], q[MS], dp[2][MS], ans=INF;
char s[MN];
bool bad[MS];

void add(int *x, int L)
{
	int n=0;
	for(int i=0;i<L;++i)
		if(~c[n][x[i]])
			n=c[n][x[i]];
		else
			n=c[n][x[i]]=++X;
	bad[n]=1;
}

void build()
{
	int Q=0;
	p[0]=-1;
	memset(g[0], 0, sizeof*g);//should alr be set to 0 but w/e
	for(int i=1,x;i<=9;++i)
		if(~(x=c[0][i]))
		{
			p[x]=0;
			g[0][i]=x;
			q[Q++]=x;
		}
	for(int i=0,n;i<Q;++i)
	{
		n=q[i];
		memcpy(g[n], g[p[n]], sizeof*g);
		for(int j=1,x;j<=9;++j)
			if(~(x=c[n][j]))
			{
				p[x]=g[p[n]][j];
				g[n][j]=x;
				q[Q++]=x;
			}
	}
}

void brute(int id, int n)
{
	if(n==x)
	{
		bool ok=1;
		for(int i=0;ok&&i<id;++i)
		{
			psum[i+1]=psum[i]+cur[i];
			for(int j=i+1==id;j<=i;++j)
				if(x%(psum[i+1]-psum[j])==0)
				{
					ok=0;
					break;
				}
		}
		if(ok)
		{
			add(cur, id);
			//for(int i=0;i<id;++i) printf("%d%c", cur[i], " \n"[i+1==id]);
		}
		return;
	}
	for(int i=1;i<=9;++i)
	{
		if(n+i>x) break;
		cur[id]=i;
		brute(id+1, n+i);
	}
}

int main()
{
	scanf(" %s%d", s, &x);
	for(;s[N];++N)s[N]-='0';
	memset(c, -1, sizeof c);
	brute(0, 0);
	build();
	memset(dp[1], 0x3f, sizeof*dp);
	dp[1][0]=0;
	for(int i=0;i<N;++i)
	{
		memcpy(dp[0], dp[1], sizeof*dp);
		for(int j=0;j<=X;++j) ++dp[1][j];
		for(int j=0,x;j<=X;++j)
		{
			x=g[j][s[i]];
			if(!bad[x])
				ckmin(dp[1][x], dp[0][j]);
		}
	}
	for(int i=0;i<=X;++i)
		ckmin(ans, dp[1][i]);
	printf("%d\n", ans);
	return 0;
}