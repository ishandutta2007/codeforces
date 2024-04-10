#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,i,tt,a[10101010];
int main()
{
    cin>>n;
    if(n==1||n==2)
        cout<<"1\n1\n";
    else
    if(n==3)
        cout<<"2\n1 3\n";
    else
    if(n==4)
        cout<<"4\n3 1 4 2\n";
    else
    {
        for(i=1;i<=n;i=i+2)
        {
            tt++;
            a[i]=tt;
        }
        for(i=2;i<=n;i=i+2)
        {
            tt++;
            a[i]=tt;
        }
        cout<<n<<"\n";
        for(i=1;i<n;i++)
            cout<<a[i]<<" ";
        cout<<a[n]<<"\n";
    }
}