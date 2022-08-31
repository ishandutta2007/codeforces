#include<bits/stdc++.h>
#define maxn 502003

using namespace std;
char s[maxn],t[maxn];
int a[maxn],b[maxn],c[maxn],d[maxn],n,m,query,l,r,x,y,u,v,p,q,mid,o1,o2;
int w1,w2,ans[maxn];

int main()
{
    scanf("%s",s); n=strlen(s);
    scanf("%s",t); m=strlen(t);
    for (int i=1;i<=n;i++)
    {
        a[i]=a[i-1]+(s[i-1]!='A');
        if (s[i-1]!='A') c[++p]=i;
    }
    for (int i=1;i<=m;i++)
    {
        b[i]=b[i-1]+(t[i-1]!='A');
        if (t[i-1]!='A') d[++q]=i;
    }
    scanf("%d",&query);
    for (int i=0;i<query;i++)
    {
        scanf("%d%d%d%d",&x,&y,&u,&v); x--; u--;
        l=-1; r=y;
        while (r-l>1)
        {
            mid=(l+r)/2;
            if (a[y]-a[mid]>0) l=mid; else r=mid;
        }
        if (l>=x) o1=(y-r); else o1=(y-x);
        l=-1; r=v;
        while (r-l>1)
        {
            mid=(l+r)/2;
            if (b[v]-b[mid]>0) l=mid; else r=mid;
        }
        if (l>=u) o2=(v-r); else o2=(v-u);
        //cout << o1 << ' ' << o2 << endl;
        w1=a[y]-a[x]; w2=b[v]-b[u];
        //cout << w1 << ' ' << w2 << endl;
        if (w1>w2||(w2-w1)%2==1) {ans[i]=0; continue;}
        if (w1==w2) {
            if (o1>=o2&&(o1-o2)%3==0) ans[i]=1; else ans[i]=0;
        }
        else {
            if (o1>o2) ans[i]=1;
            else if (o1<o2) ans[i]=0;
            else ans[i]=(o1!=y-x);
        }
    }
    for (int i=0;i<query;i++) printf("%d",ans[i]);
    printf("\n");
    return 0;
}