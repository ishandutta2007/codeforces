#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define N 110000
#define M 111
#define inf 0x3f3f3f3f



int height[N],rank[N],sa[N],x[N],y[N],cnt[N],data[N];

bool cmp(int *r,int a,int b,int l)
{
    return (r[a]==r[b]&&r[a+l]==r[b+l]);
}
void calheight(int n)
{
    int i,j,k=0;
    for(i=1; i<=n; i++)
        rank[sa[i]]=i;
    for(i=0; i<n; height[rank[i++]]=k)
        for(k?k--:0,j=sa[rank[i]-1]; data[i+k]==data[j+k]; k++);
}

void suffix(int n,int m)
{
    int i,l,p,*xx=x,*yy=y;
    for(i=0; i<m; i++)
        cnt[i]=0;
    for(i=0; i<n; i++)
        cnt[xx[i]=data[i]]++;
    for(i=1; i<m; i++)
        cnt[i]+=cnt[i-1];
    for(i=n-1; i>=0; i--)
        sa[--cnt[xx[i]]]=i;
    for(p=1,l=1; p<n; m=p,l*=2)
    {
        p=0;
        for(i=n-l; i<n; i++)
            yy[p++]=i;
        for(i=0; i<n; i++)
        {
            if(sa[i]>=l)
                yy[p++]=sa[i]-l;
        }
        for(i=0; i<m; i++)
            cnt[i]=0;
        for(i=0; i<n; i++)
            cnt[xx[yy[i]]]++;
        for(i=1; i<m; i++)
            cnt[i]+=cnt[i-1];
        for(i=n-1; i>=0; i--)
            sa[--cnt[xx[yy[i]]]]=yy[i];
        for(swap(xx,yy),xx[sa[0]]=0,i=1,p=1; i<n; i++)
            xx[sa[i]]=cmp(yy,sa[i-1],sa[i],l)?p-1:p++;
    }
    calheight(n-1);
}
int st[N][20];
void initrmq(int n)
{
    int i,j;
    for(i=1; i<=n; i++)
        st[i][0]=height[i];
    for(i=1; 1<<i<=n; i++)
    {
        for(j=1; j+(1<<i)-1<=n; j++)
            st[j][i]=min(st[j][i-1],st[j+(1<<(i-1))][i-1]);
    }
}
int qmin(int a,int b)
{
    int i,len=b-a+1;
    for(i=0; 1<<(i+1)<=len; i++);
    return min(st[a][i],st[b-(1<<i)+1][i]);
}
int lcp(int a,int b)
{
    int aa=rank[a],bb=rank[b];
    if(aa>bb)
        swap(aa,bb);
    aa++;
    return qmin(aa,bb);
}





vector<int>vec;
vector<int>maybe[N];
vector<int>ans;
int len[N];
int path[N];
int main()
{
    int n;
    int num;
    scanf("%d",&n);
    vec.clear();
    for(int i=0;i<n;i++)
    {
        scanf("%d",&data[i]);
        vec.push_back(data[i]);
    }
    sort(vec.begin(),vec.end());
    vec.erase(unique(vec.begin(),vec.end()),vec.end());
    num=vec.size();
    for(int i=0;i<n;i++)
        data[i]=lower_bound(vec.begin(),vec.end(),data[i])-vec.begin()+1;
    data[n+1]=0;
    suffix(n+1,num+5);
    initrmq(n);

    memset(len,inf,sizeof(len));

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<maybe[data[i]].size();j++)
        {
            int k=maybe[data[i]][j];
            if(lcp(k,i)>=i-k)
                len[k]=min(len[k],i-k);
        }
        maybe[data[i]].push_back(i);
    }

    path[n-1]=n-1;
    for(int i=n-2;i>=0;i--)
    {
        if(len[i]<=len[i+1])
        {
            path[i]=i;
        }
        else
        {
            len[i]=len[i+1];
            path[i]=path[i+1];
        }
    }

    int x=0;
    while(len[x]!=inf)
    {
        x=path[x]+len[x];
    }

    printf("%d\n",n-x);
    for(int i=x;i<n;i++)
    {
        printf("%d",vec[data[i]-1]);
        if(i==n-1)
            puts("");
        else
            printf(" ");
    }
}