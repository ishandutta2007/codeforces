#include <iostream>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;

struct Tree
{
    int v;
    int Len;
    int totalLen;
};

vector< pair<int,int> > Graph[300001];
bool TFO[300001];
vector<int> TheTree;
int BestDown[300001];
int BestChosen[300001];//
int BestDown2[300001];
int BestUp[300001];
Tree Trees[300001];
int tL;
int EL;
int Fv,Fd;

int MAX(int a,int b)
{
    if (a>b)
    return a;
    else
    return b;
}

int MIN(int a,int b)
{
    if (a<b)
    return a;
    else
    return b;
}

void BuildTree(int ver)
{
    int i;
    int d;

    TFO[ver]=true;
    TheTree.push_back(ver);

    for (i=0;i<Graph[ver].size();i++)
    {
        if (TFO[ Graph[ver][i].first ])
        continue;

        BuildTree( Graph[ver][i].first );

        d=Graph[ver][i].second+BestDown[ Graph[ver][i].first ];

        if (BestDown[ver]==-1)
        {
            BestDown[ver]=d;

            BestChosen[ver]=Graph[ver][i].first;
        }
        else if (BestDown[ver]<d)
        {
            BestDown2[ver]=BestDown[ver];
            BestDown[ver]=d;

            BestChosen[ver]=Graph[ver][i].first;
        }
        else if (BestDown2[ver]==-1 || BestDown2[ver]<d)
        {
            BestDown2[ver]=d;
        }
    }

    if (BestDown[ver]==-1)
    BestDown[ver]=0;
    if (BestDown2[ver]==-1)
    BestDown2[ver]=0;

    return;
}

void GetUps(int ver,int dad)
{
    int i;

    if (ver==TheTree[0])
    {
        BestUp[ver]=0;
    }

    for (i=0;i<Graph[ver].size();i++)
    {
        if (Graph[ver][i].first==dad)
        continue;

        if (BestChosen[ver]==Graph[ver][i].first)
        {
            BestUp[ Graph[ver][i].first ]=MAX(BestDown2[ver],BestUp[ver])+Graph[ver][i].second;
        }
        else
        {
            BestUp[ Graph[ver][i].first ]=MAX(BestDown[ver],BestUp[ver])+Graph[ver][i].second;
        }

        GetUps(Graph[ver][i].first,ver);
    }

    return;
}

Tree MergeTrees(Tree t1,Tree t2)
{
    Tree t12;

    t12.totalLen=MAX(t1.totalLen,t2.totalLen);
    t12.totalLen=MAX(t12.totalLen,t1.Len+t2.Len+EL);

    if (t1.Len < t2.Len)
    {
        t12.Len=MAX( t1.Len+EL , t2.Len );
        t12.v=t2.v;
    }
    else
    {
        t12.Len=MAX( t1.Len , t2.Len+EL );
        t12.v=t1.v;
    }

    return t12;
}

bool SortTrees(Tree a,Tree b)
{
    return a.Len>b.Len;
}

void Furthest(int ver,int dist)
{
    if (TFO[ver])
    return;

    if (dist>Fd)
    {
        Fv=ver;
        Fd=dist;
    }

    TFO[ver]=true;

    int i;

    for (i=0;i<Graph[ver].size();i++)
    {
        Furthest( Graph[ver][i].first,Graph[ver][i].second+dist );
    }

    return;
}

int VersTree[300001];

