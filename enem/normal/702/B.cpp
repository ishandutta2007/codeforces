#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);


    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    long long ans=0;
    for(int k=1;k!=0;k<<=1)
    {
        int l=0;
        int r=n-1;
        while(l<=r)
        {
            if(a[l]+a[r]<k)
            {
                l++;
            }
            else if(a[l]+a[r]>k)
            {
                r--;
            }
            else if(a[l]+a[r]==k)
            {
                if(2*a[l]==k)
                {
                    ans+=(1LL*(r-l+1)*(r-l))/2;
                    break;
                }
                else
                {
                    int finr=r;
                    int finl=l;
                    while(a[finl+1]==a[l]) finl++;
                    while(a[finr-1]==a[r]) finr--;
                    ans+=(1LL*(finl-l+1)*(r-finr+1));
                    l=finl+1;
                    r=finr-1;
                }
            }
        }
    }
    cout<<ans;

    return 0;
}