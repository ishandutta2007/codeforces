#include<bits/stdc++.h>
using namespace std;

int main()
{

  string a, b;
  cin >> a;
  cin >> b;

  vector< vector< int > > cost(2, vector< int >(a.size() + 1));
  cost[0][0] = 0;
  cost[1][0] = 0;

  for(int i = 1; i <= a.size(); i++) {
    cost[0][i] = cost[0][i - 1] + (a[i - 1] == '1');
    cost[1][i] = cost[1][i - 1] + (a[i - 1] == '0');
  }

  long long ret = 0;
  int tail = 0;
  int one[2] = {};
  for(int i = 0; i < b.size(); i++) {
    int pos = min< int >(a.size(), i + 1);
    ret += cost[b[i] - '0'][pos] + one[b[i] - '0'];
    if(b.size() - i <= a.size()) {
      one[0] -= (a[tail] == '1');
      one[1] -= (a[tail] == '0');
      tail++;
    }
  }
  cout << ret << endl;
}