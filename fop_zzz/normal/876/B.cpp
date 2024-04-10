#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<algorithm>
#include<cstring>
#define For(i,j,k)	for(ll i=j;i<=k;++i)
#define Dow(i,j,k)	for(ll i=k;i>=j;--i)
#define maxm 10011
#define maxn 511
#define ll long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{if(c=='-')	f=-1;c=getchar();}
	while(c<='9'&&c>='0')	t=t*10+c-48,c=getchar();
	return t*f;
}
const int N=100005;
int b[N];
int a[N];
int ans,n,k,m;
int main()
{
	n=read();k=read();m=read();
	ans=-1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[a[i]%m]++;
		if(b[a[i]%m]>=k){
			ans=a[i]%m;
		}
	}
	if(ans==-1){
		puts("No");
		return 0;
	}
	puts("Yes");
	for(int i=1;i<=n&&k>0;i++){
		if(a[i]%m==ans)printf("%d ",a[i]),k--;
	}
	return 0;
}