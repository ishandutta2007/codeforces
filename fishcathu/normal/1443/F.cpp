#include<bits/stdc++.h>
using namespace std;
const int N=2E5+10;
int read() 
{ 	
    int a=0;char b=1,c; 
    do if((c=getchar())==45)b=-1;while(!(c&16)); 
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())&16); 
    return a*b; 
} 
void write(int x) 
{
    if(x<0)putchar('-'),x=-x; 
    char a[10],s=0; 
    do a[s++]=x%10|48;while(x/=10); 
    do putchar(a[--s]);while(s);
}
int a[N],b[N];
int main()
{
	for(int x=read(),p=998244353;x--;)
	{
		int n=read(),m=read(),ans=1;
		for(int i=1;i<=n;++i)a[read()]=i;
		for(int i=1;i<=m;++i)b[i]=a[read()];
		memset(a,0,sizeof a),a[0]=a[n+1]=1;
		for(int i=1;i<=m;++i)a[b[i]]=1;
		for(int i=1;i<=m;++i)
		{
			ans=ans*1ll*(2-a[b[i]-1]-a[b[i]+1])%p;
			a[b[i]]=0;
		}
		write(ans),putchar('\n');
	}	
}