int travelTime(int N,int M,int L,int A[],int B[],int T[])
{
    int i,j;
    int cur;

    EL=L;

    for (i=0;i<M;i++)
    {
        Graph[ A[i]+1 ].push_back( make_pair( B[i]+1,T[i] ) );
        Graph[ B[i]+1 ].push_back( make_pair( A[i]+1,T[i] ) );
    }

    tL=0;
    memset(TFO,false,sizeof(TFO));
    memset(BestDown,-1,sizeof(BestDown));
    memset(BestDown2,-1,sizeof(BestDown2));
    memset(BestChosen,-1,sizeof(BestChosen));
    memset(BestUp,-1,sizeof(BestUp));

    for (i=1;i<=N;i++)
    {
        if (!TFO[i])
        {
            ///cout<<"Creating a new tree consisting of vertices : "<<endl;
            TheTree.clear();

            BuildTree(i);

            ///for (j=0;j<TheTree.size();j++)
            ///{
            ///    cout<<TheTree[j]<<" ";
            ///}
            ///cout<<endl;

            GetUps(i,0);

            tL++;
            Trees[tL].Len=-1;
            Trees[tL].v=-1;
            Trees[tL].totalLen=0;

            for (j=0;j<TheTree.size();j++)
            {
                VersTree[ TheTree[j] ]=tL;
                //cout<<TheTree[j]<<" is in "<<tL<<endl;

                cur=MAX( BestDown[ TheTree[j] ],BestUp[ TheTree[j] ] );

                Trees[tL].totalLen=MAX(Trees[tL].totalLen,cur);

                if (cur<Trees[tL].Len || Trees[tL].Len==-1)
                {
                    Trees[tL].Len=cur;
                    Trees[tL].v=TheTree[j];

                    ///cout<<"Vertex "<<TheTree[j]<<" is good as "<<cur<<endl;
                    ///cout<<"Having values of "<<BestDown[ TheTree[j] ]<<" and "<<BestUp[ TheTree[j] ]<<endl;
                }
            }

            ///cout<<"Tree's complexity estimated at "<<Trees[tL].Len<<endl<<endl;
        }
    }

    /*
    sort(Trees+1,Trees+1+tL,SortTrees);

    for (i=2;i<=tL;i++)
    {
        Graph[ Trees[1].v ].push_back( make_pair( Trees[i].v,L ) );
        Graph[ Trees[i].v ].push_back( make_pair( Trees[1].v,L ) );

        Trees[1]=MergeTrees(Trees[1],Trees[i]);
    }
    */

    return Trees[1].totalLen;
}

///Codeforces

int myfather[300001];

int Find(int ver)
{
    if (myfather[ver]==0)
    return ver;
    else
    {
        int dad=Find(myfather[ver]);
        myfather[ver]=dad;
        return dad;
    }
}

void Init()
{
    int i;

    for (i=1;i<=tL;i++)
    {
        myfather[i]=0;
    }

    return;
}

int GetDistance(int ver)
{
    int tree=Find( VersTree[ver] );

    return Trees[tree].totalLen;
}

void MergeTrees(int a,int b)
{
    int tree1=Find( VersTree[a] );
    int tree2=Find( VersTree[b] );

    if (tree1==tree2)
    return;

    myfather[tree2]=tree1;
    Trees[tree1]=MergeTrees(Trees[tree1],Trees[tree2]);

    //cout<<"New tree formed of total worst length = "<<Trees[tree1].totalLen<<endl;
    //cout<<"And has center "<<Trees[tree1].v<<endl<<endl;

    return;
}

///

int q;
int n,m,l;
int a[300001];
int b[300001];
int t[300001];

int main()
{
    //freopen("sample.txt","r",stdin);
    //freopen("test.txt","r",stdin);

    int i;
    int cm,A,B;

    scanf("%d %d %d",&n,&m,&q);
    l=1;

    for (i=0;i<m;i++)
    {
        scanf("%d %d",&a[i],&b[i]);
        a[i]--;
        b[i]--;

        t[i]=1;
    }

    travelTime(n,m,l,a,b,t);

    Init();

    //printf("%d\n",travelTime(n,m,l,a,b,t));

    for (i=1;i<=q;i++)
    {
        scanf("%d",&cm);

        if (cm==1)
        {
            scanf("%d",&A);
            printf("%d\n",GetDistance(A));
        }
        else
        {
            scanf("%d %d",&A,&B);
            MergeTrees(A,B);
        }
    }

    return 0;
}
/**
12 8 2
0 8 4
8 2 2
2 7 4
5 11 3
5 1 7
1 3 1
1 9 5
10 6 3
**/