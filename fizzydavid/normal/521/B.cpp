//while(true)rp++;
#include<bits/stdc++.h>
using namespace std;
#define debug(x) cerr<<#x<<"="<<x<<endl;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
#define input1(x) x=getval()
#define input2(x,y) x=getval(),y=getval()
#define input3(x,y,z) x=getval(),y=getval(),z=getval()
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
const ll mod=1e9+9;
inline int getval()
{
    int __res=0;bool __neg=0;
    char __c;__c=getchar();
    while(__c==' '||__c=='\n')__c=getchar();
    while(__c!=' '&&__c!='\n')
    {
        if(__c=='-')__neg=1;
        else __res=__res*10+__c-'0';
        __c=getchar();
    }
    if(__neg)__res=-__res;
    return __res;
}
set<int>s;
int m;
bool used[100111],imp[100111];
int cntup[100111],cntdown[100111];
pair<int,int>p[100111];
map<pair<int,int>,int>pos;
void update1(int t)
{
    imp[t]=0;
    for(int i=-1;i<=1;i++)
    {
        int y=pos[MP(p[t].FF+i,p[t].SS+1)];
        if(y!=0&&!used[y]&&cntdown[y]==1)
        {
            imp[t]=1;
            if(s.find(t)!=s.end())s.erase(t);
            return;
        }
    }
    if(!imp[t])s.insert(t);
}
void update2(int t)
{
    for(int i=-1;i<=1;i++)
    {
        int y=pos[MP(p[t].FF+i,p[t].SS-1)];
        if(y!=0&&!used[y])
        {
            imp[y]=1;
            if(s.find(y)!=s.end())s.erase(y);
            break;
        }
    }
}
void remove(int t)
{
    used[t]=1;
    for(int i=-1;i<=1;i++)
    {
        int y=pos[MP(p[t].FF+i,p[t].SS-1)];
        if(y!=0&&!used[y])
        {
            cntup[y]--;
            update1(y);
        }
    }
    for(int i=-1;i<=1;i++)
    {
        int y=pos[MP(p[t].FF+i,p[t].SS+1)];
        if(y!=0&&!used[y])
        {
            cntdown[y]--;
            if(cntdown[y]==1)update2(y);
        }
    }
}
int main()
{
    input1(m);
    for(int i=1;i<=m;i++)
    {
        input2(p[i].FF,p[i].SS);
        pos[p[i]]=i;
    }
    for(int x=1;x<=m;x++)
    {
        for(int i=-1;i<=1;i++)
        {
            int y=pos[MP(p[x].FF+i,p[x].SS+1)];
            if(y!=0)cntup[x]++,cntdown[y]++;
        }
    }
    for(int x=1;x<=m;x++)
    {
//      cout<<cntup[x]<<" "<<cntdown[x]<<endl;
        for(int i=-1;i<=1;i++)
        {
            int y=pos[MP(p[x].FF+i,p[x].SS+1)];
            if(cntdown[y]==1)imp[x]=1;
        }
        if(!imp[x])s.insert(x);
    }
    ll ans=0;
    for(int i=1;i<=m;i++)
    {
        int t;
        if(i&1)t=*(--s.end()),s.erase(--s.end());else t=*s.begin(),s.erase(s.begin());
//      cout<<t<<endl;
        ans=(ans*m+t-1)%mod;
        remove(t);
    }
    printf("%I64d\n",ans);
    return 0;
}
/*
8
1 1
2 2
3 1
2 0
0 2
4 2
4 0
0 0
*/