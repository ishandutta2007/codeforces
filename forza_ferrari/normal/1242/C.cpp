#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
#define int long long
int n,sum,val[21];
bool dp[1<<15];
vector<int> v[21];
vector<pair<int,int> > ans[1<<15];
map<int,int> mp;
inline bool cmp(pair<int,int> x,pair<int,int> y)
{
    return mp[x.first]<mp[y.first];
}
signed main()
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        int len;
        cin>>len;
        v[i].resize(len);
        for(int j=0;j<len;++j)
        {
            cin>>v[i][j];
            sum+=v[i][j];
            val[i]+=v[i][j];
            mp[v[i][j]]=i;
        }
    }
    if(sum%n)
    {
        cout<<"NO\n";
        return 0;
    }
    sum/=n;
    for(int i=1;i<=n;++i)
        for(int j:v[i])
        {
            int s=1<<(i-1),lst=i,pos=0,w=sum-val[i]+j;
            vector<pair<int,int> > tmp;
            tmp.emplace_back(j,0);
            bool flag=0;
            if(mp.count(w))
                pos=mp[w];
            else
                continue;
            while(1)
            {
                if(pos==i&&w==j)
                    flag=1;
                if(s>>(pos-1)&1)
                    break;
                s|=1<<(pos-1);
                tmp.emplace_back(w,lst);
                w=sum-val[pos]+w;
                if(mp.count(w))
                {
                    lst=pos;
                    pos=mp[w];
                }
                else
                {
                    flag=0;
                    break;
                }
            }
            tmp[0].second=lst;
            if(flag)
            {
                if(dp[s])
                    continue;
                dp[s]=1;
                ans[s]=tmp;
            }
        }
    for(int s=0;s<1<<n;++s)
    {
        if(dp[s])
            continue;
        for(int t=s&(s-1);t;t=s&(t-1))
            if(dp[t]&&dp[s^t])
            {
                dp[s]=1;
                ans[s]=ans[t];
                for(auto i:ans[s^t])
                    ans[s].emplace_back(i);
                break;
            }
    }
    if(dp[(1<<n)-1])
    {
        cout<<"YES\n";
        sort(ans[(1<<n)-1].begin(),ans[(1<<n)-1].end(),cmp);
        for(auto i:ans[(1<<n)-1])
            cout<<i.first<<" "<<i.second<<'\n';
    }
    else
        cout<<"NO\n";
    return 0;
}