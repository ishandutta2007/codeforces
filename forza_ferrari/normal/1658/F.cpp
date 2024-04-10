#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,n,m,a,b,sum[200001];
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>s;
        a=b=0;
        s=" "+s;
        for(int i=1;i<=n;++i)
            if(s[i]=='1')
                ++a;
            else
                ++b;
        for(int i=1;i<=n;++i)
            if(s[i]=='1')
                sum[i]=sum[i-1]-b;
            else
                sum[i]=sum[i-1]+a;
        bool flag=0;
        for(int i=m;i<=n;++i)
            if(sum[i]==sum[i-m])
            {
                flag=1;
                cout<<"1\n"<<i-m+1<<" "<<i<<'\n';
                break;
            }
        if(flag)
            continue;
        m=n-m;
        for(int i=m;i<=n;++i)
            if(sum[i]==sum[i-m])
            {
                flag=1;
                cout<<"2\n"<<1<<" "<<i-m<<'\n'<<i+1<<" "<<n<<'\n';
                break;
            }
        if(flag)
            continue;
        cout<<"-1\n";
    }
    return 0;
}