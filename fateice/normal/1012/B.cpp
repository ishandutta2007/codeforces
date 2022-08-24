#include<bits/stdc++.h>
#define L long long
using namespace std;
int n,m,q,f[400010];
inline int fa(int i)
{
    return f[i]==i?i:f[i]=fa(f[i]);
}
inline void unit(int i,int j)
{
    i=fa(i);
    j=fa(j);
    if(i!=j)
      f[i]=j;
}
int main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	int i,j;
	scanf("%d%d%d",&n,&m,&q);
	for(i=1;i<=n+m;i++)
	  f[i]=i;
	while(q--)
	  {
       scanf("%d%d",&i,&j);
       unit(i,n+j);
      }
    int p=-1;
    for(i=1;i<=n+m;i++)
      if(fa(i)==i)
        p++;
    cout<<p;
	return 0;
}