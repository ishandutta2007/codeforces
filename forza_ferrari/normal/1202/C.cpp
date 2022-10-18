#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
int t,n;
long long ans;
vector<int> maxn[2][2],minn[2][2],sum[2];
string s;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>s;
        n=s.length();
        ans=0;
        maxn[0][0].clear();
        maxn[0][1].clear();
        maxn[1][0].clear();
        maxn[1][1].clear();
        minn[0][0].clear();
        minn[0][1].clear();
        minn[1][0].clear();
        minn[1][1].clear();
        sum[0].clear();
        sum[1].clear();
        sum[0].emplace_back(0);
        sum[1].emplace_back(0);
        for(int i=0;i<n;++i)
        {
            if(s[i]=='A')
                sum[0].emplace_back(sum[0].back()-1);
            if(s[i]=='D')
                sum[0].emplace_back(sum[0].back()+1);
            if(s[i]=='W')
                sum[1].emplace_back(sum[1].back()-1);
            if(s[i]=='S')
                sum[1].emplace_back(sum[1].back()+1);
        }
        maxn[0][0].resize(sum[0].size());
        minn[0][0].resize(sum[0].size());
        maxn[0][1].resize(sum[1].size());
        minn[0][1].resize(sum[1].size());
        maxn[1][0].resize(sum[0].size());
        minn[1][0].resize(sum[0].size());
        maxn[1][1].resize(sum[1].size());
        minn[1][1].resize(sum[1].size());
        maxn[0][0][0]=minn[0][0][0]=sum[0][0];
        maxn[0][1][0]=minn[0][1][0]=sum[1][0];
        maxn[1][0].back()=minn[1][0].back()=sum[0].back();
        maxn[1][1].back()=minn[1][1].back()=sum[1].back();
        /*for(int i:sum[0])
            cout<<i<<" ";
        cout<<endl;
        for(int i:sum[1])
            cout<<i<<" ";
        cout<<endl;*/
        for(int i=(int)sum[0].size()-2;i>=0;--i)
        {
            maxn[1][0][i]=max(maxn[1][0][i+1],sum[0][i]);
            minn[1][0][i]=min(minn[1][0][i+1],sum[0][i]);
        }
        for(int i=1;i<(int)sum[0].size();++i)
        {
            maxn[0][0][i]=max(maxn[0][0][i-1],sum[0][i]);
            minn[0][0][i]=min(minn[0][0][i-1],sum[0][i]);
        }
        for(int i=(int)sum[1].size()-2;i>=0;--i)
        {
            maxn[1][1][i]=max(maxn[1][1][i+1],sum[1][i]);
            minn[1][1][i]=min(minn[1][1][i+1],sum[1][i]);
        }
        for(int i=1;i<(int)sum[1].size();++i)
        {
            maxn[0][1][i]=max(maxn[0][1][i-1],sum[1][i]);
            minn[0][1][i]=min(minn[0][1][i-1],sum[1][i]);
        }
        /*for(int i:maxn[0][0])
            cout<<i<<" ";
        cout<<endl;
        for(int i:minn[0][0])
            cout<<i<<" ";
        cout<<endl;
        for(int i:maxn[0][1])
            cout<<i<<" ";
        cout<<endl;
        for(int i:minn[0][1])
            cout<<i<<" ";
        cout<<endl;
        for(int i:maxn[1][0])
            cout<<i<<" ";
        cout<<endl;
        for(int i:minn[1][0])
            cout<<i<<" ";
        cout<<endl;
        for(int i:maxn[1][1])
            cout<<i<<" ";
        cout<<endl;
        for(int i:minn[1][1])
            cout<<i<<" ";
        cout<<endl;*/
        ans=1ll*(maxn[1][0][0]-minn[1][0][0]+1)*(maxn[1][1][0]-minn[1][1][0]+1);
        for(int i=0;i<(int)sum[0].size();++i)
        {
            int r=max(maxn[1][0][0],sum[0][i]+1),l=min(minn[0][0][i],min(sum[0][i]+1,minn[0][0].back()+1));
            if(i+1!=sum[0].size())
                r=max(r,maxn[1][0][i+1]+1);
            ans=min(ans,1ll*(r-l+1)*(maxn[1][1][0]-minn[1][1][0]+1));
            l=min(minn[1][0][0],sum[0][i]-1),r=max(maxn[0][0][i],max(sum[0][i]-1,maxn[0][0].back()-1));
            if(i+1!=sum[0].size())
                l=min(l,minn[1][0][i+1]-1);
            ans=min(ans,1ll*(r-l+1)*(maxn[1][1][0]-minn[1][1][0]+1));
        }
        for(int i=0;i<(int)sum[1].size();++i)
        {
            int r=max(maxn[1][1][0],sum[1][i]+1),l=min(minn[0][1][i],min(sum[1][i]+1,minn[0][1].back()+1));
            if(i+1!=sum[1].size())
                r=max(r,maxn[1][1][i+1]+1);
            ans=min(ans,1ll*(r-l+1)*(maxn[1][0][0]-minn[1][0][0]+1));
            l=min(minn[1][1][0],sum[1][i]-1),r=max(maxn[0][1][i],max(sum[1][i]-1,maxn[0][1].back()-1));
            if(i+1!=sum[1].size())
                l=min(l,minn[1][1][i+1]-1);
            ans=min(ans,1ll*(r-l+1)*(maxn[1][0][0]-minn[1][0][0]+1));
        }
        cout<<ans<<'\n';
    }
    return 0;
}