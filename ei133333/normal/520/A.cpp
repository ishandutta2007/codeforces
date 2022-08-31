#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin >> N;
  string str;
  cin >> str;
  vector< bool > used(26);
  for(int i = 0; i < N; i++) {
    if(isalpha(str[i])) used[tolower(str[i]) - 'a'] = true;
  }
  if(count(used.begin(), used.end(), true) != 26) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
  }
}