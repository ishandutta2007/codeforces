#include<iostream>//
#include<cstdio>
using namespace std;
int t,n,d[101],a[101];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)
        {
            a[i]=0;
            cin>>d[i];
        }
        bool flag=1;
        for(int i=1;i<=n;++i)
        {
            if(d[i]&&a[i-1]>=d[i])
            {
                flag=0;
                break;
            }
            a[i]=a[i-1]+d[i];
        }
        if(flag)
            for(int i=1;i<=n;++i)
                cout<<a[i]<<" ";
        else
            cout<<-1;
        cout<<'\n';
    }
    return 0;
}