#include <iostream>

using namespace std;

#define forn(i,n) for(int i=0;i<int(n);i++)

const int MAXL = 1000000;

// NOTA:
// Esto es copy paste textual del algoritmo de Knuth-Morris-Pratt de nuestro notebook,
// agregando solamente las dos lineas marcadas
int pmp[MAXL];
void preMp(const string& x){
  int i=0, j = pmp[0] = -1;
  while(i<int(x.size())){
    while(j>-1 && x[i] != x[j]) j = pmp[j];
      pmp[++i] = ++j;
  }
}
int extra(const string& b, const string& g){
  preMp(b);
  int i=0,j=0;
  while(j<int(g.size())){
    while(i>-1 && b[i] != g[j]){i = pmp[i];}
    i++; j++;
    if (i>=int(b.size())){
      return 0; // Agregado para este problema
      i=pmp[i];
    }
  }
  return int(b.size()) - i; // Agregado para este problema
}
// ***************

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string v[3];
    forn(i,3)
        cin >> v[i];
    int shortest = 1000000000;
    forn(a,3)
    forn(b,3)
    if (a != b)
    {
        int c = 3 - a - b;
        string intermedia = v[a] + v[b].substr(v[b].size() - extra(v[b],v[a]));
        shortest = min(shortest, int(intermedia.size()) + extra(v[c], intermedia));
    }
    cout << shortest << endl;
    return 0;
}