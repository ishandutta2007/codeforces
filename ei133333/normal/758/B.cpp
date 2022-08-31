#include<bits/stdc++.h>

using namespace std;

const string a = "RBYG";

int main()
{
  string S;
  cin >> S;

  string t = "RBYG";
  sort(begin(t), end(t));
  do {
    string link = t;
    while(link.size() <= S.size()) link += t;

    bool match = true;
    int s[4] = {};
    for(int i = 0; i < S.size(); i++) {
      if(S[i] != '!' && S[i] != link[i]) match = false;
      if(S[i] == '!') s[a.find(link[i])]++;
    }
    if(match) {
      cout << s[0] << " " << s[1] << " " << s[2] << " " << s[3] << endl;
      break;
    }
  } while(next_permutation(begin(t), end(t)));


}