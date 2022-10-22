#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
char buf[1<<21],*p1=buf,*p2=buf;
#define getchar() (p1==p2 && (p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
LL read()
{
	LL x=0;
	char c=getchar();
	while(c<'0' || c>'9')	c=getchar();
	while(c>='0' && c<='9')	x=(x<<1)+(x<<3)+(c^'0'),c=getchar();
	return x;
}
void write(LL x)
{
	if(x>9)	write(x/10);
	putchar(x%10+'0');
}
struct Point{
	LL x,y;
	Point(LL X=0,LL Y=0){x=X,y=Y;}
}p[6005];
LL n,st[4],ans;
int main(){
	n=read();
	for(LL i=1;i<=n;++i)	p[i]=Point(read()/2,read()/2),swap(p[i].x,p[i].y);
	for(LL i=1;i<=n;++i)	++st[(p[i].x&1)*2+(p[i].y&1)];
	for(LL i=0;i<=3;++i)
	{	
		for(LL j=i;j<=3;++j)
		{
			for(LL k=j;k<=3;++k)
			{
				if(i==0 && j==1 && k==2)	continue;
				if(i==0 && j==1 && k==3)	continue;
				if(i==0 && j==2 && k==3)	continue;
				if(i==1 && j==2 && k==3)	continue;
				if(i==j && j==k)	ans+=st[i]*(st[i]-1)*(st[i]-2)/6;
				else if(i==j)	ans+=st[i]*(st[i]-1)*st[k]/2;
				else if(j==k)	ans+=st[i]*st[j]*(st[j]-1)/2;
				// It's impossible to make i equal k
				else	ans+=st[i]*st[j]*st[k];
			}
		}
	}
	write(ans);
	return 0;
}