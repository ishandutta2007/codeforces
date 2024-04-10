#include<iostream>
#include<cstdio>
using namespace std;
int t,n,cnt[26][26];
long long ans;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<26;++i)
            for(int j=0;j<26;++j)
                cnt[i][j]=0;
        for(int i=1;i<=n;++i)
        {
            char x,y;
            cin>>x>>y;
            ++cnt[x-'a'][y-'a'];
        }
        ans=0;
        for(int i=0;i<26;++i)
            for(int j=0;j<26;++j)
            {
                int sum=0;
                for(int k=0;k<26;++k)
                    if(k^j)
                        sum+=cnt[i][k];
                ans+=1ll*sum*cnt[i][j];
                sum=0;
                for(int k=0;k<26;++k)
                    if(k^i)
                        sum+=cnt[k][j];
                ans+=1ll*sum*cnt[i][j];
            }
        cout<<(ans>>1)<<'\n';
    }
    return 0;
}