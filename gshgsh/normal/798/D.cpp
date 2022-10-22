#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int N,p[MAXN],a[MAXN],b[MAXN];ll s1,s2;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
bool check(){ll sum1=0,sum2=0;For(i,1,(N>>1)+1)sum1+=a[p[i]],sum2+=b[p[i]];return sum1>s1&&sum2>s2;}
int main()
{
	N=get();For(i,1,N)p[i]=i;For(i,1,N)s1+=a[i]=get();s1>>=1;For(i,1,N)s2+=b[i]=get();s2>>=1;
	mt19937 rnd(time(0));while(1){shuffle(p+1,p+N+1,rnd);if(check()){cout<<(N>>1)+1<<'\n';For(i,1,(N>>1)+1)cout<<p[i]<<' ';return 0;}}cout<<"-1\n";return 0;
}