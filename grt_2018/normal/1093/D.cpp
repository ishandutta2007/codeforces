#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = 300001;
const int mod = 998244353;

int t,n,m;
int ile,qwe;
vector<int>V[MAXN];
bool visited[MAXN];
bool state[MAXN];
long long power[MAXN];

bool oddcycle;

void dfs(int x, bool s)
{
    visited[x]=1;
    state[x]=s;
    qwe++;
    if(s) ile++;
    for(int i=0; i<V[x].size();i++)
    {
        if(!visited[V[x][i]])
            dfs(V[x][i],!s);
        if(visited[V[x][i]]&&state[V[x][i]]==state[x])
            oddcycle=1;
    }
}

int main()
{
    cin>>t;
    power[0]=1;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1; i<=n;i++)
            power[i]=(power[i-1]*2)%mod;
        long long w=1;
        for(int i=1; i<=n;i++)
        {
            V[i].clear();
            visited[i]=0;
        }
        int a,b;
        for(int i=0; i<m;i++)
        {
            cin>>a>>b;
            V[a].push_back(b);
            V[b].push_back(a);
        }
        bool ok=1;
        for(int i=1;i<=n;i++)
        {
            if(!visited[i])
            {
                ile=0; qwe=0; oddcycle=0;
                dfs(i,1);
                if(oddcycle){cout<<"0\n"; ok=0; break;}
                else
                {
                    long long pom = (power[ile] + power[qwe-ile])%mod;
                    w=(w*pom)%mod;
                }
            }
        }
        if(ok)
        {
            cout<<w<<"\n";
        }
    }
    return 0;
}