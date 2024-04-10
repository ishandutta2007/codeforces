#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#define N 100010
#define B1 344
#define B 623
#define ll long long
using namespace std;
int a[N],n;
int cnt[N],sum[N],tmp[B+3];
int tn[N],ql[N],qt;
ll ans;
priority_queue<int,vector<int>,greater<int> >qu;
void ins(int x,int v){ans+=x*v;if(x>B) while(v--) qu.push(x);else tmp[x]+=v;}
ll work()
{
    ans=0;
    for(int i=1;i<=qt;i++) if(cnt[ql[i]]>B) qu.push(cnt[ql[i]]);
    for(int i=1;i<=B;i++) tmp[i]=sum[i];
    int pre=0;
    for(int i=1;i<=B;i++)
    if(tmp[i])
    {
        if(pre) ins(i+pre,1),tmp[i]--,pre=0;
        ins(i*2,tmp[i]/2);
        if(tmp[i]&1) pre=i;
    }
    if(pre) qu.push(pre);
    int x=0,y=0;
    while(!qu.empty())
    {
        x=qu.top();qu.pop();
        if(qu.empty()) break;
        y=qu.top(),qu.pop(); qu.push(x+y);
        ans+=x+y;
    }
    return ans;
}
int bl[N];
struct ques{
    int l,r,id;
    bool operator <(const ques a)const{return bl[l]==bl[a.l]?r<a.r:bl[l]<bl[a.l];}
}q[N];
void add(int x){if(cnt[a[x]]>=0)sum[cnt[a[x]]]--;cnt[a[x]]++;if(cnt[a[x]]>=0)sum[cnt[a[x]]]++;}
void del(int x){if(cnt[a[x]]>=0)sum[cnt[a[x]]]--;cnt[a[x]]--;if(cnt[a[x]]>=0)sum[cnt[a[x]]]++;}
ll res[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),tn[a[i]]++,bl[i]=i/B1;
    for(int i=1;i<=100000;i++)
    if(tn[i]>B) ql[++qt]=i;
    int m;
    scanf("%d",&m);
    for(int i=1;i<=m;i++) scanf("%d%d",&q[i].l,&q[i].r),q[i].id=i;
    sort(q+1,q+m+1);
    int l=1,r=0;sum[0]=n;
    for(int i=1;i<=m;i++)
    {
        while(r<q[i].r) add(++r);
        while(r>q[i].r) del(r--);
        while(l<q[i].l) del(l++);
        while(l>q[i].l) add(--l);
        res[q[i].id]=work();
    }
    for(int i=1;i<=m;i++) printf("%lld\n",res[i]);
    return 0;
}