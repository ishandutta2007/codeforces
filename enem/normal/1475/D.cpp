#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin>>tc;
    while(tc--)
    {
        int n,m;
        cin>>n>>m;

        int a[n];
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }

        vector<int> v[2];
        for(int i=0; i<n; i++)
        {
            int typ;
            cin>>typ;
            v[typ-1].push_back(a[i]);
        }

        sort(v[0].begin(), v[0].end());
        sort(v[1].begin(), v[1].end());

        long long sum=0;
        int cur=0;
        for(auto it:v[0]) {sum+=it;cur++;}

        int ans=(1<<30);

        int l=0, r=v[1].size()-1;

        while((l<((int)v[0].size())&&sum>=m) || (r>=0&&sum<m))
        {
            if(l<((int)v[0].size())&&sum>=m)
            {
                ans=min(ans,cur);
                sum-=v[0][l];
                cur--;
                l++;
            }
            else
            {
                sum+=v[1][r];
                cur+=2;
                r--;
            }
        }

        if(sum>=m) ans=min(ans,cur);

        if(ans==(1<<30)) cout<<-1<<'\n';
        else cout<<ans<<'\n';
    }

    return 0;
}