#include<cstdlib>
#include<iostream>
using namespace std;
int n,k,c,a[400],sum;
int main()
{
    cin>>n>>k>>c;
    for(int i=1;i<=c;i++)cin>>a[i],sum+=(a[i]-a[i-1]-1)/k;
    sum+=c+(n-a[c])/k;cout<<sum;
    return 0;
}