#include<iostream>
#include<cstdio>
#include<map>
#include<vector>
using namespace std;
int t,n,a[200001],cnt;
map<int,int> mp;
vector<int> v;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n;
        cnt=0;
        mp.clear();
        v.clear();
        for(int i=1;i<=n;++i)
        {
            cin>>a[i];
            if(a[i])
            {
                ++cnt;
                v.emplace_back(a[i]);
            }
            mp[a[i]]=1;
        }
        if(cnt>100)
        {
            cout<<"NO\n";
            continue;
        }
        for(int i=1;i<=min(3,n-cnt);++i)
            v.emplace_back(0);
        bool flag=1;
        for(int i=0;i<(int)v.size();++i)
            for(int j=i+1;j<(int)v.size();++j)
                for(int k=j+1;k<(int)v.size();++k)
                    if(!mp.count(v[i]+v[j]+v[k]))
                    {
                        flag=0;
                        break;
                    }
        cout<<(flag? "YES":"NO")<<'\n';
    }
    return 0;
}