#include<iostream>
#include<cstdio>
#include<cstring>
#define N 200010
#define D 23
using namespace std;
int n,_2[N];
struct sa{
    char s[N];
    int rk[N],sa[N],id[N],b[N];
    int mn[N][D];
    bool opt;
    void sa_sort(int m)
    {
        for(int i=1;i<=m;i++) b[i]=0;
        for(int i=1;i<=n;i++) b[rk[i]]++;
        for(int i=1;i<=m;i++) b[i]+=b[i-1];
        for(int i=n;i;i--) sa[b[rk[id[i]]]--]=id[i];
    }
    void init(bool op)
    {
        int m=26;opt=op;
        for(int i=1;i<=n;i++) rk[i]=s[i]-'A'+1,id[i]=i;
        sa_sort(m);
        for(int p=1,t=0;p<n;p<<=1,m=t,t=0)
        {
            for(int i=1;i<=p;i++) id[++t]=n-p+i;
            for(int i=1;i<=n;i++)
            if(sa[i]>p) id[++t]=sa[i]-p;
            sa_sort(m);swap(rk,id);rk[sa[1]]=t=1;
            for(int i=2;i<=n;i++)
            rk[sa[i]]=(t+=id[sa[i]]!=id[sa[i-1]] || id[sa[i]+p]!=id[sa[i-1]+p]);
        }
        if(op)
        {
            for(int i=1;i<=n;i++) mn[i][0]=sa[i];
            for(int k=1;k<=_2[n];k++)
                for(int i=1;i+(1<<k)-1<=n;i++)
                mn[i][k]=min(mn[i][k-1],mn[i+(1<<(k-1))][k-1]);
        }
        else
        {
            for(int i=1;i<=n;i++) mn[i][0]=n-sa[i]+1;
            for(int k=1;k<=_2[n];k++)
                for(int i=1;i+(1<<k)<=n;i++)
                mn[i][k]=max(mn[i][k-1],mn[i+(1<<(k-1))][k-1]);
        }
    }
    int get(int l,int r){int k=_2[r-l+1];return opt?min(mn[l][k],mn[r-(1<<k)+1][k]):max(mn[l][k],mn[r-(1<<k)+1][k]);}
    int lower_bound(int l,int r,int len,char c)//the first one >= c
    {
        int res=r+1;
        while(l<=r)
        {
            int mid=(l+r)>>1,p=sa[mid]+len-1;
            if(p<=n && s[p]>=c) r=mid-1,res=mid;
            else l=mid+1;
        }
        return res;
    }
}s1,s2;
int pre[N],suf[N];
char s[N],rs[N];
int main()
{
    scanf("%s",s1.s+1);
    n=strlen(s1.s+1);
    for(int i=2;i<=n;i++) _2[i]=_2[i>>1]+1;
    for(int i=1;i<=n;i++) s2.s[n-i+1]=s1.s[i];
    s1.init(1);s2.init(0);
    int q,ans=0;
    scanf("%d",&q);
    while(q --> 0)
    {
        scanf("%s",s+1);
        int m=strlen(s+1);
        for(int i=1;i<=m;i++) pre[i]=suf[i]=-1;
        for(int i=1;i<=m;i++) rs[m-i+1]=s[i];
        int l=1,r=n;
        for(int i=1;i<=m;i++)
        {
            r=s1.lower_bound(l,r,i,s[i]+1)-1;
            l=s1.lower_bound(l,r,i,s[i]);
            if(l>r || l<0) break;
            pre[i]=s1.get(l,r);
        }
        l=1,r=n;
        for(int i=1;i<=m;i++)
        {
            r=s2.lower_bound(l,r,i,rs[i]+1)-1;
            l=s2.lower_bound(l,r,i,rs[i]);
            if(l>r) break;
            suf[i]=s2.get(l,r);
        }
        for(int i=1;i<=m;i++)
            if(suf[m-i]!=-1 && pre[i]!=-1)
            if(suf[m-i]-pre[i]+1>=m){ans++;break;}
    }
    printf("%d\n",ans);
    return 0;
}