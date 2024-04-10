#include <bits/stdc++.h>
using namespace std;

multiset<int> s,ss;
int n,frs,x;

int main() 
{
 cin >> n;
 for (int i = 0; i < n; ++i) {
  cin >> x;
  s.insert(x);
 }
 ss = s;
 for (int i = 0; i < n-1; ++i) {
  cin >> x;
  ss.erase(ss.find(x));
 }
 frs = (*ss.begin());
 for (int i = 0; i < n-2; ++i) {
  cin >> x;
  s.erase(s.find(x));
 }
 s.erase(s.find(frs));
 cout << frs << endl << (*s.begin());
}