#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define fi first
#define se second
#define ll long long

using namespace std;

int n,i,j;
double m=0,l=0,k=0;

int main()
{
  //freopen("input.txt","r",stdin);
  //freopen("output.txt","w",stdout);
  ios_base::sync_with_stdio(0);
  scanf("%lf %lf",&m,&l);
  scanf("%d",&n);
  int i=0;
  int u=0;
  double y=0;
  while (i<n)
  {
   i++;
   k+=l;
   u+=k/m;
   u=u%4;
   k=fmod(k,m);
   double t=m-k;
   if (u==0) printf("%.10lf %.10lf\n",k,y); else
   if (u==1) printf("%.10lf %.10lf\n",m,k); else
   if (u==2) printf("%.10lf %.10lf\n",t,m); else
   if (u==3) printf("%.10lf %.10lf\n",y,t);
  }
  return 0;
}