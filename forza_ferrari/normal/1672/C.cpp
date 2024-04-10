#include<iostream>
#include<cstdio>
using namespace std;
int t,n,a[200001],ans,cnt;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        cnt=0;
        for(int i=1;i<=n;++i)
            cin>>a[i];
        for(int i=1;i<n;++i)
            cnt+=a[i]==a[i+1];
        if(cnt<=1)
        {
            cout<<"0\n";
            continue;
        }
        bool flag=0;
        for(int i=2;i<=n;++i)
            if(a[i]==a[i-1])
            {
                for(int j=n-1;j>=1;--j)
                    if(a[j]==a[j+1])
                    {
                        cout<<max(1,j-i)<<'\n';
                        flag=1;
                        break;
                    }
                if(flag)
                    break;
            }
    }
    return 0;
}