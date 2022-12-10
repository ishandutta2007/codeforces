#include<cstdio>
#include<algorithm>
using namespace std;
int m,n,q[100000],a[100000];
main(){
  scanf("%d",&m);
  for(int i=0;i<m;i++)scanf("%d",&q[i]);
  scanf("%d",&n);
  for(int i=0;i<n;i++)scanf("%d",&a[i]);
  sort(q,q+m);
  sort(a,a+n);
  long long sum=0;
  int next=n-1,cur=0;
  while(next>=0){
    sum+=a[next];
    --next;
    ++cur;
    if(cur==q[0]){
      cur=0;
      if(next>=0)--next;
      if(next>=0)--next;
    }
  }
  printf("%I64d\n",sum);
}