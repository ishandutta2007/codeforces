#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef unsigned int UL;
const UL MAXV=1e6+10;
UL V,E;
UL i,j,s,e,T;
vector<UL>adj[MAXV];
vector<UL>sc,sk;
queue<UL>Q;
bool vis[MAXV];
UL chk[50];
UL oud[MAXV],ind[MAXV];
bool flag;
void backtrack(UL X,UL cnt,UL P)
{
    if(flag)
        return;
    if(X>=sc.size())
    {
        if(cnt>0&&cnt<sc.size()&&cnt>=__builtin_popcount(P))
        {
            flag=true;
            cout<<"NO"<<endl;
        }
        return;
    }
    backtrack(X+1,cnt,P);
    backtrack(X+1,cnt+1,P|chk[X]);
    return;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>V>>E;
    for(i=0;i<E;i++)
    {
        cin>>s>>e;
        adj[--s].push_back(--e);
        oud[s]++;
        ind[e]++;
    }
    for(i=0;i<V;i++)
    {
        if(ind[i]==0)
            sc.push_back(i);
        if(oud[i]==0)
            sk.push_back(i);
    }
    for(i=0;i<sc.size();i++)
    {
        fill(vis,vis+V,false);
        Q.push(sc[i]);
        vis[sc[i]]=true;
        while(!Q.empty())
        {
            s=Q.front();
            Q.pop();
            for(j=0;j<adj[s].size();j++)
            {
                e=adj[s][j];
                if(!vis[e])
                {
                    vis[e]=true;
                    Q.push(e);
                }
            }
        }
        for(j=0;j<sk.size();j++)
            if(vis[sk[j]])
                chk[i]|=1<<j;
    }
    backtrack(0,0,0);
    if(!flag)
        cout<<"YES"<<endl;
    return 0;
}