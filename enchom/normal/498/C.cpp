#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
using namespace std;

///Template Code

class MaxMatching
{
    /**
    Overview:

    General matching algorithm. Supports all kind of matching in bipartite graph.
    In general case it could be replaced by the standard max-flow template, but this one uses
    a weak prematching technique and is more convienient (no reverse-edge adding and no source-sink
    addin)

    Instructions:

    Call NewGraph(n) to allocate memory for the graph

    Call AddCaps(c[]) to cap all vertices. If you skip this step, standard matching is done
    and all caps = 1

    Call AddEdge(a,b,c) or AddEdge(a,b) for each edge. Reverse edges are automatically made and prematching is
    processed online.

    Call IdentifySide(a[],L) - sorted array identifying the left side of the bipartite graph.

    Call GetMatching() to get the maximum matching in the graph. A list of matched edges is also available
    in the array MatchedEdges, containing the flow sent through each edge and the edge itself, non-used
    edges excluded.

    **/

    public:

    struct Edge
    {
        int v;
        int cap,flow;
        int next;
    };

    vector<int> Used;
    vector<int> FirstSeen;
    vector<int> LastSeen;
    vector<int> VertexCap;
    int SOURCE,SINK;
    vector<Edge> EdgeList;
    int n;

    vector<int> Level;
    vector<bool> TFO;
    vector<int> LevelFirstSeen;
    vector<int> LevelLastSeen;

    vector< pair< pair<int,int> , int > > MatchedEdges;

    int MAX(int a,int b)
    {
        if (a>b)
        return a;
        else
        return b;
    }

    int MAX(int a,int b,int c)
    {
        return MAX(MAX(a,b),c);
    }

    void NewGraph(int v)
    {
        int i;

        n=v;

        EdgeList.clear();

        SOURCE=n+1;
        SINK=n+2;

        Used.resize(n+3);
        FirstSeen.resize(n+3);
        LastSeen.resize(n+3);
        LevelFirstSeen.resize(n+3);
        LevelLastSeen.resize(n+3);
        VertexCap.resize(n+3);
        Level.resize(n+3);
        TFO.resize(n+3);
        for (i=0;i<n+3;i++)
        {
            Used[i]=0;
            FirstSeen[i]=-1;
            LastSeen[i]=-1;
            LevelFirstSeen[i]=-1;
            LevelLastSeen[i]=-1;
            VertexCap[i]=1;
            Level[i]=0;
            TFO[i]=false;
        }
        VertexCap[SOURCE]=0;
        VertexCap[SINK]=0;

        return;
    }

    void AddCaps(int c[])
    {
        int i;

        for (i=1;i<=n;i++)
        {
            VertexCap[i]=c[i];
        }

        return;
    }

    void AddEdge(int a,int b,int c)
    {
        Edge help;

        help.v=b;
        help.cap=c;
        help.flow=0;
        help.next=-1;

        EdgeList.push_back(help);

        if (FirstSeen[a]==-1)
        FirstSeen[a]=(int)EdgeList.size()-1;
        else
        EdgeList[ LastSeen[a] ].next=(int)EdgeList.size()-1;

        LastSeen[a]=(int)EdgeList.size()-1;

        ///

        if (Used[a]<VertexCap[a] && Used[b]<VertexCap[b] && false)
        {
            int max_flow_send=MAX(VertexCap[a]-Used[a],VertexCap[b]-Used[b],c);

            Used[a]+=max_flow_send;
            Used[b]+=max_flow_send;
            help.flow=max_flow_send;
        }

        ///

        help.v=a;
        help.cap=0;
        help.flow=-EdgeList.back().flow;
        help.next=-1;

        EdgeList.push_back(help);

        if (FirstSeen[b]==-1)
        FirstSeen[b]=(int)EdgeList.size()-1;
        else
        EdgeList[ LastSeen[b] ].next=(int)EdgeList.size()-1;

        LastSeen[b]=(int)EdgeList.size()-1;

        return;
    }

    void AddEdge(int a,int b)
    {
        AddEdge(a,b,1);
        return;
    }

