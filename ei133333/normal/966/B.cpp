#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

int main() {
  int N, X1, X2, C[300000];
  scanf("%d %d %d", &N, &X1, &X2);
  for(int i = 0; i < N; i++) {
    scanf("%d", &C[i]);
  }
  vector< pair< int, pair< int, int >> > beet;
  for(int i = 0; i < N; i++) {
    beet.emplace_back((X1 + C[i] - 1) / C[i], make_pair((X2 + C[i] - 1) / C[i], i));
  }
  sort(begin(beet), end(beet));
  for(int i = 0; i < N; i++) {
    // 2 <= 2
    if(beet[i].second.first <= i + 1) {
      int j = i - beet[i].second.first;
      if(j >= 0 && beet[j].first <= j + 1) {

        puts("Yes");
        vector< int > vs, xs;
        int ptr = i;
        int sz1 = beet[i].second.first;
        while(sz1 > 0) {
          vs.emplace_back(beet[ptr].second.second );
          --ptr;
          --sz1;
        }
        int sz2 = beet[j].first;
        while(sz2 > 0) {
          xs.emplace_back(beet[ptr].second.second);
          --ptr;
          --sz2;
        }


        cout << xs.size() << " " << vs.size() << endl;
        for(auto& p : xs) cout << p + 1 << " ";
        cout << endl;
        for(auto& p : vs) cout << p + 1 << " ";
        cout << endl;


        return 0;
      }

    }


    if(beet[i].first <= i + 1) {
      int j = i - beet[i].first;
      if(j >= 0 && beet[j].second.first <= j + 1) {
        puts("Yes");
        vector< int > vs, xs;
        int sz1 = beet[i].first, ptr = i;
        while(sz1 > 0) {
          vs.emplace_back(beet[ptr].second.second);
          --ptr;
          --sz1;
        }
        int sz2 = beet[j].second.first;
        while(sz2 > 0) {
          xs.emplace_back(beet[ptr].second.second);
          --ptr;
          --sz2;
        }

        cout << vs.size() << " " << xs.size() << endl;
        for(auto& p : vs) cout << p + 1 << " ";
        cout << endl;
        for(auto& p : xs) cout << p + 1 << " ";
        cout << endl;


        return 0;
      }
    }

  }
  puts("No");

}