#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<set>
#include<ctime>
#include<queue>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>

#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout);
#define LL long long
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
int n,m,s[11111],b[11111];
bool fin[11111];
int main()
{
	read(n),read(m);
	for(int i=1;i<=n;i++)read(s[i]),b[i]=s[i];
	while(m--)
	{
		int l,r,x;
		read(l),read(r),read(x);
		memset(fin,false,sizeof(fin));
		for(int i=l;i<=r;i++)fin[s[i]]=true;
		for(int i=l,j=1;j<=n;j++)
			if(fin[j])
				s[i++]=j;
		if(s[x] == b[x])puts("Yes");
		else puts("No");
		for(int i=l;i<=r;i++)s[i]=b[i];
	}
}