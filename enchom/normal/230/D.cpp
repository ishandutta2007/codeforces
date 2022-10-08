#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
typedef long long Int;

struct gr
{
    Int secs,ver;
};
struct hp
{
    Int ver,path;
};

vector<gr> graph[100001];
vector<Int> k[100001];
Int n,m;
hp Heap[1000001];
Int hL=0;
Int whereis[100001];

void EditHeap(Int place,Int value)
{
    Int dad,son;
    hp d;
    
    Heap[place].path=value;
    son=place;
    dad=place/2;
    
    while(dad!=0)
    {
        if (Heap[son].path<Heap[dad].path)
        {
            whereis[ Heap[son].ver ]=dad;
            whereis[ Heap[dad].ver ]=son;
            
            d=Heap[son];
            Heap[son]=Heap[dad];
            Heap[dad]=d;
            
            son=dad;
            dad=son/2;
        }
        else
        break;
    }
    return;
}

void AddToHeap(hp k)
{
    hL++;
    Heap[hL]=k;
    whereis[k.ver]=hL;
    EditHeap(hL,k.path);
}

hp GetTopHeap()
{
    hp toreturn=Heap[1];
    Int son1,son2,dad;
    hp d;
    Heap[1].path=999999999999999;
    dad=1;
    son1=dad*2;
    son2=dad*2+1;
    
    while(dad<400000)
    {
        if ( Heap[son1].path<Heap[son2].path )
        {
            if (Heap[son1].path<Heap[dad].path)
            {
                ///Switch son1 and dad
                whereis[ Heap[son1].ver ]=dad;
                whereis[ Heap[dad].ver ]=son1;
            
                d=Heap[son1];
                Heap[son1]=Heap[dad];
                Heap[dad]=d;
                
                dad=son1;
                son1=dad*2;
                son2=dad*2+1;
            }
            else
            break;
        }
        else
        {
            if (Heap[son2].path<Heap[dad].path)
            {
                ///Switch son2 and dad
                whereis[ Heap[son2].ver ]=dad;
                whereis[ Heap[dad].ver ]=son2;
                
                d=Heap[son2];
                Heap[son2]=Heap[dad];
                Heap[dad]=d;
                
                dad=son2;
                son1=dad*2;
                son2=dad*2+1;
            }
            else
            break;
        }
    }
    
    return toreturn;
}

Int DjikstraHeap()
{
    Int shortest[100001];
    bool TFO[100001];
    Int i;
    Int to1=0;
    hp top;
    hp z;
    
    for (i=0;i<=100000;i++)
    {
        shortest[i]=-1;
        TFO[i]=false;
    }
    for (i=0;i<k[1].size();i++)
    {
        if (k[1][i]==to1)
        to1++;
    }
    shortest[1]=to1;
    z.ver=1;
    z.path=to1;
    
    AddToHeap(z);
    
    for (i=2;i<=n;i++)
    {
        z.ver=i;
        z.path=999999999999999;
        AddToHeap(z);
    }
    
    for (i=1;i<=n;i++)
    {
        top=GetTopHeap();
        ///cout<<"found path for "<<top.ver<<" long "<<top.path<<endl;
        if (top.path==999999999999999)
        {
            break;
        }
        if (top.ver==n)
        {
            return top.path;
        }
        TFO[top.ver]=true;
        for (i=0;i<k[ top.ver ].size();i++)
        {
            if (k[ top.ver ][i]==top.path)
            top.path++;
        }
        shortest[top.ver]=top.path;
        
        for (i=0;i<graph[ top.ver ].size();i++)
        {
            if (TFO[ graph[top.ver][i].ver ])
            continue;
            
            if ( shortest[ top.ver ]+graph[top.ver][i].secs<shortest[ graph[top.ver][i].ver ] || shortest[ graph[top.ver][i].ver ]==-1)
            {
                shortest[ graph[top.ver][i].ver ]=shortest[top.ver]+graph[top.ver][i].secs;
                EditHeap( whereis[ graph[top.ver][i].ver ], shortest[ graph[top.ver][i].ver ] );
            }
        }
    }
    
    return shortest[n];
}

int main()
{
    Int i,j;
    Int a,b,c;
    Int p;
    gr h;
    
    for (i=0;i<=1000000;i++)
    {
        Heap[i].path=999999999999999;
    }
    
    scanf("%I64d %I64d",&n,&m);
    
    for (i=1;i<=m;i++)
    {
        scanf("%I64d %I64d %I64d",&a,&b,&c);
        h.secs=c;
        h.ver=b;
        graph[a].push_back(h);
        h.ver=a;
        graph[b].push_back(h);
    }
    for (i=1;i<=n;i++)
    {
        scanf("%I64d",&p);
        
        for (j=1;j<=p;j++)
        {
            scanf("%I64d",&a);
            k[i].push_back(a);
        }
    }
    printf("%I64d\n",DjikstraHeap());
    return 0;
}