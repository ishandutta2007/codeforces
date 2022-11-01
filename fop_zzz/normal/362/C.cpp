#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio> 
#include<algorithm>
#include<set>
#include<ctime>
#include<map>
#define ll long long 
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
using namespace std;
inline ll read()
{
    ll t=0,f=1;char tmp=getchar();
    while(tmp<'0'||tmp>'9')   {if(tmp=='-')	f=-1;tmp=getchar();}
    while(tmp>='0'&&tmp<='9') t=t*10+tmp-48,tmp=getchar();
    return t*f;
}//pre[i][j] ij 
int pre[5001][5001],rep[5001][5001],a[5001],ans1,mx,n,tx;
int main()
{
	n=read();
	For(i,1,n)	a[i]=read();
	For(i,1,n)
	{
		For(j,0,n-1)	pre[i][j]=pre[i-1][j];
		For(j,0,a[i]-1)	pre[i][j]++;		
	}
	For(i,1,n)	For(j,i+1,n)	if(a[i]>a[j])	tx++;
	For(i,1,n)	For(j,1,n)	rep[i][j]=i-pre[i][j];
	For(i,1,n)
		For(j,i+1,n)
		{ 
			if(a[j]>a[i])	continue;
			int tmp=(pre[j-1][a[j]]-pre[i][a[j]])-(rep[j-1][a[j]]-rep[i][a[j]]);
			tmp-=pre[j-1][a[i]]-pre[i][a[i]]-(rep[j-1][a[i]]-rep[i][a[i]]);
			tmp++;
			if(tmp==mx)	ans1++;
			if(tmp>mx)	ans1=1,mx=tmp;
//			cout<<i<<' '<<j<<' '<<' '<<(pre[j-1][a[j]]-pre[i][a[j]])<<' '<<(rep[j-1][a[j]]-rep[i][a[j]])<<' '<<pre[j-1][a[i]]-pre[i][a[i]]<<' '<<(rep[j-1][a[i]]-rep[i][a[i]])<<' '<<tmp<<endl;
		}
	cout<<tx-mx<<' '<<ans1<<endl;
}