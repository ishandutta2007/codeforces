#include<iostream>
#include<cstdio>
using namespace std;
int n,ans,val,lst,sum;
int main()
{
    cin>>n;
    int l=1,r=n-1,mid;
    while(l<=r)
    {
        mid=(l+r)>>1;
        cout<<"+ "<<val+(n-mid)<<endl;
        sum+=val+(n-mid);
        int tmp;
        cin>>tmp;
        if(tmp^lst)
        {
            ans=mid;
            l=mid+1;
            val=mid;
        }
        else
        {
            r=mid-1;
            val=mid-n;
        }
        lst=tmp;
    }
    cout<<"! "<<ans+sum<<endl;
    return 0;
}