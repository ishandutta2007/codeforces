#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int kk,nrr,nok,ad,nr,po,st,dr,i,j,k,n,t,l[13],mi[13],ma[13],phi[50009];
long long cnt;
char sir[50009],a[13][50009],b[50009],ss[50050];
vector < pair < int , int > > ::iterator it;
vector < pair < int , int > > aux,v[12];
struct nod
{
    nod *urm[26];
    nod()
    {
        memset(urm,0,sizeof(urm));
    }
};
nod *tt,*q;
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
gets(sir+1);
n=strlen(sir+1);
scanf("%d\n",&t);
tt=new nod;
for(i=1;i<=t;i++)
{
    gets(ss+1);
    l[i]=0;
    po=1;
    while(ss[po]!=' ')
    {
        l[i]++;
        a[i][l[i]]=ss[po];
        po++;
    }
    po++;
    while(ss[po]!=' ')
    {
        mi[i]=mi[i]*10+ss[po]-48;
        po++;
    }
    po++;
    while(ss[po]>='0'&&ss[po]<='9')
    {
        ma[i]=ma[i]*10+ss[po]-48;
        po++;
    }
}
for(st=1;st<=n;st++)
{
    nr=0;
    q=tt;
    for(dr=st;dr<=n;dr++)
    {
        nr++;
        b[nr]=sir[dr];
        if(nr==1)
        {
            phi[1]=0;
            kk=0;
        }
        else
        {
            while(b[nr]!=b[kk+1]&&kk!=0) kk=phi[kk];
            if(b[nr]==b[kk+1]) kk++;
            phi[nr]=kk;
        }
        if(q->urm[b[nr]-'a']!=0) ad=0;
        else
        {
            q->urm[b[nr]-'a']=new nod;
            ad=1;
        }
        q=q->urm[b[nr]-'a'];
        if(nr==1)
        {
            nok=0;
            for(i=1;i<=t;i++)
            {
                v[i].clear();
                for(j=1;j<=l[i];j++)
                    if(a[i][j]==b[nr]) v[i].push_back(make_pair(j,1));
                if(v[i].size()<mi[i]) break;
                if(v[i].size()>=mi[i]&&v[i].size()<=ma[i]) nok++;
            }
            if(i<=t) break;
            if(nok==t) cnt+=ad;
        }
        else
        {
            nok=0;
            for(i=1;i<=t;i++)
            {
                aux.clear();
                nrr=0;
                for(it=v[i].begin();it!=v[i].end();it++)
                {
                    j=it->first+1;
                    if(j>l[i]) continue;
                    k=it->second;
                    while(a[i][j]!=b[k+1]&&k!=0) k=phi[k];
                    if(a[i][j]==b[k+1]) k++;
                    aux.push_back(make_pair(j,k));
                    if(k==nr) nrr++;
                }
                if(nrr>=mi[i]&&nrr<=ma[i]) nok++;
                if(nrr<mi[i]) break;
                v[i].clear();
                v[i]=aux;
            }
            if(i<=t) break;
            if(nok==t) cnt+=ad;
          //  if(cnt==2)
            //    i=i;
        }
    }
}
printf("%I64d\n",cnt);
return 0;
}