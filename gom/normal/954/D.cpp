#include <bits/stdc++.h>
#define N 1005
#define MAX 1000000000
using namespace std;
int n,m,s,e,ds[N],de[N],dist,ans;
bool visit1[N],visit2[N],graph[N][N];
vector<int> g[N];
queue<int> que;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>s>>e;
    for(int i=1;i<=m;i++){
        int p,q;
        cin>>p>>q;
        graph[p][q]=graph[q][p]=true;
        g[p].push_back(q);
        g[q].push_back(p);
    }
    visit1[s]=true;
    que.push(s);
    while(!que.empty()){
        int tp=que.front();
        que.pop();
        for(auto &it : g[tp]){
            if(!visit1[it]){
                ds[it]=ds[tp]+1;
                visit1[it]=true;
                que.push(it);
            }
        }
    }
    dist=ds[e];
    //cout<<dist<<endl;
    visit2[e]=true;
    que.push(e);
    while(!que.empty()){
        int tp=que.front();
        que.pop();
        for(auto &it : g[tp]){
            if(!visit2[it]){
                de[it]=de[tp]+1;
                visit2[it]=true;
                que.push(it);
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(graph[i][j]||i==s||i==e||j==s||j==e)
                continue;
                //cout<<i<<" "<<j<<" "<<ds[i]+de[j]+1<<" "<<de[i]+ds[j]+1<<" "<<dist<<endl;
            if(ds[i]+de[j]+1>=dist&&de[i]+ds[j]+1>=dist){
                ans++;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(i==s||graph[i][s])
            continue;
        //cout<<i<<" : "<<de[i]+1<<endl;
        if(de[i]+1>=dist)
            ans++;
    }
    for(int i=1;i<=n;i++){
        if(i==e||graph[i][e])
            continue;
        //cout<<i<<" :: "<<ds[i]+1<<endl;
        if(ds[i]+1>=dist)
            ans++;
    }
    cout<<ans;
    return 0;
}