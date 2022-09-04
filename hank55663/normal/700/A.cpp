#include<bits/stdc++.h>
using namespace std;
int main(void)
{

    double l,v1,v2;
    int n,k;
    scanf("%d %lf %lf %lf %d",&n,&l,&v1,&v2,&k);
    int aa=n/k;
    if(n%k!=0)
    aa++;
    double aaa=aa;
    double ans=2.0*v2*aaa-v2+v1;
    ans/=(v2+v1);
    ans=ans-1;
    double anss=v2;
	anss/=v1;
	ans=ans+anss;
	anss=l*v2;
	anss/=v1;
	ans=anss/ans;
    printf("%.10lf\n",ans/v2+(l-ans)/v1);
}