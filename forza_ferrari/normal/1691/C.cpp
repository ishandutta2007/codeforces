#include<iostream>
#include<cstdio>
using namespace std;
int t,n,m,cnt[2];
pair<int,int> pos[2];
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        cnt[0]=cnt[1]=pos[0].first=pos[0].second=pos[1].first=pos[1].second=0;
        for(int i=1;i<=n;++i)
        {
            int x;
            char c;
            cin>>c;
            x=c-'0';
            ++cnt[x];
            if(!pos[x].first)
                pos[x].first=i;
            pos[x].second=i;
        }
        int ans=0;
        for(int l=0;l<2;++l)
            for(int r=0;r<2;++r)
            {
                int x=pos[l].first,y=pos[r].second;
                if(x==y||!x||!y)
                    continue;
                int sum=x-1+n-y-(x>y);
                if(sum<=m)
                    ans=max(ans,l+r*10);
            }
        cout<<cnt[1]*11-ans<<'\n';
    }
    return 0;
}