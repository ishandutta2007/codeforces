#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int t,n,a[200001],l,r;
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        n<<=1;
        s=" "+s;
        l=r=0;
        for(int i=1;i<=n;++i)
        {
            a[i]=a[i-1]+(s[i]=='('? 1:-1);
            if(a[i]<0)
            {
                if(!l)
                    l=i;
                r=i;
            }
        }
        if(!l)
        {
            cout<<"0\n";
            continue;
        }
        int ql=-1e9,qr=-1e9,pl=-1,pr=-1,maxn=-1e9;
        for(int i=0;i<l;++i)
            if(a[i]>ql)
            {
                ql=a[i];
                pl=i+1;
            }
        for(int i=l;i<=r;++i)
            maxn=max(maxn,a[i]);
        for(int i=r+1;i<=n;++i)
            if(a[i]>qr)
            {
                qr=a[i];
                pr=i;
            }
        if(ql+qr>=maxn)
        {
            cout<<"1\n"<<pl<<" "<<pr<<'\n';
            continue;
        }
        maxn=-1e9;
        int node=-1;
        for(int i=1;i<=n;++i)
            if(a[i]>maxn)
            {
                maxn=a[i];
                node=i;
            }
        if(node==n)
            cout<<"1\n1 "<<node<<'\n';
        else
            cout<<"2\n1 "<<node<<'\n'<<node+1<<" "<<n<<'\n';
    }
    return 0;
}