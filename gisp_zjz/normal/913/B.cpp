#include<bits/stdc++.h>
#define maxn 230402

using namespace std;
int a[maxn],n;
bool f;
vector <int> h[maxn];

int main()
{
    scanf("%d",&n);
    memset(a,0,sizeof(a)); f=true;
    for (int i=2;i<=n;i++)
    {
        int u;scanf("%d",&u);
        a[u]++; h[u].push_back(i);
    }
    for (int i=1;i<=n;i++)
    if (a[i]){
        int k=0;
        for (int j=0;j<h[i].size();j++)
            if (a[h[i][j]]==0) k++;
        if (k<3) f=false;
    }
    if (f) puts("YES"); else printf("NO\n");
    return 0;
}