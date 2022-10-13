#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <utility>
#define fr(a,b,c) for (a=b;a<=c;a++)
#define maxN 100100
using namespace std;
struct rec { int x,y,z,d; };

int n,V,turn,sum,d[maxN],mark[maxN],num[maxN],f[maxN],e[maxN];
vector < int > edge[maxN],vertex;
vector < rec > b;
vector < pair<int,long long> > re;

bool cmp(rec i,rec j)
{
    return i.z<j.z;
}

bool cmpp(pair <int,long long> i,pair <int,long long> j)
{
    return i.second>j.second || (i.second==j.second && i.first<j.first);
}

int Get(int x)
{
    if (d[x]!=x) d[x]=Get(d[x]);
    return d[x];
}

void Calc_Sum(int x,int par)
{
    int i,j,y;
    sum+=num[x];
    fr(i,0,int(edge[x].size())-1)
    {
        j=edge[x][i];
        if (Get(b[j].x)==x) y=Get(b[j].y);
        else y=Get(b[j].x);
        if (y!=par) Calc_Sum(y,x);
    }
}

void Visit(int root,int x)
{
    int i,j,y;
    e[x]=turn; f[x]=num[x]; 
    fr(i,0,int(edge[x].size())-1)
    {
        j=edge[x][i];
        if (Get(b[j].x)==x) y=Get(b[j].y);
        else y=Get(b[j].x);
        if (e[y]==turn) continue;
        Visit(root,y);
        re.push_back(make_pair(b[j].d,1LL*f[y]*(sum-f[y])));
        f[x]+=f[y];
    }
    if (x==root) return;
    d[x]=root; 
    num[root]+=num[x];
}

void Process(int l,int r)
{
    int i,x,y;
    turn++;  
    fr(i,l,r)
    {
        x=Get(b[i].x);
        y=Get(b[i].y); 
        if (mark[x]!=turn) vertex.push_back(x), mark[x]=turn;
        if (mark[y]!=turn) vertex.push_back(y), mark[y]=turn;
        edge[x].push_back(i);
        edge[y].push_back(i);
    }
    V=vertex.size();
    fr(i,0,V-1)
        if (e[vertex[i]]!=turn) 
        {
            sum=0;
            Calc_Sum(vertex[i],-1);
            Visit(vertex[i],vertex[i]); 
        }
    fr(i,0,V-1) edge[vertex[i]].clear();
    vertex.clear();
}

int main()
{
    int i,j;
    rec u;
    cin >> n;
    fr(i,1,n-1)
    {
        scanf("%d%d%d",&u.x,&u.y,&u.z);
        u.d=i;
        b.push_back(u);
    }
    sort(b.begin(),b.end(),cmp);
    fr(i,1,n) d[i]=i,num[i]=1;
    i=0;
    while (i<n-1)
    {
        j=i+1;
        while (j<n-1 && b[j].z==b[i].z) ++j;
        Process(i,j-1);
        i=j;
    }
    sort(re.begin(),re.end(),cmpp);
    fr(i,1,n-2)
        if (re[i].second<re[i-1].second) break;
    cout << re[0].second*2 << " " << i << endl;
    fr(j,0,i-1) printf("%d ",re[j].first);
    cout << endl;
    return 0;
}