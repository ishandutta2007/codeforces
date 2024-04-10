#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=505000;
bool f;
char s[maxn];
int query,a[10],b[maxn],n,k,ans[maxn],d,c,j;

bool check(int x)
{
    if (b[n-x]==0) return false;
    for (int i=0;i<10;i++) a[i]=0;
    for (int i=0;i<n-x;i++) ans[i]=b[i],a[b[i]]^=1;
    for (int i=n-x;i<n;i++) ans[i]=-1;
    c=0; for (int i=0;i<10;i++) c+=a[i];
    if (c>x) return false;
    if (c==x){
        for (int i=0;i<b[n-x];i++) if (a[i]) ans[n-x]=i;
        if (ans[n-x]==-1) return false; a[ans[n-x]]^=1;
        for (int i=n-x+1;i<n;i++)
        {
            for (int j=0;j<10;j++) if (a[j]) ans[i]=j;
            a[ans[i]]^=1;
        }
        return true;
    }
    else{
        ans[n-x]=b[n-x]-1; a[ans[n-x]]^=1;
        c=0; for (int i=0;i<10;i++) c+=a[i];
        for (int i=n-x+1;i<n-c;i++) ans[i]=9;
        for (int i=n-c;i<n;i++)
        {
            for (int j=0;j<10;j++) if (a[j]) ans[i]=j;
            a[ans[i]]^=1;
        }
        return true;
    }
}

void solve()
{
    scanf("%s",s); n=strlen(s);
    if (n%2) {
        for (int i=0;i<n/2;i++) printf("99"); printf("\n"); return ;
    }
    f=true;
    for (int i=0;i<n;i++) b[i]=s[i]-'0';
    if (b[0]>1) f=false;
    for (int i=1;i<n-1;i++) if (b[i]) f=false;
    if (b[n-1]>1) f=false;
    if (f) {
        for (int i=1;i<n/2;i++) printf("99"); printf("\n"); return ;
    }
    j=1; while (!check(j)) j++;
    for (int i=0;i<n;i++) printf("%d",ans[i]);
    printf("\n");
}

int main()
{
    scanf("%d",&query);
    while (query--)
    {
        solve();
    }
}