#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int t,n,l,r,cnt[200001],res[2];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>l>>r;
        for(int i=1;i<=n;++i)
            cnt[i]=0;
        res[0]=res[1]=0;
        int sum=abs(r-l)>>1;
        for(int i=1;i<=l;++i)
        {
            int x;
            cin>>x;
            ++cnt[x];
        }
        for(int i=1;i<=r;++i)
        {
            int x;
            cin>>x;
            --cnt[x];
        }
        int ans=0,tot=0;
        for(int i=1;i<=n;++i)
        {
            ans+=abs(cnt[i]);
            if((l>r)==(cnt[i]>0))
            {
                tot+=min(sum,abs(cnt[i])>>1);
                sum-=min(sum,abs(cnt[i])>>1);
            }
        }
        cout<<(ans>>1)+(abs(r-l)>>1)-tot<<'\n';
    }
    return 0;
}