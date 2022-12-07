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
#define LL long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v;
void re(int& x)
{
    bool f=false;char ch=getchar();x=0;
    while(ch<48)f=(ch=='-'),ch=getchar();
    while(47<ch)x=(x<<3)+(x<<1)+ch-48,ch=getchar();
    if(f)x=-x;
}
using namespace std;
int k,p[1001];
int main()
{
	re(k);k*=2;
	if(!k)puts("ab");
	else
	for(int i=0;k;++i)
	{
		int j;for(j=sqrt(k)+1;j*(j-1)>k;--j);
		k-=j*(j-1);
		for(int l=1;l<=j;++l)
			putchar(i+'a');
	}
	/*for(int i=2;i<=1000;++i)
	{
		p[i]=1<<29;
		for(int j=1;j<i;++j)
			p[i]=min(p[i],p[j]+p[i-j]+j*(i-j));
	}
	for(int i=1;i<=100;++i)
		cout<<p[i]<<" "<<i*(i-1)/2<<endl;*/
}