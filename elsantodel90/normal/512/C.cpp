#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <functional>
#include <stack>
#include <sstream>

#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define dforn(i,n) for(int i=(n)-1;i>=0; i--)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)

#define forall(it, c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)

using namespace std;

typedef long long tint;

const int MAX_N = 1024;

namespace Notebook
{

    struct Eje{ long f,m; long d(){return m-f;}};
    typedef map <int, Eje> MIE; MIE red[MAX_N];
    int N,F,D;
    void iniG(int n, int f, int d){N=n; F=f; D=d;fill(red, red+N, MIE());}
    void aEje(int d, int h, int m){
      red[d][h].m=m;red[d][h].f=red[h][d].m=red[h][d].f=0;
    }
    #define DIF_F(i,j) (red[i][j].d())
    #define DIF_FI(i)  (i->second.d())
    int v[MAX_N];
    long camAu(){
      fill(v, v+N,-1);
      queue<int> c;
      c.push(F);
      while(!(c.empty()) && v[D]==-1){
        int n = c.front(); c.pop();
        for(MIE::iterator i = red[n].begin(); i!=red[n].end(); i++){
          if(v[i->first]==-1 && DIF_FI(i) > 0){
            v[i->first]=n;
            c.push(i->first);
          }
        }
      }
      if(v[D]==-1)return 0;
      int n = D;
      long f = DIF_F(v[n], n);
      while(n!=F){
          f = min(f, DIF_F(v[n], n));
          n=v[n];
      }
      n = D;
      while(n!=F){
        red[n][v[n]].f=-(red[v[n]][n].f+=f);
        n=v[n];
      }
      return f;
    }
    long flujo(){long tot=0, c;do{tot+=(c=camAu());}while(c>0); return tot;}
};

const int MAX_P = 100000;
bool primes[MAX_P];

void criba()
{
    forn(i, MAX_P) primes[i] = true;
    primes[0] = primes[1] = false;
    for(int i = 2; i*i < MAX_P; i++)
    if (primes[i])
        for(int j = i*i;j < MAX_P; j += i) primes[j] = false;
}

int a[MAX_N], pares[MAX_N], impares[MAX_N];
int pares_index[MAX_N], impares_index[MAX_N];

const char * IMPOSSIBLE = "Impossible";

vector<int> g[MAX_N];

vector<vector<int> > solution;
bool used[MAX_N];

void dfs(int x)
{
    used[x] = true;
    solution.back().push_back(x);
    forall(it, g[x])
    if (!used[*it])
        dfs(*it);
}

int main() 
{
    criba();
    #ifdef ACMTUYO
        freopen("c.in","r",stdin);
    #endif
    int n; cin >> n;
    int P = 0, I = 0;
    forn(i,n)
    {
        cin >> a[i];
        if (a[i] % 2)
        {
            impares_index[I] = i;
            impares[I++] = a[i];
        }
        else
        {
            pares_index[P] = i;
            pares[P++] = a[i];
        }
    }
    if (P != I)
    {
        cout << IMPOSSIBLE << endl;
        return 0;
    }
    const int SOURCE = P+I, SINK = P+I+1, NODES = P+I+2;
    Notebook::iniG(NODES, SOURCE, SINK);
    #define par(i) (i)
    #define impar(i) (P+(i))
    forn(i, P) Notebook::aEje(SOURCE,par(i),2);
    forn(i, I) Notebook::aEje(impar(i), SINK,2);
    
    forn(i, P)
    forn(j, I)
    if (primes[pares[i] + impares[j]])
        Notebook::aEje(par(i), impar(j), 1);
    int maxFlow = Notebook::flujo();
    if (maxFlow < 2*P)
    {
        cout << IMPOSSIBLE << endl;
        return 0;
    }
    forn(i, P)
    forn(j, I)
    if (primes[pares[i] + impares[j]] && Notebook::red[par(i)][impar(j)].f > 0)
    {
        g[pares_index[i]].push_back(impares_index[j]);
        g[impares_index[j]].push_back(pares_index[i]);
    }
    forn(i,n) used[i] = false;
    forn(i,n) if (!used[i])
    {
        solution.push_back(vector<int>());
        dfs(i);
    }
    cout << solution.size() << endl;
    forn(i, solution.size())
    {
        cout << solution[i].size();
        forn(j,solution[i].size())
            cout << " " << solution[i][j]+1;
        cout << endl;
    }
    return 0;
}