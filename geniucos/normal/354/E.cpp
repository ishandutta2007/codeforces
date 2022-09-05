#include<queue>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
int i,T,mod;
long long cat,S;
struct str{long long obt,hw[6];}acr,rez,ret;
vector < str > v[666013];
vector < str > sum[10];
int key(long long cat)
{int lin=((long long)cat^3128358+cat-435872-cat^4747472)%mod;if(lin<0) lin+=mod;return lin;}
int exist(long long cat)
{
    int lin=key(cat);
    vector < str > :: iterator it;
    for(it=v[lin].begin();it!=v[lin].end();it++)
        if(it->obt==cat)
        {
            acr=*it;
            return 1;
        }
    return -1;
}
void back(int poz)
{
    if(poz==6)
    {
        acr.obt=S;
        sum[S%10].push_back(acr);
        return ;
    }
    acr.hw[poz]=0;
    back(poz+1);
    S+=4;
    acr.hw[poz]=4;
    back(poz+1);
    S-=4;
    S+=7;
    acr.hw[poz]=7;
    back(poz+1);
    S-=7;
}
str calc(long long cat)
{
    int i,ceva;
    vector < str > :: iterator it;
    if(exist(cat)==1) return acr;
    if(cat==0)
    {
        for(i=0;i<6;i++)
            acr.hw[i]=0;
        acr.obt=0;
        i=key(cat);
        v[i].push_back(acr);
        return acr;
    }
    for(it=sum[cat%10].begin();it!=sum[cat%10].end();it++)
        if(cat>=it->obt)
        {
            acr=calc((cat-it->obt)/10);
            ret=*it;
            if(acr.hw[0]!=-1)
            {
                for(i=0;i<6;i++)
                    acr.hw[i]=1LL*acr.hw[i]*10+it->hw[i];
                acr.obt=cat;
                i=key(cat);
                v[i].push_back(acr);
                return acr;
            }
        }
    i=key(cat);
    acr.obt=cat;
    acr.hw[0]=-1;
    v[i].push_back(acr);
    return acr;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&T);mod=666013;
back(0);
while(T)
{
    T--;
    scanf("%I64d\n",&cat);
    rez=calc(cat);
    if(rez.hw[0]==-1)
    {
        printf("-1\n");
        continue;
    }
    for(i=0;i<6;i++)
        printf("%I64d ",rez.hw[i]);
    printf("\n");
}
return 0;
}