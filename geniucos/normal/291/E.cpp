#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
int kk,po,i,n,m,t[100009],phi[300010];
long long sol;
char sir[300010];
struct nod
{
    char val;
    nod *urm;
};
nod *p,*q,*u,*s[100009];
vector < int > v[100009];
void dfsandkmp(int nodd,int k)
{
    int ki=k;
    nod *q;
    vector < int >::iterator it;
    for(it=v[nodd].begin();it!=v[nodd].end();it++)
    {
        if(nodd==1&&*it==4)
            sir[0]=0;
        k=ki;
        for(q=s[*it];q!=0;q=q->urm)
        {
            while(k!=0&&q->val!=sir[k+1]) k=phi[k];
            if(q->val==sir[k+1]) k++;
            if(k==m)
            {
                sol++;
                k=phi[k];
            }
        }
        dfsandkmp(*it,k);
    }
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d\n",&n);
for(i=2;i<=n;i++)
{
    gets(sir+1);
    po=1;
    while(sir[po]>='0'&&sir[po]<='9')
    {
        t[i]=t[i]*10+sir[po]-48;
        po++;
    }
    po++;
    s[i]=new nod;
    s[i]->val=sir[po];
    u=s[i];
    po++;
    while(sir[po]>='a'&&sir[po]<='z')
    {
        q=new nod;
        q->val=sir[po];
        u->urm=q;
        u=q;
        po++;
    }
    u->urm=0;
}
gets(sir+1);
m=strlen(sir+1);
kk=0;
phi[1]=0;
for(i=2;i<=m;i++)
{
    while(sir[kk+1]!=sir[i]&&kk!=0) kk=phi[kk];
    if(sir[kk+1]==sir[i]) kk++;
    phi[i]=kk;
}
for(i=2;i<=n;i++)
    v[t[i]].push_back(i);
dfsandkmp(1,0);
printf("%I64d",sol);
return 0;
}