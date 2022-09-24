#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<LL,LL>PL;
const LL INF=1e18;
const int MAXV=5e5+10;
vector<int>adj[MAXV];
bool D[MAXV];
void dfs(int x,int p,bool d)
{
    D[x]=d;
    for(int i=0;i<adj[x].size();i++)
        if(adj[x][i]!=p)
            dfs(adj[x][i],x,!d);
    return;
}
char S[MAXV];
int T,N,s,e,d2;
int i,j;
vector<int>V;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>T;
    while(T-->0)
    {
        cin>>N;
        for(i=1;i<N;i++)
        {
            cin>>s>>e;
            adj[--s].push_back(--e);
            adj[e].push_back(s);
        }
        cin>>S;
        for(i=0;i<N;i++)
        {
            if(S[i]=='W')
            {
                adj[i].push_back(N);
                adj[N].push_back(i);
                adj[N].push_back(N+1);
                adj[N].push_back(N+2);
                adj[N+1].push_back(N);
                adj[N+2].push_back(N);
                N+=3;
            }
        }
        for(i=0;i<N;i++)
        {
            if(adj[i].size()<3)
                continue;
            if(adj[i].size()>3)
                break;
            d2=0;
            for(j=0;j<3;j++)
                if(adj[adj[i][j]].size()>1)
                    d2++;
            if(d2>1)
                break;
            V.push_back(i);
        }
        if(i<N)
            cout<<"White\n";
        else if(V.size()>2)
            cout<<"White\n";
        else if(V.size()<2)
            cout<<"Draw\n";
        else
        {
            dfs(V[0],-1,false);
            if(D[V[1]])
                cout<<"Draw\n";
            else
                cout<<"White\n";
        }
        for(i=0;i<N;i++)
            adj[i].clear();
        for(i=0;i<N;i++)
            S[i]=0;
        V.clear();
    }
    cout<<endl;
    return 0;
}