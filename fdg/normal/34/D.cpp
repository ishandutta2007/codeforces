#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long

using namespace std;

int gcd(int a,int b) {return (b==0) ? a : gcd(b,a%b);}
int lcm(int a,int b) {return a/gcd(a,b)*b;}

vector < vector <int> > g;
vector <int> ans;

bool used[50002]={0};

void dfs(int cur,int last = 0)
{
    used[cur]=true; ans[cur]=last;
    for(int i=0;i<g[cur].size();i++)
        if (!used[g[cur][i]]) dfs(g[cur][i],cur);
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,r1,r2,a;
    scanf("%d%d%d",&n,&r1,&r2);
    r1--; r2--;
    g.resize(n);
    for(int i=0;i<n-1;i++)
    {
        scanf("%d",&a);
        if (i>=r1)
        {
            g[i+1].push_back(a-1);
            g[a-1].push_back(i+1);
        }
        else
        {
            g[i].push_back(a-1);
            g[a-1].push_back(i);
        }
    }
    ans.resize(n,0);
    dfs(r2);
    bool first=true;
    for(int i=0;i<n;i++)
    {
        if (i==r2) continue;
        if (first) printf("%d",ans[i]+1);
        else printf(" %d",ans[i]+1);
        first=false;
    }
    printf("\n");
    return 0;
}