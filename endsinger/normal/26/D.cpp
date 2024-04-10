#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    double ans=1;
    for(int i=0;i<=k;i++) 
    	ans*=(m-i)/(n+1.0+i);
    printf("%.12lf\n",max(1-ans,0.0));
    return 0;
}