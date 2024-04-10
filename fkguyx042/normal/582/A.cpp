#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
#define N 505
using namespace std;
multiset<int>st;
int i,j,m,n,p,k,a[N];
int gcd(int x,int y){return !y?x:gcd(y,x%y); }
int main()
{
   scanf("%d",&n);
   for (i=1;i<=n*n;++i) scanf("%d",&k),st.insert(k);
   for (i=1;i<=n;++i)
   {
   	  a[i]=*--st.end();
   	  for (j=1;j<i;++j)
   	  {
   	  	  st.erase(st.lower_bound(gcd(a[i],a[j])));
   	  	  st.erase(st.lower_bound(gcd(a[i],a[j])));
   	  }
   	  st.erase(st.lower_bound(a[i]));
   }
   for (i=1;i<=n;++i) printf("%d ",a[i]);
}