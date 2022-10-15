#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)
#define forsn(i,s,n) for(int i=int(s);i<int(n);i++)
#define dforn(i,n) for(int i=int(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=int(s);i--)

typedef long long tint;

const int MAXN = 200100;

tint numberOfPairs[MAXN];

int vertexNumbers[MAXN];

vector<pair<int,int>> edgesByGcd[MAXN];

tint gcd(tint a,tint b) { return a == 0 ? b : gcd(b%a, a);}

int iterNumber;

struct UnionFindData
{
    int iteration;
    int parent;
    int size;
};

UnionFindData data[MAXN];

int find(int x)
{
    if (data[x].iteration != iterNumber)
    {
        data[x].iteration = iterNumber;
        data[x].parent = x;
        data[x].size = 1;
    }
    if (data[x].parent == x)
        return x;
    return data[x].parent = find(data[x].parent);
    
}

vector<int> possibleRoots;

void join(int x, int y)
{
    int rootX = find(x);
    int rootY = find(y);
    data[rootY].parent = rootX;
    data[rootX].size += data[rootY].size;
    possibleRoots.push_back(rootX);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n; cin >> n;
    forn(i,n)
        cin >> vertexNumbers[i];
    forn(edgeIndex, n-1)
    {
        int x,y;
        cin >> x >> y;
        x--; y--;
        edgesByGcd[gcd(vertexNumbers[x], vertexNumbers[y])].push_back({x,y});
    }
    
    possibleRoots.reserve(MAXN);
    
    iterNumber = 1;
    dforsn(divisor,1, MAXN)
    {
        possibleRoots.clear();
        for (int edgeGcd = divisor; edgeGcd < MAXN; edgeGcd+= divisor)
        {
            for (auto e : edgesByGcd[edgeGcd])
                join(e.first, e.second);
            numberOfPairs[divisor] -= numberOfPairs[edgeGcd];
        }
        for (int root : possibleRoots)
        if (data[root].iteration == iterNumber && data[root].parent == root)
        {
            tint k = data[root].size;
            numberOfPairs[divisor] += (k*(k-1))/2;
            data[root].iteration = -1; // Para no contar varias veces la componente
        }
        assert(numberOfPairs[divisor] >= 0);
        iterNumber++;
    }   
    
    forn(i,n)
        numberOfPairs[vertexNumbers[i]]++;
    
    forsn(i,1,MAXN)
    if (numberOfPairs[i] > 0)
        cout << i << " " << numberOfPairs[i] << "\n";
    return 0;
}