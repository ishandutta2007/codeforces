#include<cstdio>
#include<iostream>
using namespace std;
const int MAX=100000;
int n,a[MAX];
main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++)scanf("%d",&a[i]);
  long long sum=0;
  for(int i=0;i<n;i++)sum+=a[i];
  long long ans=(sum+n-2)/(n-1);
  for(int i=0;i<n;i++)ans=max(ans,(long long)a[i]);
  cout<<ans<<endl;
}