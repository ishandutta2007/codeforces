#include<bits/stdc++.h>

using namespace std;

void inc(string& s)
{
  int idx = s.size() - 1;
  while(idx >= 0 && s[idx] == '9') s[idx--] = '0';
  if(idx == -1) s = "1" + s;
  else s[idx]++;
}

int main()
{
  int N, T;
  string K;

  cin >> N >> T;
  cin >> K;
  if(K.find('.') == string::npos) throw(0);

  int ptr = 0;
  while(ptr < K.size() && K[ptr] != '.') ++ptr;
  string L = K.substr(0, ptr);
  string R = "0" + K.substr(ptr + 1);
  int delta = 1;
  for(int i = 0; 0 <= i && i < R.size() && T > 0; i += delta) {
    if(R[i] >= '5') {
      while(i < R.size()) R.pop_back();
      --T;
      inc(R);
      while(R.back() == '0') R.pop_back();
      delta = -1;
    }
  }
  if(R.front() == '1') inc(L);
  if(R.size() == 1) cout << L << endl;
  else cout << L << "." << R.substr(1) << endl;
}