#include <bits/stdc++.h>
using namespace std;
const int N=1021;
const double eps=1e-14;
int n, m, a[N], b[N];
bool okay(double fuel){
  for(int i=0; i<n; i++){
    {
      double nd=(m+fuel)/a[i];
      if(fuel<nd-eps) return false;
      fuel-=nd;
    }
    {
      double nd=(m+fuel)/b[(i+1)%n];
      if(fuel<nd-eps) return false;
      fuel-=nd;
    }
  }
  return true;
}
int main(){
  cin>>n>>m;
  for(int i=0; i<n; i++)
    cin>>a[i]>>b[i];
  double l=0, r=1e10;
  for(int i=0; i<70; i++){
    double mid=(l+r)*.5;
    if(okay(mid)) r=mid;
    else l=mid;
  }
  if(r>5e9) r=-1;
  printf("%.12f\n", r);
}