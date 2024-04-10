#include <bits/stdc++.h>
using namespace std;
const int MAX_A = 100000, oo = 1000111000;

struct SegmentTree
{
  int low, mid, high, sum, cnt;
  SegmentTree *left, *right;
  
  SegmentTree(int low, int high)
  {
    this -> low = low;
    this -> high = high;
    mid = (low + high) / 2;
    sum = cnt = 0;
    if (low < high)
    {
      left = new SegmentTree(low, mid);
      right = new SegmentTree(mid + 1, high);
    }
  }
  
  void update(int x, int v, int type)
  {
    sum += v * type;
    cnt += type;
    if (low == high) return;
    if (x <= mid) left -> update(x, v, type);
    else right -> update(x, v, type); 
  }
  
  int search(int need)
  {
    if (cnt == need) return sum;
    if (left -> cnt >= need) return left -> search(need);
    return left -> sum + right -> search(need - left -> cnt);
  }
};

vector < pair <int,int> > a[MAX_A + 10], votes[MAX_A + 10], b;
int n, minCost[100100], pos[100100];
SegmentTree *segmenTree;

int main()
{
  ios::sync_with_stdio(0);
  //freopen("c.in", "r", stdin);
  
  int x, y, maxOther = 0;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> x >> y;
    a[x].push_back(make_pair(y, i));
    if (x) b.push_back(make_pair(y, i));
  }
  
  sort(b.begin(), b.end());
  if (!b.empty())
    segmenTree = new SegmentTree(0, b.size() - 1);
  for (int i = 0; i < int(b.size()); i++)
  {
    minCost[i + 1] = minCost[i] + b[i].first;
    segmenTree -> update(i, b[i].first, 1);
    pos[b[i].second] = i;
  }
    
  for (int i = 1; i <= MAX_A; i++)
  {
    sort(a[i].begin(), a[i].end(), greater< pair<int,int> >());
    maxOther = max(maxOther, int(a[i].size()));
    
    for (int j = 0; j < int(a[i].size()); j++)
      votes[j + 1].push_back(a[i][j]);
  }
  
  int myVotes = a[0].size();
  if (myVotes > maxOther)
  {
    cout << 0 << endl;
    return 0;
  }
  
  int ans = oo, sumCost = 0, sumVote = 0;
  for (int target = min(n, maxOther + 1); target > myVotes; target--)
  {
    for (int i = 0; i < int(votes[target].size()); i++)
    {
      sumCost += votes[target][i].first;
      sumVote++;
      int id = pos[votes[target][i].second];
      segmenTree -> update(id, b[id].first, -1);
    }
    
    int curCost = sumCost;
    if (myVotes + sumVote < target)
      curCost += segmenTree -> search(target - myVotes - sumVote);
      
    ans = min(ans, curCost);
  }
  
  cout << ans << endl;
}