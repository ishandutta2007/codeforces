#include <bits/stdc++.h>

using namespace std;
#define int long long
const int maxn=1e5+5;
vector<pair<int,int> > a[maxn];
bool used[maxn];
int hd[maxn];int hu[maxn];
int dpd[maxn];int dpu[maxn];int resu[maxn];
void dfs1(int x)
{
    used[x]=true;hd[x]=0;
    for(auto [v,w]:a[x])
    {
        if(used[v]) continue;
        dfs1(v);
        hd[x]=max(hd[x],hd[v]+w);
    }
    used[x]=false;
}
void dfs2(int x)
{
    used[x]=true;
    multiset<int> s;s.insert(hu[x]);
    for(auto [v,w]:a[x])
    {
        if(used[v]) continue;
        s.insert(hd[v]+w);
    }
    for(auto [v,w]:a[x])
    {
        if(used[v]) continue;
        s.erase(s.find(hd[v]+w));
        multiset<int>::iterator it=s.end();--it;
        hu[v]=(*it)+w;
        s.insert(hd[v]+w);
        dfs2(v);
    }
    used[x]=false;
}
void dfs3(int x)
{
    used[x]=true;
    vector<int> h;
    for(auto [v,w]:a[x])
    {
        if(used[v]) continue;
        h.push_back(hd[v]+w);
    }
    while(h.size()<2) h.push_back(0);
    sort(h.begin(),h.end());reverse(h.begin(),h.end());
    dpd[x]=h[0]+h[1];
    for(auto [v,w]:a[x])
    {
        if(used[v]) continue;
        dfs3(v);
        dpd[x]=max(dpd[x],dpd[v]);
    }
    used[x]=false;
}
int answ=0;
void dfs4(int x)
{
    resu[x]=max(resu[x],dpu[x]);
    used[x]=true;
    multiset<int> s;multiset<int> s1;multiset<int> s2;
    vector<int> s3;s3.push_back(hu[x]);
    for(auto [v,w]:a[x])
    {
        if(used[v]) continue;
        s.insert(hd[v]+w);
        s1.insert(hd[v]+w);
        s2.insert(dpd[v]);
        s3.push_back(hd[v]+w);
    }
    s.insert(0);s1.insert(0);s1.insert(0);s2.insert(0);s3.push_back(0);s3.push_back(0);s3.push_back(0);
    sort(s3.begin(),s3.end());reverse(s3.begin(),s3.end());
    answ=max(answ,s3[0]+s3[1]+s3[2]+s3[3]);
    for(auto [v,w]:a[x])
    {
        if(used[v]) continue;
        s.erase(s.find(hd[v]+w));
        s1.erase(s1.find(hd[v]+w));
        s2.erase(s2.find(dpd[v]));
        multiset<int>::iterator it=s.end();--it;
        multiset<int>::iterator it1=s1.end();--it1;
        multiset<int>::iterator it2=s2.end();--it2;
        int ans2=(*it1);--it1;ans2+=(*it1);
        dpu[v]=max(dpu[v],(*it2));
        dpu[v]=max(dpu[v],ans2);
        dpu[v]=max(dpu[v],(*it)+hu[x]);
        dpu[v]=max(dpu[v],dpu[x]);
        resu[v]=max(resu[v],resu[x]);
        resu[v]=max(resu[v],dpu[v]+2*w);
        s.insert(hd[v]+w);
        s1.insert(hd[v]+w);
        s2.insert(dpd[v]);
        dfs4(v);
    }
    used[x]=false;
}
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;cin>>n;int res=0;
    for(int i=0;i<n-1;++i) {int x,y,w;cin>>x>>y>>w;--x;--y;a[x].push_back({y,w});a[y].push_back({x,w});res+=(2*w);}
    dfs1(0);dfs2(0);dfs3(0);dfs4(0);
    int ans=answ;for(int i=0;i<n;++i) {ans=max(ans,dpd[i]+resu[i]);}
    cout<<(res-ans);
    return 0;
}
/*
7
1 3 1
1 2 100
3 4 100
3 5 100
2 6 100
2 7 100
*/
/*
10
1 10 1
10 2 100
2 3 100
10 4 100
4 5 100
10 6 100
6 7 100
10 8 100
8 9 100
*/