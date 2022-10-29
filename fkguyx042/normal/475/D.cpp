#include<cstdio>
#include<algorithm>
#include<cstring>
#include<map>
using namespace std;
int i,j,m,n,p,k,tmp,cnt,q;
int stk[100001],a[100001],id[100001];
map<int,long long>mp;
int gcd(int x,int y) {return y==0?x:gcd(y,x%y);}
int main()
{  scanf("%d",&n); for (i=1;i<=n;i++) scanf("%d",&a[i]);
  for (i=1;i<=n;i++)
  {    for (j=1;j<=cnt;j++) stk[j]=gcd(a[i],stk[j]);
       stk[++cnt]=a[i]; id[cnt]=i; tmp=0;
      for (j=1;j<=cnt;j++)
      {   
	    stk[++tmp]=stk[j];
	    id[tmp]=id[j];
	    for (;j<=cnt&&stk[tmp]==stk[j];j++);
	    j--;
      }
      cnt=tmp;  tmp=i+1;
      for (j=cnt;j;j--)
       mp[stk[j]]+=tmp-id[j],tmp=id[j];
}
 scanf("%d",&q);
 for (;q--;)
 { scanf("%d",&k);
   printf("%I64d\n",mp[k]);
}
}