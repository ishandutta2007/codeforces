#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 101
int T,N,a[MAXN],b[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();int sum=0;For(i,1,N)sum+=a[i]=get();For(i,1,N)sum-=b[i]=get();if(sum){cout<<"-1\n";continue;}
		set<int>x,y;int M=0;For(i,1,N)if(a[i]!=b[i])(a[i]>b[i]?x:y).insert(i),M+=max(a[i]-b[i],0);
		cout<<M<<endl;while(M--){int i=*x.begin(),j=*y.begin();cout<<i<<' '<<j<<endl;a[i]--,a[j]++;if(a[i]==b[i])x.erase(i);if(a[j]==b[j])y.erase(j);}
	}
	return 0;
}