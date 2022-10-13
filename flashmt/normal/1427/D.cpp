#include <bits/stdc++.h>
using namespace std;

void doOp(vector<int> op, vector<int> &a)
{
  vector<int> res;
  int curId = a.size();
  for (int i = int(op.size()) - 1; i >= 0; i--)
  {
    curId -= op[i];
    for (int j = 0; j < op[i]; j++)
      res.push_back(a[curId + j]);
  }
  a = res;
  // cout << "op: ";
  // for (int x : op) cout << x << ' ';
  // cout << endl;
  // cout << "  a: ";
  // for (int x : a)
  //   cout << x << ' ';
  // cout << endl << endl;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> a[i];
    a[i]--;
  }

  vector<vector<int>> ans;
  while (1)
  {
    int l = -1, r = -1;
    vector<int> id(n);
    for (int i = 0; i < n; i++)
      if (a[i] != i)
      {
        if (l < 0)
          l = i;
        r = i;
        id[a[i]] = i;
      }

    if (l < 0)
      break;

    vector<int> op1, op2;
    if (id[l] < id[r])
    {
      if (l)
        op1.push_back(l);
      op1.push_back(id[l] - l + 1);
      if (id[r] - 1 > id[l])
        op1.push_back(id[r] - 1 - id[l]);
      op1.push_back(r - id[r] + 1);
      if (r < n - 1)
        op1.push_back(n - 1 - r);

      if (r < n - 1)
        op2.push_back(n - 1 - r);
      op2.push_back(1);
      if (r - 1 > l)
        op2.push_back(r - 1 - l);
      op2.push_back(1);
      if (l)
        op2.push_back(l);
    }
    else
    {
      if (l)
        op1.push_back(l);
      if (id[r] > l)
        op1.push_back(id[r] - l);
      op1.push_back(r - id[r] + 1);
      if (r < n - 1)
        op1.push_back(n - 1 - r);

      if (op1.size() == 1)
      {
        op1 = {1};
        if (id[l] - 1 > id[r])
          op1.push_back(id[l] - 1 - id[r]);
        op1.push_back(r - id[l] + 1);
      }
      else
      {
        if (r < n - 1)
          op2.push_back(n - 1 - r);
        op2.push_back(1);
        if (id[l] - 1 > id[r])
          op2.push_back(id[l] - 1 - id[r]);
        op2.push_back(r - id[l] + 1 + id[r] - l);
        if (l)
          op2.push_back(l);
      }
    }

    doOp(op1, a);
    ans.push_back(op1);
    if (!op2.empty())
    {
      doOp(op2, a);
      ans.push_back(op2);
    }
  }

  cout << ans.size() << endl;
  for (auto op : ans)
  {
    cout << op.size();
    for (int x : op)
      cout << ' ' << x;
    cout << endl;
  }
}