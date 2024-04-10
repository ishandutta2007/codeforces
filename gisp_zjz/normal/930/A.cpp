#include<bits/stdc++.h>
#define maxn 100020

using namespace std;
vector <int> h[maxn];
int n,a[maxn],ans,c[maxn];

void dfs(int x,int fa,int d)
{
    c[d]^=1;
    for (int i=0;i<h[x].size();i++)
    {
        int y=h[x][i];
        if (y!=fa) dfs(y,x,d+1);
    }
}

int main()
{
    scanf("%d",&n);
    for (int i=2;i<=n;i++)
    {
        int k; scanf("%d",&k);
        h[k].push_back(i);
    }
    dfs(1,0,0);
    for (int i=0;i<n;i++) ans+=c[i];
    cout << ans << endl;
}