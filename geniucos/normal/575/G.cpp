#include <cstdio>
#include <queue>

using namespace std;

struct str
{
    int nod,c;
    str(int nod1=0,int c1=0) {nod=nod1;c=c1;}
};
vector<str> v[100010];
queue<int> q;
pair<int,int> tata[100010],sol[100010];
int v1[100010],d[100010],d1[100010];
char vaz[100010];

int main()
{
    //freopen("file.in", "r", stdin);
    //freopen("file.out", "w", stdout);
    int n,m,nr=0,x,y,c;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&c);x++;y++;
        v[x].push_back(str(y,c));
        v[y].push_back(str(x,c));
    }
    d[1]=0;
    vaz[1]=1;
    q.push(1);
    while(!q.empty())
    {
        int nod=q.front();q.pop();
        for(vector<str>::iterator it=v[nod].begin();it!=v[nod].end();it++)
            if(!vaz[it->nod])
            {
                d[it->nod]=d[nod]+1;
                vaz[it->nod]=1;
                q.push(it->nod);
            }
    }
    for(int i=1;i<=n;i++) vaz[i]=0;
    q.push(n);
    vaz[n]=1;
    d1[n]=0;
    while(!q.empty())
    {
        int nod=q.front();q.pop();
        for(vector<str>::iterator it=v[nod].begin();it!=v[nod].end();it++)
            if(!vaz[it->nod] && it->c==0)
            {
                d1[it->nod]=d1[nod]+1;
                vaz[it->nod]=1;
                tata[it->nod]={nod,0};
                q.push(it->nod);
            }
    }
    int minn=1000000000;
    for(int i=1;i<=n;i++)
        if(vaz[i]) minn=min(minn,d[i]);
    for(int i=1;i<=n;i++)
        if(vaz[i] && d[i]==minn) v1[++nr]=i;
    x=1;y=nr;
    while(x<=y)
    {
        int minn=10;
        for(int i=x;i<=y;i++)
            for(vector<str>::iterator it=v[v1[i]].begin();it!=v[v1[i]].end();it++)
                if(d[it->nod]==d[v1[i]]-1) minn=min(minn,it->c);
        for(int i=x;i<=y;i++)
            for(vector<str>::iterator it=v[v1[i]].begin();it!=v[v1[i]].end();it++)
                if(d[it->nod]==d[v1[i]]-1 && it->c==minn)
                    if(!vaz[it->nod])
                    {
                        d1[it->nod]=d1[v1[i]]+1;
                        tata[it->nod]={v1[i],minn};
                        v1[++nr]=it->nod;
                        vaz[it->nod]=1;
                    }
                    else if(d1[it->nod]>d1[v1[i]]+1)
                    {
                        d1[it->nod]=d1[v1[i]]+1;
                        tata[it->nod]={v1[i],minn};
                    }
        x=y+1;
        y=nr;
    }
    nr=0;
    for(int i=1;i!=n;i=tata[i].first) sol[++nr]={i,tata[i].second};
    int i=nr;
    for(;i>1 && sol[i].second==0;i--);
    for(;i;i--) printf("%d",sol[i].second);
    sol[++nr]={n,0};
    printf("\n%d\n",nr);
    for(int i=1;i<=nr;i++) printf("%d ",sol[i].first-1);
    return 0;
}