#include<iostream>
#include<cstdlib>
using namespace std;
int a[105],n,s,t;
int main()
{
    int i,c1=0,c2=0;
    cin>>n;
    for(i=1;i<=n;i++)cin>>a[i],c1+=a[i];
    cin>>s>>t;if(s>t)swap(s,t);
    for(i=s;i<t;i++)c2+=a[i];c1=c1-c2;
    if(c1<c2)cout<<c1;else cout<<c2;
    return 0;
}