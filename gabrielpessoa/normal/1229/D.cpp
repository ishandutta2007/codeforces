#include <bits/stdc++.h>
using namespace std;
 
//#define int long long
 
const int ms = 2e5+5;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;
const int sq = 400;
 
int n, k;
int arr[ms][5];
int perm[ms][5];
int last[ms];
int hsh[ms];
int result[5];
int temp[5];
pair<int, int> go[ms];
int app[200][200];
int exist[ms];
int exSz;
vector<int> good;
vector<int> q;
 
int doHash(int a[]) {
  int h = 0;
  for(int i = 0; i < k; i++) {
    h = h*6 + a[i];
  }
  return h;
}
 
int match(int x, int y) {
  for(int i = 0; i < k; i++) {
    if(arr[x][i] != perm[y][i]) return 0;
  }
  return 1;
}
 
int applyPerm(int x, int y) {
  for(int i = 0; i < k; i++) {
    temp[i] = perm[x][i];
  }
  for(int i = 0; i < k; i++) {
    result[i] = perm[x][perm[y][i]-1];
  }
  return hsh[doHash(result)];
}
 
main() {
  cin.tie(0); ios::sync_with_stdio(0);
  long long ans = 0;
  scanf("%d%d", &n, &k);
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < k; j++) {
      scanf("%d", &arr[i][j]);
    }
  }
  vector<int> v;
  for(int i = 1; i <= k; i++) v.push_back(i);
  int z = 0;
  do {
    for(int j = 0; j < k; j++) {
      perm[z][j] = v[j];
    }
    hsh[doHash(perm[z])] = z;
    // cout << "HASH de " << doHash(perm[z]) << " = " << z << endl;
    z++;
  } while(next_permutation(v.begin(), v.end()));
  for(int i = 0; i < z; i++) {
    for(int j = 0; j < z; j++) {
      app[i][j] = applyPerm(i, j);
    }
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 0; j < z; j++) {
      if(match(i, j)) last[j] = i;
      go[j] = {last[j], j};
    }
    sort(go, go+z);
    reverse(go, go+z);
    go[z] = {0, -1};
    for(int j = 0; j < z; j++) {
      exist[j] = 0;
    }
    exSz = 0;
    exist[0] = 1;
    exSz++;
    good.clear();
    for(int j = 0; j < z; j++) {
      int p = go[j].second;
      // if(go[j].first) cout << "agora pondo " << p << " na posicao " << go[j].first << endl;
      if(!exist[p]) {
        exist[p] = 1;
        exSz++;
        good.push_back(p);
        q.clear();
        q.push_back(p);
        for(int i = 0; i < q.size(); i++) {
          int f = q[i];
          for(int w : good) {
            int k1 = app[f][w];
            int k2 = app[w][f];
            // cout << "aplicando " << w << " em " << f << " deu " << k1 << " e " << k2 << endl;
            if(!exist[k1]) {
              exist[k1] = 1;
              exSz++;
              q.push_back(k1);
            }
            if(!exist[k2]) {
              exist[k2] = 1;
              exSz++;
              q.push_back(k2);
            }
          }
        }
      }
      // if(go[j].first) cout << "Deu " << exSz << " agora e o o proxiom  em " << go[j+1].first << endl;
      ans = ans + (long long) exSz * (go[j].first - go[j+1].first);
    }
    // cout << "--Proximo cara-- " << endl;
  }
  printf("%lld\n", ans);
}