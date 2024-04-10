#include<cstdio>
#include<algorithm>
#include<set>
using namespace std;
multiset<int>st;
int i,j,m,n,p,k,x;
int main()
{ scanf("%d%d",&n,&k);
  for (i=1;i<=n;i++) scanf("%d",&x),st.insert(x);
  for (i=1;i<=n;i++){
  	scanf("%d",&x);
  	if (st.lower_bound(k-x)!=st.end()) p++,st.erase(st.lower_bound(k-x));}
  	printf("1 %d\n",p);
}