    void IdentifySide(int a[],int L)
    {
        int i;
        int uk=1;
        Edge help;

        for (i=1;i<=n;i++)
        {
            if (uk>L)
            uk=L;

            if (i==a[uk])
            {
                AddEdge(SOURCE,i,VertexCap[i]);
                EdgeList[ (int)EdgeList.size()-2 ].flow=Used[i];
                EdgeList[ (int)EdgeList.size()-1 ].flow=-Used[i];

                uk++;
            }
            else
            {
                AddEdge(i,SINK,VertexCap[i]);
                EdgeList[ (int)EdgeList.size()-2 ].flow=Used[i];
                EdgeList[ (int)EdgeList.size()-1 ].flow=-Used[i];
            }
        }

        return;
    }

    ///Flow algorithm itself

    vector< pair<Edge,int> > LevelEdgeList;

    void AddLevelEdge(int a,int b,int c,int id)
    {
        Edge h;

        h.v=b;
        h.flow=0;
        h.cap=c;
        h.next=-1;

        LevelEdgeList.push_back( make_pair(h,id) );

        if (LevelFirstSeen[a]==-1)
        LevelFirstSeen[a]=(int)LevelEdgeList.size()-1;
        else
        LevelEdgeList[ LevelLastSeen[a] ].first.next=(int)LevelEdgeList.size()-1;

        LevelLastSeen[a]=(int)LevelEdgeList.size()-1;

        return;
    }

    vector<int> q;

    bool BFS()
    {
        Edge h;
        int i;
        int uk=0;
        int v;
        bool ret=false;

        LevelEdgeList.clear();

        for (i=0;i<=n+2;i++)
        {
            Level[i]=0;
            TFO[i]=false;
            LevelFirstSeen[i]=-1;
            LevelLastSeen[i]=-1;
        }
        q.clear();

        //cout<<"Building level graph"<<endl;

        q.push_back(SOURCE);
        TFO[SOURCE]=true;
        Level[SOURCE]=0;

        while(uk<q.size())
        {
            v=q[uk];

            //cout<<"Working with "<<v<<" at level "<<Level[v]<<endl;

            if (v==SINK)
            return true;

            for (i=FirstSeen[v];i!=-1;i=EdgeList[i].next)
            {
                //cout<<"Trying kid "<<EdgeList[i].v<<endl;
                if (EdgeList[i].cap==EdgeList[i].flow)
                continue;

                if ( TFO[ EdgeList[i].v ] )
                {
                    if (Level[ EdgeList[i].v ]=Level[v]+1)
                    {
                        AddLevelEdge(v,EdgeList[i].v,EdgeList[i].cap-EdgeList[i].flow,i);
                    }
                }
                else
                {
                    TFO[ EdgeList[i].v ]=true;
                    Level[ EdgeList[i].v ]=Level[v]+1;
                    q.push_back(EdgeList[i].v);

                    AddLevelEdge(v,EdgeList[i].v,EdgeList[i].cap-EdgeList[i].flow,i);
                }
            }

            uk++;
        }

        return false;
    }

    vector<int> Path;

    void Init()
    {
        int i;

        for (i=0;i<=n+2;i++)
        {
            TFO[i]=false;
        }
        Path.clear();

        return;
    }

    bool DFS(int ver)
    {
        if (TFO[ver])
        return false;

        TFO[ver]=true;

        if (ver==SINK)
        return true;

        int i;

        for (i=LevelFirstSeen[ver];i!=-1;i=LevelEdgeList[i].first.next)
        {
            if (LevelEdgeList[i].first.flow==LevelEdgeList[i].first.cap)
            continue;

            Path.push_back(i);

            if ( DFS( LevelEdgeList[i].first.v ) )
            {
                return true;
            }

            Path.pop_back();
        }

        return false;
    }

    int MIN(int a,int b)
    {
        if (a<b)
        return a;
        else
        return b;
    }

    void UpdateEdgeList(int e,int f)
    {
        EdgeList[e].flow+=f;

        if (e%2==0)
        EdgeList[e+1].flow-=f;
        else
        EdgeList[e-1].flow-=f;

        return;
    }

    int MAXFLOW;

    void SendFlow()
    {
        int i;
        int max_flow_send=999999999;

        for (i=0;i<Path.size();i++)
        {
            max_flow_send=MIN(max_flow_send,LevelEdgeList[ Path[i] ].first.cap-LevelEdgeList[ Path[i] ].first.flow);
        }

        MAXFLOW+=max_flow_send;

        for (i=0;i<Path.size();i++)
        {
            LevelEdgeList[ Path[i] ].first.flow+=max_flow_send;

            UpdateEdgeList(LevelEdgeList[ Path[i] ].second,max_flow_send);
        }

        return;
    }

