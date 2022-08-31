#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

const string V = ",;";


int main() {
  string s;
  cin >> s;
  vector< string > st;
  st.emplace_back();
  for(int i = 0; i < s.size(); i++) {
    if(V.find(s[i]) == string::npos) {
      st.back() += s[i];
    } else {
      st.emplace_back();
    }
  }
  string latte, malta;
  for(auto &p : st) {
    if(p == "") {
      malta += ",";
      continue;
    }
    if(p == "0") {
      latte += p + ",";
      continue;
    }
    bool all = p[0] != '0';
    for(auto &c : p) all &= isdigit(c);
    if(all) {
      latte += p + ",";
      continue;
    }
    malta += p + ",";
  }
  if(latte.empty()) cout << "-" << endl;
  else {
    latte.pop_back();
    cout << "\"" << latte << "\"" << endl;
  }
  if(malta.empty()) cout << "-" << endl;
  else {
    malta.pop_back();
    cout << "\"" << malta << "\"" << endl;
  }
}