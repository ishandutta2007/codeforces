#include<cstdio>
#include<algorithm>
#include<cstring>
#include<set>
using namespace std;
int i,j,m,n,p,k,a[100001],w,h;
multiset<int>st,st1,St,St1;
char c[5];
int x;
int main()
{
  scanf("%d%d%d",&w,&h,&n); 
  st.insert(0);
  st.insert(w);
  st1.insert(0);
  st1.insert(h);
  St.insert(w);
  St1.insert(h);
  multiset<int>::iterator it,it1;
  for (;n--;)
 { 
     scanf("%s %d",&c,&x);
     if (c[0]=='H')
    {
    	      if (*st1.lower_bound(x)==x) continue;
    	      it=st1.lower_bound(x);
    	      it1=--it;
    	      it=st1.lower_bound(x);
    	      St1.erase(St1.lower_bound(*it-*it1));
    	      St1.insert(*it-x);
    	      St1.insert(x-*it1);
    	      st1.insert(x);
   }
   else {
   	        if (*st.lower_bound(x)==x) continue;
    	      it=st.lower_bound(x);
    	      it1=--it;
    	      it=st.lower_bound(x);
    	      St.erase(St.lower_bound(*it-*it1));
    	      St.insert(*it-x);
    	      St.insert(x-*it1);
    	      st.insert(x);
      }
    printf("%I64d\n",1ll*(*--St.end())*(*--St1.end()));
}
  return 0;
}