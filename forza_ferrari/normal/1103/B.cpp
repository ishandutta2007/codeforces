#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string s;
int main()
{
    while(1)
    {
        cin>>s;
        if(s!="start")
            return 0;
        cout<<"? 0 1"<<endl;
        cin>>s;
        if(s=="x")
        {
            cout<<"! 1"<<endl;
            continue;
        }
        int l=1,r=2;
        while(1)
        {
            cout<<"? "<<l<<" "<<r<<endl;
            cin>>s;
            if(s=="x")
                break;
            l=r;
            r=l<<1;
        }
        int ans=r,mid;
        while(l+1<r)
        {
            mid=(l+r)>>1;
            cout<<"? "<<l<<" "<<mid<<endl;
            cin>>s;
            if(s=="x")
            {
                ans=mid;
                r=mid;
            }
            else
                l=mid;
        }
        cout<<"! "<<ans<<endl;
    }
    return 0;
}