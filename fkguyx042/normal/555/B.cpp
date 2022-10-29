#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<map>
#include<set>
#include<bitset>
using namespace std;
long long i,j,m,n,p,k,l[300005],r[300005],a[300005],Ans[300005],id[300005];
struct Node{long long Min,Max,id;}Q[300005];
set<pair<long long,int> >st;
inline bool cmp(int A,int b)
{
	  return a[A]<a[b]; 
}
inline bool Cmp(Node a,Node b)
{
	  return a.Min<b.Min;
}
int main()
{
  scanf("%d%d",&n,&m);
  set<pair<long long,int> >::iterator it;
  for (i=1;i<=n;++i)
    scanf("%I64d%I64d",&l[i],&r[i]);
  for (i=1;i<=m;++i) scanf("%I64d",&a[i]),id[i]=i; sort(id+1,id+m+1,cmp);
  for (i=1;i<n;++i) Q[i].Min=l[i+1]-r[i],Q[i].Max=r[i+1]-l[i],Q[i].id=i;
  sort(Q+1,Q+n,Cmp); int L=1;
  for (i=1;i<=m;++i) 
  {
  	  while (L<n&&Q[L].Min<=a[id[i]]) st.insert(make_pair(Q[L].Max,Q[L].id)),L++;
  	  it=st.lower_bound(make_pair(a[id[i]],0));
  	  if (it==st.end()) continue;
  	  pair<long long,int> x=*it;
  	  Ans[x.second]=id[i];
  	  st.erase(it);
  }
  for (i=1;i<n;++i) if (!Ans[i]) { printf("No\n"); return 0;}
  printf("Yes\n");
  for (i=1;i<n;++i) printf("%d ",Ans[i]);
}