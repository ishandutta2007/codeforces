#include<bits/stdc++.h>

using namespace std;

int main()
{
  int N;
  string S;

  cin >> N;
  cin >> S;

  int ret = 0;
  vector< int > ans;
  for(char& s : S) {
    if(s == 'B') {
      ++ret;
    } else if(ret > 0) {
      ans.push_back(ret);
      ret = 0;
    }
  }
  if(ret > 0) {
    ans.push_back(ret);
  }

  cout << ans.size() << endl;
  for(int& val : ans) cout << val << " ";
}