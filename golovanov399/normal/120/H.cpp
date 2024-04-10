#include <cstdio>
#include <iostream>
#include <cstdlib>

#include <cstring>

#include <vector>
#include <map>
#include <algorithm>

using namespace std;

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define pb push_back

const int maxn = 200 + 5;
const int maxt = 200 * 1000 + 5;

vector <int> A[maxn];
bool used[maxn];
vector <int> temp;
string S[maxt];
string ans[maxn];
map <string, int> M;
int mt[maxt];

int cnt = 0;

void mk(string & s, int pos, int len)
{
  string sub = "";
  for (int i = 0; i < len - 1; ++i) {
    sub += s[i];
  }
  
  temp.clear();
  /*
  for (int i = len - 1; i < sz(s); ++i) {
    sub += s[i];
    if (i - len >= 0)
      sub = sub.substr(1, 4);
    
    if (!M.count(sub)) {
      S[cnt] = sub;
      M[sub] = cnt++;
    }
    
    temp.pb(M[sub]);
  }
  */
  
  for (int i = 0; i < (1 << sz(s)); ++i) {
    string sub = "";
    int x = i;
    for (int j = 0; j < sz(s); ++j) {
      int c = x % 2;
      if (c)
        sub += s[j];
        
      if (sz(sub) > len)
        break;
        
      x /= 2;
    }
    
    if (sz(sub) > len || !sz(sub))
      continue;
      
    if (!M.count(sub)) {
      S[cnt] = sub;
      M[sub] = cnt++;
    }
    
    temp.pb(M[sub]); 
  }
  
  sort(all(temp));
  
  for (int i = 0; i < sz(temp); ++i) {
    if (!i || temp[i - 1] != temp[i]) {
      A[pos].pb(temp[i]);
    }
  }
  
}

bool kuhn(int v)
{
  if (used[v]) 
    return 0;
  used[v] = 1;
  
  for (int i = 0; i < sz(A[v]); ++i) {
    int u = A[v][i];
    if (mt[u] == -1 || kuhn(mt[u])) {
      mt[u] = v;
      return 1;
    }
  }
  
  return 0;
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  
  int n;
  cin >> n;
  
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    
    for (int j = 1; j <= min(4, sz(s)); ++j) {
      mk(s, i, j);
    }
  }
  
  for (int i = 0; i < cnt; ++i) {
    mt[i] = -1;
  }
  
  for (int i = 0; i < n; ++i) {
    memset(used, 0, sizeof(used));
    
    kuhn(i);
  }
  
 // cerr << cnt << endl;
  
  int res = 0;
  
  for (int i = 0; i < cnt; ++i) {
    if (mt[i] != -1) {
      ++res;
      ans[mt[i]] = S[i];
      //cerr << mt[i] << endl;
    }
  }
  
 
  
  if (res < n) {
    cout << "-1\n";
    return 0;
  }
  
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << "\n";
  }
  
  return 0;
}