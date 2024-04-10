#include<iostream>
#include<cstdlib>
using namespace std;
int n,a[105],b[105],c[105],d[105],mi=1001,no;
bool e[105];
int main()
{
    int i,j;
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i]>>b[i]>>c[i]>>d[i];
    for(i=1;i<=n;i++)if(e[i]==0)for(j=1;j<=n;j++)if(a[i]>a[j]&&b[i]>b[j]&&c[i]>c[j])e[j]=1;
    for(i=1;i<=n;i++)if(d[i]<mi&&!e[i])no=i,mi=d[i];
    cout<<no;
    return 0;
}