#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
int n,m,ans;
int main()
{
    cin>>n>>m;
    int l=1,r=n,mid;
    while(l<r)
    {
        int mid=(l+r)>>1;
        cout<<"1 "<<mid<<" "<<mid+1<<endl;
        string s;
        cin>>s;
        if(s=="TAK")
            r=mid;
        else
            l=mid+1;
    }
    ans=r;
    if(ans^1)
    {
        l=1,r=ans-1;
        while(l<r)
        {
            int mid=(l+r)>>1;
            cout<<"1 "<<mid<<" "<<mid+1<<endl;
            string s;
            cin>>s;
            if(s=="TAK")
                r=mid;
            else
                l=mid+1;
        }
        cout<<"1 "<<r<<" "<<ans<<endl;
        string s;
        cin>>s;
        if(s=="TAK")
        {
            cout<<"2 "<<r<<" "<<ans<<endl;
            return 0;
        }
    }
    l=ans+1,r=n;
    while(l<r)
    {
        int mid=(l+r)>>1;
        cout<<"1 "<<mid<<" "<<mid+1<<endl;
        string s;
        cin>>s;
        if(s=="TAK")
            r=mid;
        else
            l=mid+1;
    }
    cout<<"2 "<<ans<<" "<<r<<endl;
    return 0;
}