#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int t,n,m,ans;
string s;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>s>>m;
        vector<int> v;
        while(m--)
        {
            char c;
            cin>>c;
            for(int i=0;i<n;++i)
                if(s[i]==c)
                    v.emplace_back(i);
        }
        if(v.empty())
        {
            cout<<0<<endl;
            continue;
        }
        sort(v.begin(),v.end());
        ans=v[0];
        for(int i=1;i<(int)v.size();++i)
            ans=max(ans,v[i]-v[i-1]);
        cout<<ans<<endl;
    }
    return 0;
}