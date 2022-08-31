#include<bits/stdc++.h>

using namespace std;

int X[200000];
string A, B;

bool check(int v)
{
  int tail = 0;
  for(int i = 0; i < A.size(); i++) {
    if(X[i] < v) continue;
    if(A[i] == B[tail]) ++tail;
    if(tail == B.size()) return (true);
  }
  return (false);
}

int main()
{
  cin >> A >> B;
  for(int i = 0; i < A.size(); i++) {
    int V;
    cin >> V;
    X[--V] = i;
  }

  int ok = 0, ng = (int) A.size();
  while(ng - ok > 1) {
    int mi = (ok + ng) >> 1;
    if(check(mi)) ok = mi;
    else ng = mi;
  }
  cout << ok << endl;
}