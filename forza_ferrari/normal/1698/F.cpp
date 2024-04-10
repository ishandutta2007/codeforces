#include<iostream>
#include<cstdio>
#include<vector>//
#include<algorithm>
using namespace std;
int t,n,a[505],b[505];
vector<pair<int,int> > v[2],ans;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        v[0].clear();
        v[1].clear();
        ans.clear();
        for(int i=1;i<=n;++i)
            cin>>a[i];
        for(int i=1;i<=n;++i)
            cin>>b[i];
        if(a[1]!=b[1]||a[n]!=b[n])
        {
            cout<<"NO\n";
            continue;
        }
        for(int i=1;i<n;++i)
        {
            v[0].emplace_back(a[i],a[i+1]);
            v[0].emplace_back(a[i+1],a[i]);
            v[1].emplace_back(b[i],b[i+1]);
            v[1].emplace_back(b[i+1],b[i]);
        }
        sort(v[0].begin(),v[0].end());
        sort(v[1].begin(),v[1].end());
        if(v[0]!=v[1])
        {
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        for(int i=2;i<n;++i)
            if(a[i]^b[i])
            {
                bool flag=0;
                for(int j=i+1;j<=n;++j)
                    if(a[j-1]==b[i]&&a[j]==b[i-1])
                    {
                        ans.emplace_back(i-1,j);
                        reverse(a+i-1,a+j+1);
                        flag=1;
                        break;
                    }
                if(flag)
                    continue;
                int p=0;
                for(int j=i;j<=n;++j)
                {
                    p=0;
                    flag=0;
                    for(int k=j+1;k<=n;++k)
                    {
                        if(a[k]==b[i]&&a[k-1]==b[i-1])
                            flag=1;
                        if(flag&&a[k]==a[j])
                        {
                            p=k;
                            break;
                        }
                    }
                    if(p)
                    {
                        ans.emplace_back(j,p);
                        reverse(a+j,a+p+1);
                        break;
                    }
                }
                for(int j=i+1;j<=n;++j)
                    if(a[j-1]==b[i]&&a[j]==b[i-1])
                    {
                        ans.emplace_back(i-1,j);
                        reverse(a+i-1,a+j+1);
                        break;
                    }
            }
        cout<<ans.size()<<'\n';
        for(auto i:ans)
            cout<<i.first<<" "<<i.second<<'\n';
    }
    return 0;
}