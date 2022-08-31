#include <bits/stdc++.h>

using namespace std;


int main()
{
  list< char > tuplis;
  string S;
  cin >> S;
  for(auto &c : S) tuplis.push_back(c);

  vector< pair< list< char >::iterator, int > > killptr;
  for(auto p = tuplis.begin(); p != tuplis.end(); p++) {
    bool isdel = false;
    if(tuplis.begin() != p) {
      auto q = prev(p);
      if(*q != *p) isdel = true;
    }
    auto r = next(p);
    if(r != tuplis.end()) {
      if(*r != *p) isdel = true;
    }
    if(isdel) {
      bool flag = false;
      if(killptr.empty() && p != tuplis.begin()) flag = true;
      if(killptr.size() && killptr.back().first != prev(p)) flag = true;
      killptr.emplace_back(p, flag);
    }
  }

  int ret = 0;


  while(killptr.size()) {
    vector< list< char >::iterator > neighbor;
    for(auto &p : killptr) {
      if(p.second > 0) neighbor.emplace_back(prev(p.first));
      tuplis.erase(p.first);
    }
    killptr.clear();

    for(int i = 0; i < neighbor.size(); i++) {
      auto p = neighbor[i];
      {
        bool isdel = false;
        if(tuplis.begin() != p) {
          auto q = prev(p);
          if(*q != *p) isdel = true;
        }
        auto r = next(p);
        if(r != tuplis.end()) {
          if(*r != *p) isdel = true;
        }
        if(isdel) {
          bool flag = false;
          if(killptr.empty() && p != tuplis.begin()) flag = true;
          if(killptr.size() && killptr.back().first != prev(p)) flag = true;
          killptr.emplace_back(p, flag);
        }
      }

      if(i + 1 == neighbor.size() || next(p) != neighbor[i + 1]) {
        p = next(p);
        if(p == tuplis.end()) continue;

        {
          bool isdel = false;
          if(tuplis.begin() != p) {
            auto q = prev(p);
            if(*q != *p) isdel = true;
          }
          auto r = next(p);
          if(r != tuplis.end()) {
            if(*r != *p) isdel = true;
          }
          if(isdel) {
            bool flag = false;
            if(killptr.empty() && p != tuplis.begin()) flag = true;
            if(killptr.size() && killptr.back().first != prev(p)) flag = true;
            killptr.emplace_back(p, flag);
          }
        }
      }
    }


    ++ret;
  }

  cout << ret <<
       endl;
}