#include <cstdio>
#include <cassert>

template<typename T> bool ckmax(T& a, const T& b){return a<b?a=b,1:0;}

const int MN = 5.3e3;

int N, p[MN][MN], pr[MN], P, c[MN], f=-1, cf=1;
bool a[MN][MN];
char s[MN];

bool ok(int v)
{
	for(int i=0;i<N;i+=v)
	{
		for(int j=0;j<N;j+=v)
		{
			int cnt=p[i+v][j+v]-p[i][j+v]-p[i+v][j]+p[i][j];
			//printf("%d\n", cnt);
			if(cnt!=0&&cnt!=v*v) return 0;
		}
	}
	return 1;
}
void brute(int n=0)
{
	if(n==P)
	{
		if(ok(cf))
			ckmax(f, cf);
		return;
	}
	int pcf=cf;
	brute(n+1);
	for(int i=0;i<c[n];++i)
	{
		cf*=pr[n];
		brute(n+1);
	}
	cf=pcf;
}
int main()
{
	scanf("%d", &N);
	for(int i=0;i<N;++i)
	{
		scanf("%s", s);
		for(int j=0;j<N/4;++j)
		{
			int x=s[j]<='9'?s[j]-'0':s[j]-'A'+10;
			for(int k=0;k<4;++k)
				a[i][j*4+k]=x>>3-k&1;
		}
	}
	for(int i=0;i<N;++i)
		for(int j=0;j<N;++j)
			p[i+1][j+1]=p[i+1][j]+p[i][j+1]-p[i][j]+a[i][j];
	int n=N;
	for(int i=2;i<=N;++i)
	{
		if(n%i==0)
		{
			pr[P]=i;
			c[P]=1;
			for(n/=i;n%i==0;n/=i)
				++c[P];
			++P;
		}
	}
	//for(int i=0;i<P;++i) printf("%d %d\n", pr[i], c[i]);
	f=1;
	for(int i=0;i<P;++i)
	{
		for(int j=0;j<c[i];++j)
			if(ok(f*pr[i]))
				f*=pr[i];
			else
				break;
	}
	//brute(0);
	assert(f>0);
	printf("%d\n", f);
	return 0;
}