    int GetMatching()
    {
        int i,j;

        //cout<<"Getting matching"<<endl;

        while( BFS() )
        {
            //cout<<"Built level graph"<<endl;
            Init();
            while( DFS(SOURCE) )
            {
                SendFlow();
                Init();
            }
        }

        MAXFLOW=0;
        for (i=1;i<=n;i++)
        {
            for (j=FirstSeen[i];j!=-1;j=EdgeList[j].next)
            {
                if (EdgeList[j].flow>0)
                {
                    MatchedEdges.push_back(make_pair(make_pair(i,EdgeList[j].v),EdgeList[j].flow));
                }

                if (EdgeList[j].v==SINK)
                MAXFLOW+=EdgeList[j].flow;
            }
        }

        return MAXFLOW;
    }
};



MaxMatching MM;

vector<int> Primes;
bool P[1000001];

map< pair<int,int> , pair<int,int> > mymap;
map< pair<int,int> , pair<int,int> >::iterator myit;

int verctr=0;

int n,m;
int a[101];

int VCap[3001];
int Side[3001];
int L=0;

vector< pair<int,int> > Div[101];

void Break(int id)
{
    int i;
    int num=a[id];
    int ctr;

    for (i=0;i<Primes.size();i++)
    {
        if (Primes[i]*Primes[i]>a[id])
        break;

        if (num%Primes[i]==0)
        {
            num/=Primes[i];
            ctr=1;

            while(num%Primes[i]==0)
            {
                num/=Primes[i];
                ctr++;
            }

            Div[id].push_back( make_pair(Primes[i],ctr) );

            verctr++;
            VCap[verctr]=ctr;

            mymap.insert( make_pair( make_pair(id,Primes[i]) , make_pair(verctr,ctr) ) );

            if (id%2==0)
            {
                L++;
                Side[L]=verctr;
            }

            ///cout<<"Adding "<<id<<" with prime "<<Primes[i]<<" and ver="<<verctr<<" ctr="<<ctr<<endl;
        }
    }

    if (num>1)
    {
        ctr=1;
        Div[id].push_back( make_pair(num,1) );
        verctr++;
        VCap[verctr]=1;

        if (id%2==0)
        {
            L++;
            Side[L]=verctr;
        }

        mymap.insert( make_pair( make_pair(id,num) , make_pair(verctr,ctr) ) );

        ///cout<<"Adding "<<id<<" with prime "<<num<<" and ver="<<verctr<<" ctr="<<ctr<<endl;
    }

    return;
}

int MIN(int a,int b)
{
    if (a<b)
    return a;
    else
    return b;
}

void BuildEdges(int a,int b)
{
    int i;
    int cap;
    int A,B;

    for (i=0;i<Div[a].size();i++)
    {
        myit=mymap.find( make_pair(b,Div[a][i].first) );

        if (myit!=mymap.end())
        {
            cap=MIN(Div[a][i].second,(*myit).second.second);
        }
        else
        continue;

        B=(*myit).second.first;

        myit=mymap.find( make_pair(a,Div[a][i].first) );

        A=(*myit).second.first;

        if (a%2==0)
        MM.AddEdge(A,B,cap);
        else
        MM.AddEdge(B,A,cap);
    }

    return;
}

int main()
{
    int i,j;
    int A,B;

    for (i=2;i<=1000000;i++)
    {
        P[i]=true;
    }

    for (i=2;i<=1000000;i++)
    {
        if (P[i])
        {
            Primes.push_back(i);

            for (j=i+i;j<=1000000;j+=i)
            {
                P[j]=false;
            }
        }
    }

    scanf("%d %d",&n,&m);

    for (i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);

        Break(i);
    }

    MM.NewGraph(verctr);
    MM.AddCaps(VCap);

    for (i=1;i<=m;i++)
    {
        scanf("%d %d",&A,&B);

        BuildEdges(A,B);
    }

    MM.IdentifySide(Side,L);

    printf("%d\n",MM.GetMatching());

    return 0;
}