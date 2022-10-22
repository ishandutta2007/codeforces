#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MOD = 3;

int add(int a, int b) {
  a += b;
  if(a >= MOD) return a - MOD;
  if(a < 0) return a + MOD;
  return a;
}

int mul(int a, int b) {
  return a * (ll)b % MOD;
}

int expow(int a, int b) {
  int r = 1;
  while(b) {
    if(b & 1) {
      r = mul(r, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return r;
}

int dv(int a, int b) {
  return mul(a, expow(b, MOD - 2));
}

/// n ecuatii
/// m necunoscute : a(0), ..., a(10)

int n;
int m;
int A[257*257][257];
int X[257*257];
int e[300][300];
int id[300][300];

signed main() {
 // freopen("input","r",stdin);
  ios::sync_with_stdio(0);cin.tie(0);
  int t;
  cin>>t;
  while (t--){
    for (int i=0;i<257*257;i++){
      X[i]=0;
      for (int j=0;j<257;j++)A[i][j]=0;
    }

    for (int i=0;i<300;i++)for (int j=0;j<300;j++)e[i][j]=id[i][j]=0;
    int verts,edges;
    cin>>verts>>edges;
    n=0;
    m=edges;


    for (int i=1;i<=edges;i++){
      int a,b,c;
      cin>>a>>b>>c;
      if(c!=-1){
        n++;
        A[n][i]=1;
        A[n][m+1]=c-1;
      }
      e[a][b]=c;
      e[b][a]=c;
      id[a][b]=id[b][a]=i;
    }

    for (int i=1;i<=verts;i++){
      for (int j=i+1;j<=verts;j++){
        if(id[i][j]){
          for (int k=j+1;k<=verts;k++){
            if(id[i][k]&&id[j][k]){
              n++;
              A[n][id[i][j]]=1;
              A[n][id[i][k]]=1;
              A[n][id[j][k]]=1;
              A[n][m+1]=0;
            }
          }
        }
      }
    }
    assert(n<257*257);

    int i = 1, j = 1, k;
    int aux;

    //Algoritmul lui Gauss propriu-zis
    while(i <= n && j <= m) {
      //Cautam o linie k pentru care A[k][j] sa fie nenul. Folosim epsilonul pentru a nu lua in considerare micile erori de calcul.
      for(k = i; k <= n; ++k)
        if(A[k][j] != 0)
          break;

      //Daca nu gasim linia, necunoscuta j este variabila libera, incrementam pe j si trecem la pasul urmator.
      if(k == n + 1) {
        ++j;
        continue;
      }

      //Interschimbam pe k cu i, daca este cazul.
      if(k != i)
        for(int l = 1; l <= m + 1; ++l) {
          aux = A[i][l];
          A[i][l] = A[k][l];
          A[k][l] = aux;
        }

      //Pentru a usura calculele, impartim toate valorile de pe linia i la A[i][j], A[i][j] devenind 1.
      //Observam ca valorile de pe linia i si coloanele 1..j-1 sunt egale cu 0 de la pasii precedenti ai algoritmului,
      //deci nu e necesar sa le parcurgem pentru a le imparti.
      for(int l = j + 1; l <= m + 1; ++l)
        A[i][l] = dv(A[i][l], A[i][j]);
      A[i][j] = 1;

      //Scadem din ecuatiile i+1...n ecuatia i inmultita cu A[u][j], pentru a egala toti coeficientii de coloana j
      //a acestor linii la 0.
      for(int u = i + 1; u <= n; ++u) {
        for(int l = j + 1; l <= m + 1; ++l)
          A[u][l] = add(A[u][l], -mul(A[u][j], A[i][l]));
        A[u][j] = 0;
      }

      ++i;
      ++j;
    }

    bool ok=1;

    //Calculul necunoscutelor
    for(int i = n; i > 0; --i)
      for(int j = 1; j <= m + 1; ++j)
        if(A[i][j] != 0) {
          //Singura valoare nenegativa de pe linia i este rezultatul => sistemul nu are solutie.
          if(j == m + 1) {
            ok=0;
            break;
          }

          //Calculam pe necunoscuta j = rezultatul ecuatiei i - necunoscutele j+1...m inmultite cu coeficientii lor din aceasta ecuatie.
          X[j] = A[i][m + 1];
          for(int k = j + 1; k <= m; ++k)
            X[j] = add(X[j], -mul(X[k], A[i][k]));
          break;
        }
      if(!ok){
        cout<<"-1\n";
        continue;
      }
    for (int i=1;i<=m;i++)cout<<X[i]+1<<" ";cout<<"\n";
  }
  return 0;
}
/**


**/