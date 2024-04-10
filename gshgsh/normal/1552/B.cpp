#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 50001
int T,N,a[MAXN][5];
bool cmp(int a[5],int b[5]){int cnt=0;For(i,0,4)cnt+=a[i]<b[i];return cnt>=3;}
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)For(j,0,4)a[i][j]=get();
		int x=1;For(i,2,N)if(cmp(a[i],a[x]))x=i;
		bool flag=1;For(i,1,N)if(i!=x&&cmp(a[i],a[x])){flag=0;break;}
		cout<<(flag?x:-1)<<endl;
	}
	return 0;
}