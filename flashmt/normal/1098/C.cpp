#include <bits/stdc++.h>
using namespace std;

long long getSum(int depth, long long cnt, int rem, int branch)
{
  return cnt ? depth * cnt + getSum(depth + 1, min(rem - cnt, cnt * branch), rem - cnt, branch) : 0;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n;
  long long s;
  cin >> n >> s;
  if (s < n * 2 - 1 || s > n * (n + 1LL) / 2)
  {
    cout << "No" << endl;
    return 0;
  }

  cout << "Yes" << endl;
  if (s == n * (n + 1LL) / 2)
  {
    for (int i = 1; i < n; i++)
      cout << i << ' ';
    return 0;
  }

  int low = 2, high = n - 1, branch = n;
  while (low <= high)
  {
    int mid = (low + high) / 2;
    if (s < getSum(1, 1, n, mid)) low = mid + 1;
    else
    {
      branch = min(branch, mid);
      high = mid - 1;
    }
  }

  vector<int> cntDepth(n + 1, 0), childCnt(n + 1, 0), iter(n + 1);
  cntDepth[1] = iter[1] = 1;
  long long sum = 1;
  int used = 1;
  for (int depth = 2; used < n; depth++)
  {
    int low = 1, high = n - used;
    while (low <= high)
    {
      int mid = (low + high) / 2;
      if (getSum(depth, mid, n - used, branch) + sum <= s)
      {
        cntDepth[depth] = mid;
        high = mid - 1;
      }
      else low = mid + 1;
    }

    iter[depth] = used + 1;
    used += cntDepth[depth];
    sum += 1LL * cntDepth[depth] * depth;

    for (int i = 0; i < cntDepth[depth]; i++)
    {
      cout << iter[depth - 1] << ' ';
      if (++childCnt[iter[depth - 1]] == branch)
        iter[depth - 1]++;
    }
  }
  assert(sum == s);
}