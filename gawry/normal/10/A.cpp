#include<cstdio>
#include<algorithm>
using namespace std;
main(){
  int n,p1,p2,p3,t1,t2,a=0,l[101],r[101];
  scanf("%d %d %d %d %d %d",&n,&p1,&p2,&p3,&t1,&t2);
  for(int i=0;i<n;i++){
    scanf("%d %d",&l[i],&r[i]);
    a+=(r[i]-l[i])*p1;
    if(!i)continue;
    int left=l[i]-r[i-1];
    int take=min(left,t1);
    left-=take;
    a+=take*p1;
    take=min(left,t2);
    left-=take;
    a+=take*p2;
    a+=left*p3;
  }
  printf("%d\n",a);
}