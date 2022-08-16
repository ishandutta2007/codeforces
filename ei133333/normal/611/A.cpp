#include<bits/stdc++.h>
using namespace std;
typedef long long int64;
const int INF = 1 << 30;
int main()
{
  const int manth[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  const int hoge[] = {52, 52, 52, 52, 53, 53, 52};
  int N;
  cin >> N; 
  string S;
  getline(cin, S);
  if(S.find("week") != string::npos) {
    cout << hoge[N - 1] << endl;
  } else {
    int ret = 0;
    for(int i = 0; i < 12; i++) {
      if(N <= manth[i]) ++ret;
    }
    cout << ret << endl;
  }

}