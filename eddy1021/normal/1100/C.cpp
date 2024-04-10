#include <bits/stdc++.h>
using namespace std;
const double pi=acos(-1.);
double n, R;
int main(){
  cin>>n>>R;
  double theta=2.*pi/n;
  double alpha=2*(1-cos(theta));
  double xx=sqrt(max(0., 4*alpha*alpha+4*alpha*(4-alpha)));
  double bns=(2*alpha+xx)/(2*(4-alpha));
  printf("%.12f\n", bns*R);
}