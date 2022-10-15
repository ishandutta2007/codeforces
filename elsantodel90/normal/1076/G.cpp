#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cassert>

using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define all(c) begin(c), end(c)

#define SIZE(c) int((c).size())
#define MACRO(code) do {code} while (false)

typedef long long tint;

const int MAX_M = 5;

int m;

struct Data
{
    // A range works, by prepending to another, as a function transforming the N / P status of the first m cells
    // So for m=5
    // 0 == NNNNN
    // 1 == PNNNN
    // 2 == NPNNN
    // 3 == NNPNN
    // 4 == NNNPN
    // 5 == NNNNP

    int f[2][MAX_M+1]; // f[0] is for normal parity, f[1] is for swapped parity
    
    Data() // NEUTER, IDENTITY FUNCTION
    {
        forn(p,2)
        forn(i,m+1)
            f[p][i] = i;
    }
    
    Data(tint value)
    {
        forn(p,2)
        {
            forsn(i,1,m+1)
                f[p][i] = (i+1)%(m+1);
            f[p][0] = int((value+p) % 2);
        }
    }
    
    bool winning() const
    {
        return f[0][0] != 1;
    }
    
    void merge(const Data &left, const Data &right) // FUNCTION COMPOSITION
    {
        forn(p,2)
        forn(i,m+1)
            f[p][i] = left.f[p][right.f[p][i]];
    }
};

struct Lazy
{
    bool flipParity;
    
    Lazy() // NEUTRO
    {
        flipParity = false;
    }
   
    void updateData(Data &data) const
    {
        if (flipParity)
        forn(i,m+1)
            swap(data.f[0][i], data.f[1][i]);
    }
    
    void updateLazy(const Lazy &newLazy) // OJO! PUEDE NO CONMUTAR
    {
        flipParity ^= newLazy.flipParity;
    }
};

const int MAXN = 300000;

struct SegmentTree
{
    struct Node
    {
        Data data;
        Lazy lazy;
    };

    struct NodeIndex
    {
        int index, a,b;
        NodeIndex left() const
        {
            return {2*index, a, mid()};
        }
        
        int mid() const { return (a+b)/2;}
        
        NodeIndex right() const
        {
            return {2*index+1, mid(), b};
        }
        
        int size() const { return b-a; }
        
        bool disjoint(int queryA, int queryB) const
        {
            return a >= queryB || b <= queryA;
        }
        
        bool full(int queryA, int queryB) const
        {
            return queryA <= a && queryB >= b;
        }
    };
    
    Node st[4*MAXN];
    int size;
    
    Node* preinit(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        forn(i, 2*size)
            st[i] = Node();
        return st + size;
    }
    
    void init()
    {
        dforn(i, size)
            st[i].data.merge(st[2*i].data, st[2*i+1].data);
    }
    
    void updateNode(const NodeIndex &node, const Lazy &lazy)
    {
        st[node.index].lazy.updateLazy(lazy);
        lazy.updateData(st[node.index].data);
    }
    
    void propagate(const NodeIndex &node)
    {
        updateNode(node.left(), st[node.index].lazy);
        updateNode(node.right(), st[node.index].lazy);
        st[node.index].lazy = Lazy();
    }
    
    Data go(const NodeIndex &node, 
            int queryA, int queryB, const Lazy &lazy)
    {
        if (node.disjoint(queryA, queryB))
            return Data();
        if (node.full(queryA, queryB))
        {
            updateNode(node, lazy);
            return st[node.index].data;
        }
        propagate(node);
        int mid = node.mid();
        Data leftData, rightData;
        if (queryA < mid && queryB > mid)
        {
            leftData = go(node.left(), queryA, mid, lazy);
            rightData = go(node.right(), mid, queryB, lazy);
        }
        else
        {
            leftData = go(node.left(), queryA, queryB, lazy);
            rightData = go(node.right(), queryA, queryB, lazy);
        }
        st[node.index].data.merge(st[2*node.index].data, st[2*node.index+1].data);
        Data result;
        result.merge(leftData, rightData);
        return result;
    }
    
    NodeIndex root() const
    {
        return {1, 0, size};
    }
    
    Data update(int queryA, int queryB, const Lazy& lazy)
    {
        return go(root(), queryA, queryB, lazy);
    }
    
    Data query(int queryA, int queryB)
    {
        return update(queryA, queryB, Lazy());
    }
    
} segmentTree;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,q;
    cin >> n >> m >> q;
    auto *v = segmentTree.preinit(n);
    forn(i,n)
    {
        tint x;
        cin >> x;
        v[i].data = Data(x);
    }
    segmentTree.init();
    Lazy flip;
    flip.flipParity = true;
    forn(queryIndex, q)
    {
        int qt, l, r;
        cin >> qt >> l >> r;
        l--;
        if (qt == 1)
        {
            tint d;
            cin >> d;
            if (d % 2)
                segmentTree.update(l,r, flip);
        }
        else
        {
            cout << "21"[segmentTree.query(l,r).winning()] << "\n";
        }
    }
    return 0;
}