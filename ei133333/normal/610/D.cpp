#include<bits/stdc++.h>
using namespace std;
struct BinaryIndexedTree
{
  vector< int > data;
  BinaryIndexedTree(int sz)
  {
    data.assign(++sz, 0);
  }
  long long query(int k)
  {
    int ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return(ret);
  }
  void update(int k, int x)
  {
    for(++k; k < data.size(); k += k & -k) data[k] += x;
  }
};
struct Event
{
  int x1, x2, y, type;
  bool operator<(const Event& e) const
  {
    if(y == e.y) return(type < e.type);
    return(y < e.y);
  }
};
vector< pair< int, int > > dist[200005], dist2[200005];

int main()
{
  int n;
  cin >> n;
  vector< Event > data, prev, pref;
  vector< int > nums, nums2;
  long long ret = 0;

  for(int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 > x2) swap(x1, x2);
    if(y1 > y2) swap(y1, y2);
    nums.push_back(x1), nums.push_back(x2);
    nums2.push_back(y1), nums2.push_back(y2);
    if(x1 == x2) {
      prev.push_back((Event){x1, x2, y1, 1});
      prev.push_back((Event){x1, x2, y2, 3});
    } else {
      pref.push_back((Event){y1, y2, x1, 1});
      pref.push_back((Event){y1, y2, x2, 3});
    }
  }
  nums.push_back(-1145141919);
  nums.push_back(+1145141919);
  nums2.push_back(-1145141919);
  nums2.push_back(+1145141919);
  sort(nums.begin(), nums.end());
  nums.erase(unique(nums.begin(), nums.end()), nums.end());
  sort(nums2.begin(), nums2.end());
  nums2.erase(unique(nums2.begin(), nums2.end()), nums2.end());

  for(int i = 0; i < prev.size(); i++) {
    const Event& e = prev[i];
    if(e.type == 1) {
      int x = lower_bound(nums.begin(), nums.end(), e.x1) - nums.begin();
      dist[x].push_back(make_pair(e.y, -1));
    } else {
      int x = lower_bound(nums.begin(), nums.end(), e.x1) - nums.begin();
      dist[x].push_back(make_pair(e.y, +1));
    }
  }
  for(int i = 0; i < nums.size(); i++) {
    if(dist[i].empty()) continue;
    sort(dist[i].begin(), dist[i].end());
    int lines = 0;
    for(int j = 0; j < dist[i].size(); j++) {
      if(dist[i][j].second == 1) { // Erase  
        lines--;
        if(lines == 0) {
          data.push_back((Event){nums[i], nums[i], dist[i][j].first, 3});
          ret += dist[i][j].first - data[data.size() - 2].y + 1;
        }
      } else { // Create
        if(lines == 0) data.push_back((Event){nums[i], nums[i], dist[i][j].first, 1});
        lines++;
      }
    }
  }

  for(int i = 0; i < pref.size(); i++) {
    const Event& e = pref[i];
    if(e.type == 1) {
      int x = lower_bound(nums2.begin(), nums2.end(), e.x1) - nums2.begin();
      dist2[x].push_back(make_pair(e.y, -1));
    } else {
      int x = lower_bound(nums2.begin(), nums2.end(), e.x1) - nums2.begin();
      dist2[x].push_back(make_pair(e.y, +1));
    }
  }
  for(int i = 0; i < nums2.size(); i++) {
    if(dist2[i].empty()) continue;
    sort(dist2[i].begin(), dist2[i].end());
    int lines = 0;
    int f = 0;
    for(int j = 0; j < dist2[i].size(); j++) {
      if(dist2[i][j].second == 1) { // Erase  
        lines--;
        if(lines == 0) {
          data.push_back((Event){dist2[i][f].first, dist2[i][j].first, nums2[i], 2});
        }
      } else { // Create
        if(lines == 0) f = j;
        lines++;
      }
    }
  }


  sort(data.begin(), data.end());

  BinaryIndexedTree bit(nums.size());

  for(int i = 0; i < data.size(); i++) {
    const Event& e = data[i];
    if(e.type == 1) {
      int x = lower_bound(nums.begin(), nums.end(), e.x1) - nums.begin();
      bit.update(x, +1);
    } else if(e.type == 3) {
      int x = lower_bound(nums.begin(), nums.end(), e.x1) - nums.begin();
      bit.update(x, -1);
    } else {
      int x1 = lower_bound(nums.begin(), nums.end(), e.x1) - nums.begin();
      int x2 = lower_bound(nums.begin(), nums.end(), e.x2) - nums.begin();
      ret += e.x2 - e.x1 + 1 - (bit.query(x2) - bit.query(x1 - 1));
    }
  }


  cout << ret << endl;
}