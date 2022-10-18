#include<iostream>
#include<cstdio>
using namespace std;
int t,n,k,a[200001],l,r,sum[200001];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;++i)
            sum[i]=0;
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            ++sum[a[i]];
        }
        for(int i=2;i<=n;++i)
            sum[i]+=sum[i-1];
        int l=1,r=n;
        for(int i=1,j=1;i<=n;++i)
        {
            while(j<=n&&(sum[j]-sum[i-1])-(sum[n]-sum[j]+sum[i-1])<k)
                ++j;
            if(j>n||(sum[j]-sum[i-1])-(sum[n]-sum[j]+sum[i-1])<k)
                break;
            if((j-i+1)<(r-l+1))
            {
                l=i;
                r=j;
            }
        }
        cout<<l<<" "<<r<<endl;
        int cnt=0,lst=1;
        for(int i=1;i<=n;++i)
        {
            if(a[i]>=l&&a[i]<=r)
                ++cnt;
            else
                --cnt;
            if(cnt>0&&k>1)
            {
                cnt=0;
                cout<<lst<<" "<<i<<endl;
                lst=i+1;
                --k;
            }
        }
        cout<<lst<<" "<<n<<endl;
    }
    return 0;
}