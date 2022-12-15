#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll mod = 1e9 + 7;
const int ms = 1e5+5;

int n, m, s;
pair<int, int> a[ms];
int used[ms];
pair<pair<int, int>, int> b[ms]; // bug complexity, level of student, number of passes

bool solve(int k) {
  if(k == m + 1) return true;
  int E = (m-1)/k + 1;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  int soma = 0;
  int cur = 0;
  //cout << "Busca de " << k << endl;
  for(int i = 0; i < E; i++) {
    int bug = a[i*k].first;
    //cout << "No " << i << " do " << k << " deu " << bug << endl;
    while(cur < n && b[cur].first.first >= bug) {
      pq.emplace(b[cur].first.second, b[cur].second);
      cur++;
    }
    if(pq.empty()) return false;
    soma += pq.top().first;
    int limite = min(m, (i+1)*k);
    //cout << "LIMITE? " << i * k << ' ' << limite << endl;
    for(int j = i*k; j < limite; j++) {
      //cout << "UPDATING " << a[j].second << ' ' << pq.top().second << endl;
      used[a[j].second] = pq.top().second;
    }
    pq.pop();
    if(soma > s) return false;
  }
  //cout << "Resultado de " << k << ' ' << soma << endl;
  return true;
}

int main() {
  cin.tie(0); ios::sync_with_stdio(0);
  cin >> n >> m >> s;
  for(int i = 0; i < m; i++) cin >> a[i].first;
  for(int i = 0; i < m; i++) a[i].second = i;
  for(int i = 0; i < n; i++) cin >> b[i].first.first;
  for(int i = 0; i < n; i++) cin >> b[i].first.second;
  for(int i = 0; i < n; i++) b[i].second = i + 1;
  sort(a, a+m); sort(b, b+n);
  reverse(a, a+m); reverse(b, b+n);
  int lo = 1, hi = m+1;
  while(lo < hi) {
    int mi = (lo+hi)/2;
    if(solve(mi)) hi = mi;
    else lo = mi + 1;
  }
  solve(lo);
  if(lo == m + 1) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    //cout << lo << endl;
    for(int i = 0; i < m; i++) {
      cout << used[i] << ' ';
    }
    cout << endl;
  }
}