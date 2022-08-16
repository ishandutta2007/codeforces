#include<bits/stdc++.h>
using namespace std;
typedef long long int64;

struct Point {
  int64 x, y;
};

int main()
{
  Point p[3];
  vector< int64 > xx, yy;
  for(int i = 0; i < 3; i++) {
    cin >> p[i].x >> p[i].y;
    xx.push_back(p[i].x);
    yy.push_back(p[i].y);
  }
  sort(xx.begin(), xx.end());
  xx.erase(unique(xx.begin(), xx.end()), xx.end());
  sort(yy.begin(), yy.end());
  yy.erase(unique(yy.begin(), yy.end()), yy.end());
  
  if(xx.size() == 1 || yy.size() == 1) {
    cout << 1 << endl;
  } else if(xx.size() == 2) {
    for(int i = 0; i < 3; i++) {
      for(int j = i + 1; j < 3; j++) {
        if(p[i].x == p[j].x) {
          if(p[i].y > p[j].y) swap(p[i].y, p[j].y);
          int none;
          if(i == 0 && j == 1) none = 2;
          else if(i == 0 && j == 2) none = 1;
          else if(i == 1 && j == 2) none = 0;

          if(p[i].y < p[none].y && p[none].y < p[j].y) {
            cout << 3 << endl; 
          } else {
            cout << 2 << endl;
          }
          exit(0);
        } 
      }
    }
  } else if(yy.size() == 2) {
    for(int i = 0; i < 3; i++) {
      for(int j = i + 1; j < 3; j++) {
        if(p[i].y == p[j].y) {
          if(p[i].x > p[j].x) swap(p[i].x, p[j].x);
          int none;
          if(i == 0 && j == 1) none = 2;
          else if(i == 0 && j == 2) none = 1;
          else if(i == 1 && j == 2) none = 0;

          if(p[i].x < p[none].x && p[none].x < p[j].x) {
            cout << 3 << endl; 
          } else {
            cout << 2 << endl;
          }
          exit(0);
        } 
      }
    }
  } else {
    cout << 3 << endl;
  }
}