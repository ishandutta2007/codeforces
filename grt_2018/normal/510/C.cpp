#include <bits/stdc++.h>

using namespace std;

#define FOR(i,b,e) for( __typeof(b) i = (b) - ((b)>(e)); i!=(e) - ((b)>(e)); i+=1 - 2 * ((b)>(e)))
#define PB push_back

const int MAXN = 101;
int n;
vector<int>V[27];
char s[MAXN][MAXN];
bool visited[27];
bool active[27];
int nr=25;
int t[27];

void dfs(int x)
{
    visited[x]=1;
    for(auto i: V[x])
    {
        if(!visited[i])
            dfs(i);
    }
    t[nr--]=x;
}
bool c=0;
void cycle(int x)
{
    visited[x]=1;
    active[x]=1;
    for(auto i: V[x])
    {
        if(!visited[i])
        {
            cycle(i);
        }
        else if(active[i])
            c=1;
    }
    active[x]=0;
}

int main()
{
    cin>>n;
    FOR(i,0,n) {
        cin>>s[i];
        if(i>0)
        {
            int p1=0;
            while(s[i][p1]==s[i-1][p1])
            {
                if(s[i][p1]==' ') break;
                p1++;
            }
            if(!s[i][p1]&&s[i-1][p1]!=' ')
            {
                cout<<"Impossible"; return 0;
            }
            else if(s[i][p1]&&s[i-1][p1])
            {
                V[(int)s[i-1][p1]-97].PB((int)s[i][p1]-97);
            }
        }
    }
    FOR(i,0,26)
        if(!visited[i])
            cycle(i);
    if(c) {cout<<"Impossible"; return 0;}
    FOR(i,0,26)
        visited[i]=0;
    FOR(i,0,26)
        if(!visited[i])
            dfs(i);
    FOR(i,0,26)
        cout<<(char)(t[i]+97);
    return 0;
}