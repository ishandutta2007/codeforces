#include<bits/stdc++.h>
using namespace std;


int main()
{
  int N;
  string S;
  bool exist[256] = {};
  int id[256] = {};
  
  cin >> N;
  cin >> S;

  for(char& c : S) exist[c]++;
  int sz = 0;
  for(int i = 0; i < 256; i++) {
    if(exist[i]) id[i] = sz++;
  }

  vector< int > shake(sz, 0);
  int head = 0, pz = 0;
  int ret = 1 << 30;
  for(int i = 0; i < N; i++) {
    while(head < N && pz < sz) {
      const int idx = id[S[head]];
      if(shake[idx] == 0) ++pz;
      ++shake[idx];
      ++head;
    }
    if(pz == sz) ret = min(ret, head - i);
    --shake[id[S[i]]];
    if(shake[id[S[i]]] == 0) --pz;
  }
  cout << ret << endl;
}