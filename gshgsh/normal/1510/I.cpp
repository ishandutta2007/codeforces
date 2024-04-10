#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
#include<cmath>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define base 0.8
#define MAXN 1001
int N,M,cnt[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int getc(){char c=getchar();while(c!='0'&&c!='1')c=getchar();return c-'0';}
int main()
{
	N=get(),M=get();mt19937 rnd(time(0));
	For(i,1,M)
	{
		vector<int>a(N);For(j,0,N-1)a[j]=getc();
		double s1=0,s2=0;For(j,0,N-1)if(a[j])s1+=pow(base,cnt[j]);else s2+=pow(base,cnt[j]);
		double r=rnd()/pow(2,32);if(r<s1/(s1+s2))cout<<1<<endl;else cout<<0<<endl;
		int x=get();For(j,0,N-1)cnt[j]+=x!=a[j];
	}
	return 0;
}