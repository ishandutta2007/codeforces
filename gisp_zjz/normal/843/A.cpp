#include<bits/stdc++.h>
#define maxn 102030

using namespace std;
map <int,int> f;
int a[maxn],b[maxn],c[maxn],d[maxn],n,k;
vector <int> h[maxn];
bool vis[maxn];

void dfs(int x)
{
    vis[x]=true;
    h[k].push_back(x+1);
    if (!vis[c[x]]) dfs(c[x]);
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++){scanf("%d",&a[i]);b[i]=a[i];}
    sort(a,a+n);
    for (int i=0;i<n;i++) f[b[i]]=i;
    for (int i=0;i<n;i++) c[i]=f[a[i]];
    for (int i=0;i<n;i++) if (!vis[i]) dfs(i),k++;
    cout << k << endl;
    for (int i=0;i<k;i++)
    {
        cout << h[i].size() << ' ' ;
        for (int j=0;j<h[i].size();j++) cout << h[i][j] << ' ';
        cout << endl;
    }
    return 0;
}