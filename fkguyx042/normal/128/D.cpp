#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>

#define N 100005
using namespace std;
multiset<int>st;
multiset<int>::iterator it;
int a[N],i,j,m,n,p,k,L,R;
int main()
{
      st.insert(-1); st.insert((int)1e9+7);
      scanf("%d",&n);
      if (n&1)  { puts("NO\n"); return 0; }
      for (i=1;i<=n;++i) scanf("%d",&a[i]);
      sort(a+1,a+n+1);
      for (i=2;i<=n;++i) if (a[i]-a[i-1]>1) { puts("NO\n"); return 0; }
      for (i=1;i<=n;++i) st.insert(a[i]);
      st.erase(st.lower_bound(a[1]));
      it=st.lower_bound(a[1]+1);
      if (*it!=a[1]+1)
      {
         puts("NO"); return 0;
      }
      st.erase(it);
      it=st.lower_bound(a[1]+1);
      if (*it!=a[1]+1)
      {
         puts("NO"); return 0;
      }
      st.erase(it);
      L=R=a[1]+1;
      for (i=1;i<=n-3;++i)
      {
            if (L>R) swap(L,R);
            it=st.lower_bound(L-1);
            if (*it==L-1) 
            {
              st.erase(it);
              L--;
            }
            else 
            {
                it=st.lower_bound(L+1);
                if (*it==L+1)
                {
                   st.erase(it);
                   L++;
                }
                else { puts("NO"); return 0; }
            }
      }
      if (abs(L-R)!=1) puts("NO\n");
      else puts("YES\n");
}