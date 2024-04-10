#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<complex>
#include<queue>
#define maxn 500020

using namespace std;
typedef long long ll;

struct point{
    ll x,y;
};

bool cmp2(point u,point v)
{
    return u.x>v.x;
}

char s[maxn],t[maxn];
bool f[maxn];
ll ans,n,t1[maxn],t2[maxn],cc[maxn],x[maxn],sa[maxn],rank_[maxn],height[maxn],b[maxn],pre[maxn],sz[maxn];
ll len,h[maxn];
point a[maxn];

bool cmp(ll *y,ll a,ll b,ll k)
{
    ll a1=y[a];
    ll b1=y[b];
    ll a2=a+k>=len ? -1:y[a+k];
    ll b2=b+k>=len ? -1:y[b+k];
    return a1==b1 && a2==b2;
}

int make_sa()
{
    ll *x=t1,*y=t2;
    ll m=26;
    for(int i=0; i<m; i++) cc[i]=0;
    for(int i=0; i<len; i++) ++cc[x[i]=s[i]-'a'];
    for(int i=1; i<m; i++) cc[i]+=cc[i-1];
    for(int i=len-1; i>=0; i--) sa[--cc[x[i]]]=i;

    for(int k=1; k<=len; k<<=1)
    {
        int p=0;
        for(int i=len-k; i<len; i++) y[p++]=i;
        for(int i=0; i<len; i++)
           if( sa[i]>=k ) y[p++]=sa[i]-k;

        for(int i=0; i<m; i++) cc[i]=0;
        for(int i=0; i<len; i++) ++cc[x[y[i]]];
        for(int i=1; i<m; i++) cc[i]+=cc[i-1];
        for(int i=len-1; i>=0; i--) sa[--cc[x[y[i]]]]=y[i];

        swap(x,y);
        m=1; x[sa[0]]=0;
        for(int i=1; i<len; i++)
            x[sa[i]]=cmp(y,sa[i],sa[i-1],k) ? m-1:m++;

        if( m>=len ) break;
    }
}

void make_height()
{
    for(int i=0; i<len; i++) rank_[sa[i]]=i;
    height[0]=0;
    int k=0;
    for(int i=0; i<len; i++)
    {
        if(!rank_[i]) continue;
        int j=sa[rank_[i]-1];
        if(k) k--;
        while(s[i+k]==s[j+k]) k++;
        height[rank_[i]]=k;
    }
}

ll ffind(int x)
{
    if (pre[x]==x) return x;
    int tmp=ffind(pre[x]);
    pre[x]=tmp;
    return tmp;
}

ll sub_union(int x,int y)
{
    if (h[x]==h[y]) h[x]++;
    if (h[x]>h[y]) {pre[y]=x;sz[x]+=sz[y];return sz[x];}
    if (h[x]<h[y]) {pre[x]=y;sz[y]+=sz[x];return sz[y];}
}

int main()
{
    scanf("%d",&len);
    scanf("%s",t);
    for (int i=0;i<len;i++) s[i]=t[len-1-i];
    scanf("%s",t);
    for (int i=0;i<len;i++) f[i]=(t[len-1-i]=='0');
    ans=0;n=0;
    for (int i=0;i<len;i++) if (t[i]=='0') ans=i+1;
    make_sa();
    make_height();
    int j=0; while (j<len&&!f[sa[j]]) j++;
    for (int i=j;i<len;i++)
    {
        ll k=height[++j];
        while (j<len&&!f[sa[j]]){
            k=min(k,height[++j]);
        }
        i=j;
        a[++n].x=k;
    }
    //printf("%d\n",n);
    for (int i=1;i<=n;i++) a[i].y=i;
    sort(a+1,a+n+1,cmp2);
    for (int i=1;i<=n+1;i++) pre[i]=i,sz[i]=1,h[i]=1;
    for (int i=1;i<=n;i++)
    {
        ll u=ffind(a[i].y);
        ll v=ffind(a[i].y+1);
        ll w=sub_union(u,v);
        ans=max(ans,w*a[i].x);
    }
    printf("%I64d\n",ans);
    //for(int i=0;i<len;i++) cout << i; cout << endl;
    //for(int i=0;i<len;i++) cout<<rank_[i] << " "; cout << endl;
    //for(int i=0;i<len;i++) cout<<height[i];
    return 0;
}