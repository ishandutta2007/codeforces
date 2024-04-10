#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdlib>
#include<map>
#define For(i,j,k)	for(ll i=j;i<=k;++i)
#define Dow(i,j,k)	for(ll i=k;i>=j;--i)
#define ll  long long
using namespace std;
inline ll read()
{
	ll t=0,f=1;char c=getchar();
	while(c<'0'||c>'9')	{c=getchar();}
	while(c>='0'&&c<='9')	t=t*10+c-48,c=getchar();
	return t*f;
}
const int N=200005;
int ans,sum,n,m,k,a[N],vis[N];
int main(){
	n=read(); m=read(); k=read();
	For(i,1,n){a[i]=read(); vis[i]=1;}
	sort(&a[1],&a[n+1]);
	int l=0;
	For(i,1,n){
		sum++;
		while(a[l]<a[i]-m+1)
			sum-=vis[l++];
		if(sum>=k){
			vis[i]=0; ans++; sum--;
		}
	}
	cout<<ans<<endl;
}