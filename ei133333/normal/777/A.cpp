#include<bits/stdc++.h>

using namespace std;
int main()
{
  vector< vector< int > > v;
  v.push_back({0, 1, 2});
  v.push_back({1, 0, 2});
  v.push_back({1, 2, 0});
  v.push_back({2, 1, 0});
  v.push_back({2, 0, 1});
  v.push_back({0, 2, 1});


  int n, x;
  cin >> n >> x;
  cout << v[n % v.size()][x] << endl;
}