#include<map>
#include<set>
#include<ctime>
#include<queue>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define eps 1e-5
#define LL long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v;
void re(LL& x)
{
    bool f=false;char ch=getchar();x=0;
    while(ch<48)f=(ch=='-'),ch=getchar();
    while(47<ch)x=(x<<3)+(x<<1)+ch-48,ch=getchar();
    if(f)x=-x;
}
using namespace std;
LL n,y[1001];
bool ok;
int main()
{
	re(n);
	for(LL i=1;i<=n;++i)re(y[i]);
	for(LL i=2;i<=n;++i)
	{
		double k=(y[i]-y[1])/(i-1.0),b=y[1]-k,kk,bb;
		LL x1,y1,x2,y2;
		bool h1=false,h2=false,okk=true;
		for(LL j=1;j<=n;++j)
			if(fabs(j*k+b-y[j]) > eps)
			{
				if(h1==false)x1=j,y1=y[j],h1=true;
				else if(h2==false)
				{
					x2=j,y2=y[j],h2=true;
					kk=(y2-y1)/(double)(x2-x1),bb=y1-x1*kk;
				}else if(fabs(j*kk+bb-y[j]) > eps)okk=false;
			}
		if((fabs(k-kk)<eps || !h2) && h1 && okk)ok=true;
	}
	LL k=y[3]-y[2],b=y[2]-2*k;bool okk=(k+b != y[1]);
	for(LL i=2;i<=n;++i)
		if(i*k+b != y[i])
			okk=false;
	if(okk)ok=true;
	puts(ok?"Yes":"No");
}