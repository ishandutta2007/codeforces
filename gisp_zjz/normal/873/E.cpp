#include<bits/stdc++.h>
#define maxn 200020
#define x first
#define y second

using namespace std;
pair <int,int> a[maxn];
int n,d[4],c[maxn],l,r,s,k,b[maxn],ans[maxn];
vector <pair<int,int> > p;

bool cmp(pair<int,int> u,pair<int,int> v)
{
    return u.x>v.x;
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i].x);
    for (int i=0;i<n;i++) a[i].y=i;
    sort(a,a+n,cmp);p.clear();a[n].x=0;
    d[1]=d[2]=d[3]=0;
    for (int i=1;i<=n;i++) c[i]=a[i-1].x-a[i].x;
    for (int i=1;i<=n;i++)
        for (int j=i+(i+1)/2;j<=min(n,i*3);j++){
            l=j+(max(i,j-i)+1)/2;
            if (l>n) continue;
            if (c[i]>d[1]||c[i]==d[1]&&c[j]>d[2]){
                p.clear();p.push_back({i,j});d[1]=c[i];d[2]=c[j];
            }
            else if (d[1]==c[i]&&d[2]==c[j]) p.push_back({i,j});
        }
    memset(b,0,sizeof(b));s=0;
    for (int i=0;i<p.size();i++)
    {
        l=p[i].y+(max(p[i].x,p[i].y-p[i].x)+1)/2;
        r=p[i].y+(min(p[i].x,p[i].y-p[i].x)*2);
        if (l<=n) b[l]++,b[r+1]--;
    }
    c[n+1]=-1;
    k=n+1;
    for (int i=1;i<=n;i++)
    {
        s+=b[i];
        if (s&&c[i]>c[k]) k=i;
    }
    for (int i=0;i<p.size();i++)
    {
        l=p[i].y+(max(p[i].x,p[i].y-p[i].x)+1)/2;
        r=p[i].y+(min(p[i].x,p[i].y-p[i].x)*2);
        if (l<=n&&k>=l&&k<=r) d[1]=p[i].x,d[2]=p[i].y,d[3]=k;
    }
    for (int i=0;i<d[1];i++) ans[a[i].y]=1;
    for (int i=d[1];i<d[2];i++) ans[a[i].y]=2;
    for (int i=d[2];i<d[3];i++) ans[a[i].y]=3;
    for (int i=d[3];i<n;i++) ans[a[i].y]=-1;
    for (int i=0;i<n;i++) printf("%d ",ans[i]); printf("\n");
    return 0;
}