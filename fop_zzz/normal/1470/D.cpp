#include<bits/stdc++.h>
#define For(i,j,k)  for(int i=j;i<=k;++i)
#define Dow(i,j,k)  for(int i=k;i>=j;--i)
#define ll long long
#define pb push_back
#define fir first
#define sec second
#define pb push_back
#define pa pair<int,int>
#define mk make_pair
 
using namespace std;
 
inline ll read()
{
    ll t=0,dp=1;char c=getchar();
    while(!isdigit(c))  {if(c=='-') dp=-1;c=getchar();}
    while(isdigit(c))   t=t*10+c-48,c=getchar();
    return t*dp;
}
inline void write(ll x){if(x<0)  {putchar('-');x=-x;}    if(x>=10)    write(x/10);putchar(x%10+48);}
inline void writeln(ll x){write(x);puts("");}
inline void write_p(ll x){write(x);putchar(' ');}

vector<int> E[500010];
int Ans[500010],ans_num,vis[500010], colv[500010],ans[500005];
int n,m;
inline void Dfs(int u, int col)
{
     vis[u] = 1;
     for (auto v : E[u]) 
          if (vis[v] && colv[v] == 1) col=0;
     colv[u] = col;
     if (col==1) {ans[++ans_num]=u;}
     for (auto v : E[u])
          if (!vis[v]) Dfs(v, col ^ 1);
}

int main(){
    int T=read();
    while(T--)
    {
        n=read();m=read();
        For(i,1,n)  E[i].clear();
        For(i,1,n)  vis[i]=colv[i]=0;
        ans_num=0;
        For(i,1,m)
        {
            int u=read(),v=read();
            E[u].pb(v);E[v].pb(u);
        }
        Dfs(1, 1);
        bool win = 1;
        For(i,1,n)  if(!vis[i]) win=0;
        if (!win) puts("NO");
         else{
              puts("YES");
              writeln(ans_num);
              For(i,1,ans_num) write_p(ans[i]);
              puts("");
         }
    }
}