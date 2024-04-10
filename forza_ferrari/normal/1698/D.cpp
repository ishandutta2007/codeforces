#include<iostream>
#include<cstdio>
using namespace std;
int t,n;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        int l=1,r=n,mid,ans=0;
        while(l<=r)
        {
            mid=(l+r)>>1;
            cout<<"? "<<l<<" "<<mid<<endl;
            int cnt=0;
            for(int i=l;i<=mid;++i)
            {
                int x;
                cin>>x;
                cnt+=x>=l&&x<=mid;
            }
            if(cnt&1)
            {
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        cout<<"! "<<ans<<'\n';
    }
    return 0;
}