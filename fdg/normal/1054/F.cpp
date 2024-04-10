#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int x[1001], y[1001];

struct hSeg {
  int y, x1, x2;
};

struct vSeg {
  int x, y1, y2;
};

bool has(const hSeg& a, const vSeg& b) {
  return b.y1 < a.y && a.y < b.y2 && a.x1 < b.x && b.x < a.x2;
}

typedef vector<int> VInt;
typedef vector<VInt> VVInt;
typedef VInt::iterator VIter;
typedef vector<bool> VBool;

VVInt graph;
int leftCount, rightCount;
VInt match;
VBool visited;
VBool isRight;

bool matchVisit(int u) {
   visited[u] = true;
   for(VIter it = graph[u].begin(); it != graph[u].end(); it++)
      if(match[*it] == -1 || (!visited[match[*it]] && matchVisit(match[*it]))) {
         match[*it] = u;
         return true;
      }
   return false;
}

void controlVisit(int u) {
   visited[u] = true;
   for(VIter it = graph[u].begin(); it != graph[u].end(); it++)
      if(!isRight[*it] && !visited[match[*it]]) {
         controlVisit(match[*it]);
         isRight[*it] = true;
      }
}

pair<VInt, VInt> control() {
   int i;
   
   match.assign(rightCount, -1);
   visited.assign(leftCount, false);
   
   for(i = 0; i < leftCount; i++) {
      visited.assign(leftCount, false);
      matchVisit(i);
   }
   
   VBool isFree(leftCount, true);
   for(i = 0; i < rightCount; i++)
      if(match[i] != -1)
         isFree[match[i]] = false;

   isRight.assign(rightCount, false);
   visited.assign(leftCount, false);
   for(i = 0; i < leftCount; i++)
      if(isFree[i])
         controlVisit(i);
         
   pair<VInt, VInt> result;
   for(i = 0; i < rightCount; i++)
      if(match[i] != -1) {
         if(isRight[i])
            result.second.push_back(i);
         else
            result.first.push_back(match[i]);
      }
   return result;
}

int main() {
  int n;
  cin >> n;
  
  vector<pair<int, int>> xy, yx;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
    xy.push_back({x[i], y[i]});
    yx.push_back({y[i], x[i]});
  }

  sort(xy.begin(), xy.end());
  sort(yx.begin(), yx.end());

  vector<vSeg> vseg;
  for (int i = 1; i < xy.size(); ++i) {
    if (xy[i - 1].first == xy[i].first) {
      vseg.push_back({xy[i].first, xy[i - 1].second, xy[i].second});
      // cout << vseg.back().x << "  " << vseg.back().y1 << "  " << vseg.back().y2 << endl;
    }
  }

  vector<hSeg> hseg;
  for (int i = 1; i < yx.size(); ++i) {
    if (yx[i - 1].first == yx[i].first) {
      hseg.push_back({yx[i].first, yx[i - 1].second, yx[i].second});
      // cout << hseg.back().y << "  " << hseg.back().x1 << "  " << hseg.back().x2 << endl;
    }
  }

  leftCount = vseg.size();
  rightCount = hseg.size();

   graph.resize(leftCount);
   for (int i = 0; i < vseg.size(); ++i) {
    for (int j = 0; j < hseg.size(); ++j) {
      if (has(hseg[j], vseg[i])) {
        graph[i].push_back(j);
      }
    }
   }
   
   pair<VInt, VInt> answer = control();
   
   vector<bool> goodLeft(vseg.size(), true);
   for(VIter it = answer.first.begin(); it != answer.first.end(); it++)
      goodLeft[*it] = false;
   vector<bool> goodRight(hseg.size(), true);
   for(VIter it = answer.second.begin(); it != answer.second.end(); it++)
      goodRight[*it] = false;

  {
    vector<hSeg> hAns;
    int lx = yx[0].second, ly = yx[0].first, id = 0;
    yx.push_back({1e+9 + 7, 1e+9 + 7});
    for (int i = 1; i < yx.size(); ++i) {
      if (yx[i - 1].first == yx[i].first) {
        if (!goodRight[id]) {
          hAns.push_back({ly, lx, yx[i - 1].second});
          lx = yx[i].second;
          ly = yx[i].first;
        }
        ++id;
      } else {
        hAns.push_back({ly, lx, yx[i - 1].second});
        lx = yx[i].second;
        ly = yx[i].first;
      }
    }

    cout << hAns.size() << endl;
    for (int i = 0; i < hAns.size(); ++i)
      cout << hAns[i].x1 << " " << hAns[i].y << " " << hAns[i].x2 << " " << hAns[i].y << endl;
  }

  {
    vector<vSeg> vAns;
    int lx = xy[0].first, ly = xy[0].second, id = 0;
    xy.push_back({1e+9 + 7, 1e+9 + 7});
    for (int i = 1; i < xy.size(); ++i) {
      if (xy[i - 1].first == xy[i].first) {
        if (!goodLeft[id]) {
          vAns.push_back({lx, ly, xy[i - 1].second});
          lx = xy[i].first;
          ly = xy[i].second;
        }
        ++id;
      } else {
        vAns.push_back({lx, ly, xy[i - 1].second});
        lx = xy[i].first;
        ly = xy[i].second;
      }
    }

    cout << vAns.size() << endl;
    for (int i = 0; i < vAns.size(); ++i)
      cout << vAns[i].x << " " << vAns[i].y1 << " " << vAns[i].x << " " << vAns[i].y2 << endl;
  }

  return 0;
}