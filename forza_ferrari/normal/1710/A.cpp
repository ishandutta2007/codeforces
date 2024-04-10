#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m,p,a[100001];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>p;
        for(int i=1;i<=p;++i)
            cin>>a[i];
        int cnt=0;
        bool flag=0,tag=0;
        for(int i=1;i<=p;++i)
            if(a[i]>=n+n)
            {
                if(a[i]/n>2)
                    flag=1;
                if(m-cnt>1)
                    cnt+=a[i]/n;
                else
                    tag=1;
                if(cnt>=m)
                    tag=1;
            }
        if(tag&&(cnt>=m||flag))
        {
            cout<<"YES\n";
            continue;
        }
        cnt=flag=tag=0;
        for(int i=1;i<=p;++i)
            if(a[i]>=m+m)
            {
                if(a[i]/m>2)
                    flag=1;
                if(n-cnt>1)
                    cnt+=a[i]/m;
                else
                    tag=1;
                if(cnt>=n)
                    tag=1;
            }
        if(tag&&(cnt>=n||flag))
        {
            cout<<"YES\n";
            continue;
        }
        cout<<"NO\n";
    }
    return 0;
}