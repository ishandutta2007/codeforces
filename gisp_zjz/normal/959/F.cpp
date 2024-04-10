#include<bits/stdc++.h>
#define maxn 340000
#define M 1000000007

using namespace std;
int a[50],b[maxn],n,v,u,ans[maxn],r,s,q;
struct node{
    int x,num;
};
vector <node> h[maxn];

int insert_(int x)
{
    for (int i=20;i>=0;i--)
    {
        if (x&(1<<i)){
            if (!a[i]) return i;
            x^=a[i];
        }
    }
    return -1;
}

int main()
{
    scanf("%d%d",&n,&q); s=1;
    for (int i=1;i<=n;i++) scanf("%d",&b[i]);
    for (int i=1;i<=q;i++)
    {
        scanf("%d%d",&u,&v);
        h[u].push_back({v,i});
    }
    for (int i=1;i<=n;i++)
    {
        r=insert_(b[i]);
        if (r!=-1) {
            for (int j=20;j>r;j--) if (b[i]&(1<<j)) b[i]^=a[j];
            a[r]=b[i];
        }
        else s=s*2%M;
        for (int j=0;j<h[i].size();j++) ans[h[i][j].num]=(insert_(h[i][j].x)==-1)?s:0;
    }
    for (int i=1;i<=q;i++) cout << ans[i] << endl;
    return 0;
}