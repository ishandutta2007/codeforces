#include<iostream>
#include<cstdlib>
using namespace std;
bool pr[80005];
int a[40005],ai,b[20005],bi,n,k;
int main()
{
    cin>>n>>k;
    int i,j;
    for(i=2;i*i<80000;i++)if(pr[i]==0)for(j=i+i;j<80000;j+=i)pr[j]=1;
    for(i=2;i<=40000;i++)if(pr[i]==0)ai++,a[ai]=i;
    for(i=1;i<=ai;i++)if(!pr[a[i]+a[i+1]+1])bi++,b[bi]=a[i]+a[i+1]+1;
    if(b[k]>n)cout<<"NO";else cout<<"YES";
    return 0;
}