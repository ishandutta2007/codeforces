#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;
int n,a[1000001],ans;
string s;
vector<pair<int,int> > v,tmp;
int main()
{
    cin>>s;
    n=s.length();
    s=" "+s;
    for(int i=1;i<=n;++i)
        a[i]=s[i]-'a';
    int cnt=1;
    for(int i=2;i<=n;++i)
        if(a[i]!=a[i-1])
        {
            v.push_back({a[i-1],cnt});
            cnt=1;
        }
        else
            ++cnt;
    v.push_back({a[n],cnt});
    while(v.size()>1)
    {
        tmp.clear();
        for(int i=0;i<(int)v.size();++i)
        {
            if(i==0||i==(int)v.size()-1)
                --v[i].second;
            else
                v[i].second-=2;
            if(v[i].second>0)
            {
                if(!tmp.empty()&&tmp.back().first==v[i].first)
                    tmp.back().second+=v[i].second;
                else
                    tmp.push_back(v[i]);
            }
        }
        v=tmp;
        ++ans;
    }
    cout<<ans<<'\n';
    return 0;
}