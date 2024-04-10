#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cassert>

using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)

const int MAXN = 200000;

typedef long long tint;

int profundidad[MAXN], ordenDFS[MAXN], tamSubarbol[MAXN], padre[MAXN];
tint distancia[MAXN];
int cabeza[MAXN];
bool activo[MAXN];

vector<pair<int, int>> g[MAXN];

int dfsTimeStamp = 0;

void dfsPrecomputos(int nodo)
{
    ordenDFS[nodo] = dfsTimeStamp++;
    tamSubarbol[nodo] = 1;
    for (pair<int,int> par : g[nodo])
    {
        int hijo = par.first;
        if (hijo != padre[nodo])
        {
            profundidad[hijo] = profundidad[nodo] + 1;
            distancia[hijo] = distancia[nodo] + par.second;
            padre[hijo] = nodo;
            dfsPrecomputos(hijo);
            tamSubarbol[nodo] += tamSubarbol[hijo];
        }
    }
}

void dfsHeavyLight(int nodo)
{
    for (pair<int,int> par : g[nodo])
    {
        int hijo = par.first;
        if (hijo != padre[nodo])
        {
            if (2*tamSubarbol[hijo] > tamSubarbol[nodo])
                cabeza[hijo] = cabeza[nodo];
            else
                cabeza[hijo] = hijo;
            dfsHeavyLight(hijo);
        }
    }
}

int lca(int a,int b)
{
    while (cabeza[a] != cabeza[b])
    {
        if (profundidad[cabeza[a]] < profundidad[cabeza[b]])
            swap(a,b);
        a = padre[cabeza[a]];
    }
    if (profundidad[a] < profundidad[b])
        return a;
    else
        return b;
}

struct PorProfundidad
{
    bool operator()(int i, int j) const
    {
        if (profundidad[i] != profundidad[j])
            return profundidad[i] < profundidad[j];
        else
            return i < j;
    }
};

struct PorOrdenDFS
{
    bool operator()(int i, int j) const
    {
        if (ordenDFS[i] != ordenDFS[j])
            return ordenDFS[i] < ordenDFS[j];
        else
            return i < j;
    }
};


set<int, PorProfundidad> nodosActivos[MAXN];
tint distanciaTotal = 0;
int totalHijosActivos[MAXN];

void cambiar(int nodo, bool act)
{
    assert(activo[nodo] == !act);
    activo[nodo] = act;
    while (true)
    {
        bool eraVacio = nodosActivos[cabeza[nodo]].empty();
        #define profundidadMaximaEnCamino (nodosActivos[cabeza[nodo]].empty()?0:(distancia[*nodosActivos[cabeza[nodo]].rbegin()] - distancia[cabeza[nodo]]))
        distanciaTotal -= profundidadMaximaEnCamino;
        if (totalHijosActivos[nodo] == 0 && !activo[nodo])
            nodosActivos[cabeza[nodo]].erase(nodo);
        else
            nodosActivos[cabeza[nodo]].insert(nodo);
        distanciaTotal += profundidadMaximaEnCamino;
        
        bool esVacio = nodosActivos[cabeza[nodo]].empty();
        int propagaCoef = (2*eraVacio-1);
        nodo = cabeza[nodo];
        if (eraVacio == esVacio || nodo == 0)
            return;
        const tint pesoAristaPadre = distancia[nodo] - distancia[padre[nodo]];    
        distanciaTotal += propagaCoef * pesoAristaPadre;
        nodo = padre[nodo];
        totalHijosActivos[nodo] += propagaCoef;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; cin >> N;
    forn(i,N-1)
    {
        int a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back({b,c});
        g[b].push_back({a,c});
    }
    profundidad[0] = 0;
    distancia[0] = 0;
    padre[0] = 0;
    dfsPrecomputos(0);
    cabeza[0] = 0;
    dfsHeavyLight(0);
    int Q; cin >> Q;
    set<int, PorOrdenDFS> todosLosNodos;
    forn(i,Q)
    {
        string tipo; cin >> tipo;
        if (tipo == "?")
        {
            tint result = 0;
            if (!todosLosNodos.empty())
            {
                int globalLCA = lca(*todosLosNodos.begin(), *todosLosNodos.rbegin());
                result = distanciaTotal - distancia[globalLCA];
            }
            cout << result  << "\n";
        }
        else
        {
            int x; cin >> x;
            x--;
            cambiar(x, tipo == "+");
            if (tipo == "+")
                todosLosNodos.insert(x);
            else
                todosLosNodos.erase(x);
        }
    }
    return 0;
}