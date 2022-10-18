#include<iostream>
#include<cstdio>
#include<chrono>
#include<random>
#include<string>
#include<vector>
using namespace std;
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int t,n,m;
inline int solve(int l,int r)
{
    int mid;
    while(l<=r)
    {
        if(l==r)
            return l;
        vector<int> a,b;
        mid=(l+r)>>1;
        for(int i=l-(mid-l+1);i<l;++i)
            a.emplace_back(i);
        for(int i=l;i<=mid;++i)
            b.emplace_back(i);
        cout<<"? "<<a.size()<<" "<<b.size()<<endl;
        for(auto i:a)
            cout<<i<<" ";
        cout<<endl;
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
        string s;
        cin>>s;
        if(s=="FIRST")
            r=mid;
        else
            l=mid+1;
    }
    return 0;
}
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int pos=1;
        for(int i=1;i<=20;++i)
        {
            int p=rnd()%n+1;
            while(pos==p)
                p=rnd()%n+1;
            cout<<"? 1 1"<<endl<<pos<<endl<<p<<endl;
            string s;
            cin>>s;
            if(s=="SECOND")
                pos=p;
        }
        if(pos^1)
        {
            cout<<"! 1"<<endl;
            continue;
        }
        bool flag=0;
        int len=0;
        for(int i=2;i<=n;i<<=1)
        {
            len=i;
            int mid=i>>1;
            cout<<"? "<<mid<<" "<<mid<<endl;
            for(int j=1;j<=mid;++j)
                cout<<j<<" ";
            cout<<endl;
            for(int j=mid+1;j<=i;++j)
                cout<<j<<" ";
            cout<<endl;
            string s;
            cin>>s;
            if(s=="FIRST")
            {
                int ans=solve(mid+1,i);
                cout<<"! "<<ans<<'\n';
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            int ans=solve(len+1,n);
            cout<<"! "<<ans<<'\n';
        }
    }
    return 0;
}