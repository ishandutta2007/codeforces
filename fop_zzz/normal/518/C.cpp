#include<iostream>
#include<cstdio>
#include<cmath>
#include<queue>
#include<map>
#include<cstring>
#include<ctime>
#include<algorithm>
#define For(i,j,k)  for(register int i=j;i<=k;++i)
#define Dow(i,j,k)  for(register int i=k;i>=j;--i)
#define ll long long
#define mk make_pair
#define pb push_back
#define eps 1e-8
#define pa pair<int,int>
#define fir first
#define sec second
using namespace std;
inline int read()
{
    int t=0,f=1;char c=getchar();
    while(c<'0'||c>'9')   {if(c=='-') f=-1;c=getchar();}
    while(c>='0'&&c<='9') t=(t<<1)+(t<<3)+c-48,c=getchar();
    return t*f;
}
int n,m,k,x,now,tnow,pos1,pos2;  
int F[200001],num[200001];  
ll ans;
int main()  
{  
	n=read();m=read();k=read(); 
	For(i,1,n)
		scanf("%d",&x),num[F[x]=i]=x;  
	ans=m;  
	For(i,1,m)
	{
		scanf("%d",&x);  
 		ans+=(F[x]-1)/k;  
		if(F[x]!=1)
		{  
			pos1=F[x];  
			now=x;  
			tnow=num[pos1-1];  
			pos2=F[tnow];  
			swap(num[pos1],num[pos2]);  
			swap(F[now],F[tnow]);  
        }  
    }  
    cout<<ans<<endl;  
}