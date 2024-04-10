#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
string s;
vector<int> v[100001];
vector<int> id[2],val[2][2];
int n,a[100001],cnt,num;
int main()
{
    cin>>s;
    n=s.length();
    s=" "+s;
    for(int i=1;i<=n;++i)
    {
        a[i]=s[i]=='R';
        num+=a[i]? 1:-1;
    }
    for(int i=1;i<=n;++i)
    {
        if(id[a[i]^1].empty())
            id[a[i]^1].emplace_back(++cnt);
        v[id[a[i]^1].back()].emplace_back(i);
        id[a[i]].emplace_back(id[a[i]^1].back());
        id[a[i]^1].pop_back();
    }
    cout<<cnt-1<<'\n';
    for(int i=1;i<=cnt;++i)
        val[a[v[i][0]]][a[v[i].back()]].emplace_back(i);
    if(val[0][1].size()&&val[1][0].size()&&!(val[0][0].size()+val[1][1].size()))
    {
        int x=val[0][1].back(),y=val[1][0].back();
        val[0][1].pop_back();
        val[1][0].pop_back();
        if(v[x].back()<v[y].back())
        {
            v[x].emplace_back(v[y].back());
            v[y].pop_back();
        }
        else
        {
            v[y].emplace_back(v[x].back());
            v[x].pop_back();
        }
        val[0][0].emplace_back(x);
        val[1][1].emplace_back(y);
    }
    if(num==-1)
    {
        while(!val[0][1].empty())
        {
            for(int i:v[val[0][1].back()])
                cout<<i<<" ";
            val[0][1].pop_back();
        }
        while(!val[0][0].empty())
        {
            for(int i:v[val[0][0].back()])
                cout<<i<<" ";
            val[0][0].pop_back();
            if(val[1][1].empty())
                break;
            for(int i:v[val[1][1].back()])
                cout<<i<<" ";
            val[1][1].pop_back();
        }
        while(!val[1][0].empty())
        {
            for(int i:v[val[1][0].back()])
                cout<<i<<" ";
            val[1][0].pop_back();
        }
    }
    else if(num==0)
    {
        while(!val[0][1].empty())
        {
            for(int i:v[val[0][1].back()])
                cout<<i<<" ";
            val[0][1].pop_back();
        }
        if(!val[0][0].empty())
        {
            for(int i:v[val[0][0].back()])
                cout<<i<<" ";
            val[0][0].pop_back();
        }
        while(!val[1][0].empty())
        {
            for(int i:v[val[1][0].back()])
                cout<<i<<" ";
            val[1][0].pop_back();
        }
        while(!val[1][1].empty())
        {
            for(int i:v[val[1][1].back()])
                cout<<i<<" ";
            val[1][1].pop_back();
            if(val[0][0].empty())
                break;
            for(int i:v[val[0][0].back()])
                cout<<i<<" ";
            val[0][0].pop_back();
        }
    }
    else
    {
        while(!val[1][0].empty())
        {
            for(int i:v[val[1][0].back()])
                cout<<i<<" ";
            val[1][0].pop_back();
        }
        while(!val[1][1].empty())
        {
            for(int i:v[val[1][1].back()])
                cout<<i<<" ";
            val[1][1].pop_back();
            if(val[0][0].empty())
                break;
            for(int i:v[val[0][0].back()])
                cout<<i<<" ";
            val[0][0].pop_back();
        }
        while(!val[0][1].empty())
        {
            for(int i:v[val[0][1].back()])
                cout<<i<<" ";
            val[0][1].pop_back();
        }
    }
    cout<<'\n';
    return 0;
}