#include<bits/stdc++.h>

using namespace std;

struct Taplis
{
  void TapTap()
  {
    int N;
    string S;

    cin >> N;
    cin >> S;

    int ret = 0;
    for(int i = 0; i < N; i++) {
      set< char > st;
      for(int j = i; j < N; j++) {
        if(isupper(S[j])) break;
        st.insert(S[j]);
      }
      ret = max(ret, (int)st.size());
    }

    cout << ret << endl;
  }
};

int main()
{
  Taplis().TapTap();
}