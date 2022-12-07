#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<ctime>

#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
#define _max(a,b) (a>b?a:b)
#define _min(a,b) (a<b?a:b)

using namespace std;
template<class T>
inline void read(T& x)
{
    bool f=false;char ch=getchar();x=0;
    while(ch<48)f=(ch=='-'),ch=getchar();
    while(ch>=48)x=(x<<3)+(x<<1)+ch-48,ch=getchar();
    if(f)x*=-1;
}
char a[333333],b[333333];
int aa[333333],bb[333333],n,cc[333333];
bool cmp (int a,int b){return a>b;}
int main()
{
	scanf("%s%s",a,b);
	n=strlen(a);
	for(int i=1;i<=n;i++)aa[i]=a[i-1];
	for(int i=1;i<=n;i++)bb[i]=b[i-1];
	sort(aa+1,aa+n+1);
	sort(bb+1,bb+n+1,cmp);
	int l=1,r=n,al=1,ar=n/2+n%2,bl=1,br=n/2;
	for(int i=1;i<=n/2;i++)
	{
		if(aa[al]>=bb[bl])cc[r--]=aa[ar--];
		else cc[l++]=aa[al++];
		if(aa[al]>=bb[bl])cc[r--]=bb[br--];
		else cc[l++]=bb[bl++];
	}
	for(int i=1;i<=n;i++)
		if(!cc[i])cc[i]=aa[al];
	for(int i=1;i<=n;i++)
		printf("%c",char(cc[i]));
}