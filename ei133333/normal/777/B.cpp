#include<bits/stdc++.h>

using namespace std;

int a(string x, string y)
{
  int a[10];
  for(int i = 0; i < 10; i++) {
    a[i] = count(begin(y), end(y), (char)(i + '0'));
  }
  sort(begin(y), end(y));
  int ret = 0;
  for(int i = 0; i < x.size(); i++) {
    for(int j = x[i] - '0'; j <= 9; j++) {
      if(a[j] > 0) {
        --a[j], ++ret;
        break;
      }
    }
  }
  return(x.size() - ret);
}

int b(string x, string y)
{
  int a[10];
  for(int i = 0; i < 10; i++) {
    a[i] = count(begin(y), end(y), (char)(i + '0'));
  }
  sort(begin(y), end(y));
  int ret = 0;
  for(int i = 0; i < x.size(); i++) {
    for(int j = x[i] - '0' + 1; j <= 9; j++) {
      if(a[j] > 0) {
        --a[j], ++ret;
        break;
      }
    }
  }
  return(ret);
}
int main()
{
  int n;
  string s, t;

  cin >> n;
  cin >> s >> t;
  cout << a(s, t) << endl;
  cout << b(s, t) << endl;

}