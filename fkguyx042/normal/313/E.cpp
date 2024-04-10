#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
int i,j,m,n,p,k,l,r,x,ans[100001];
multiset<int>st;
multiset<int>::iterator it;
int a[10000001];
inline bool cmp(int a,int b) { return a>b;}
int main()
{ scanf("%d%d",&n,&m);
  for (i=1;i<=n;i++) scanf("%d",&a[i]);
  l=1,r=n;
  for (i=1;i<=n;i++) scanf("%d",&k),st.insert(k);
  sort(a+1,a+n+1,cmp);
  for(;l<=r;l++)
    if (a[l]<0)
   {   ans[++ans[0]]=*--st.end()+a[l],st.erase(--st.end()); } else 
  {   it=st.upper_bound(m-a[l]-1);
      if (it==st.begin()) a[++r]=a[l]-m;
      else  ans[++ans[0]]=*--it+a[l],st.erase(it);
  }
  sort(ans+1,ans+n+1);
  for (i=n;i;i--) printf("%d ",ans[i]);
}