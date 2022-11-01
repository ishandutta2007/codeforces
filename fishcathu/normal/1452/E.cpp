#include<bits/stdc++.h>
#define pb push_back
typedef long long ll;
using namespace std;
const int N=2010;
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
int l[N],r[N],wg[N<<1];
int main()
{
	int n=read(),m=read(),k=read(),ans=0;
	for(int i=1;i<=m;++i)l[i]=read(),r[i]=read();
	for(int i=k;i<=n;++i)
	{
		memset(wg,0,sizeof wg);
		int s=0;
		for(int j=1;j<=m;++j)
		{
			int w=max(min(i,r[j])-max(i-k,l[j]-1),0);
			s+=w;
			++wg[l[j]+w];
			--wg[l[j]+k];                              
			--wg[r[j]+1];
			++wg[r[j]+k-w+1];
		}
		for(int j=1;j<=n;++j)ans=max(ans,s+=wg[j]+=wg[j-1]);
	}
	printf("%d",ans);
}