#include <bits/stdc++.h>
using namespace std;

struct Mod
{
  int prime, power, value;
};

int n, a[100100], numMod, inv[10][100100];
long long inv2[10];
pair <int, int> maxPowers[10][100100];
vector <Mod> mods;
vector <int> powers[10];

long long mulInv(long long a, long long b) 
{
  long long b0 = b, x0 = 0, x1 = 1;
 
  if (b == 1)
    return 1;
 
  while (a > 1) 
  {
    long long q = a / b, amb = a % b;
    a = b;
    b = amb;
    long long xqx = x1 - q * x0;
    x1 = x0;
    x0 = xqx;
  }
 
  if (x1 < 0)
    x1 += b0; 
  return x1;
}

struct SegmentTree 
{
  int low, mid, high, id, power, value, coPrimeValue, save;
  SegmentTree *l, *r;

  SegmentTree(int low, int high, int a[], int id): low(low), high(high), id(id) 
  {
    mid = (low + high) / 2;
    save = 1;
    if (low == high)
    {
      power = maxPowers[id][a[low]].first;
      coPrimeValue = a[low] / maxPowers[id][a[low]].second % mods[id].value;
      value = a[low] % mods[id].value;
    }
    else
    {
      l = new SegmentTree(low, mid, a, id);
      r = new SegmentTree(mid + 1, high, a, id);
      value = (l -> value + r -> value) % mods[id].value;
      coPrimeValue = 1;
      power = 0;
    }
  }

  int addMod(int x, int y)
  {
    int res = x + y;
    if (res >= mods[id].value)
      return res - mods[id].value;
    return res;
  }

  void updateChildren()
  {
    l -> save = 1LL * l -> save * save % mods[id].value;
    l -> value = 1LL * l -> value * save % mods[id].value;
    l -> coPrimeValue = 1LL * l -> coPrimeValue * coPrimeValue % mods[id].value;
    l -> power += power;
    r -> save = 1LL * r -> save * save % mods[id].value;
    r -> value = 1LL * r -> value * save % mods[id].value;
    r -> coPrimeValue = 1LL * r -> coPrimeValue * coPrimeValue % mods[id].value;
    r -> power += power;
    power = 0;
    coPrimeValue = save = 1;
  }

  void multiply(int x, int y, int v)
  {
    if (low == x && high == y)
    {
      value = 1LL * value * v % mods[id].value;
      save = 1LL * save * v % mods[id].value;
      power += maxPowers[id][v].first;
      coPrimeValue = 1LL * coPrimeValue * (v / maxPowers[id][v].second) % mods[id].value;
      return;
    }

    updateChildren();
    
    if (x <= mid)
      l -> multiply(x, min(y, mid), v);
    if (mid < y)
      r -> multiply(max(x, mid + 1), y, v);
    value = (l -> value + r -> value) % mods[id].value;
  }

  void divide(int x, int v)
  {
    if (low == high)
    {
      power -= maxPowers[id][v].first;
      coPrimeValue = 1LL * coPrimeValue * inv[id][v / maxPowers[id][v].second] % mods[id].value;
      if (power >= mods[id].power) value = 0;
      else value = 1LL * coPrimeValue * powers[id][power] % mods[id].value;
      return;
    }

    updateChildren();

    if (x <= mid) l -> divide(x, v);
    else r -> divide(x, v);
    value = addMod(l -> value, r -> value);
  }

  int getValue(int x, int y)
  {
    if (low == x && high == y)
      return value;

    updateChildren();

    int leftValue = 0, rightValue = 0;
    if (x <= mid)
      leftValue = l -> getValue(x, min(y, mid));
    if (mid < y)
      rightValue = r -> getValue(max(x, mid + 1), y);

    return addMod(leftValue, rightValue);
  }
} *tree[10];

void init(int m)
{
  for (int i = 2; i * i <= m; i++)
    if (m % i == 0)
    {
      int power = 0;
      long long value = i;
      while (m % value == 0)
      {
        power++;
        value *= i;
      }
      value /= i;
      m /= value;
      mods.push_back({i, power, int(value)});
    }

  if (m > 1)
    mods.push_back({m, 1, m});

  numMod = mods.size();
  
  for (int i = 0; i < numMod; i++)
    for (int j = 1; j <= 100000; j++)
    {
      int v = j;
      maxPowers[i][j] = {0, 1};
      while (v % mods[i].prime == 0)
      {
        v /= mods[i].prime; 
        maxPowers[i][j].first++;
        maxPowers[i][j].second *= mods[i].prime;
      }
      inv[i][j] = mulInv(v, mods[i].value);
    }

  for (int i = 0; i < numMod; i++)
  {
    int p = 1;
    for (int j = 0; j < numMod; j++)
      if (j != i)
        p *= mods[j].value;
    inv2[i] = mulInv(p, mods[i].value) * p;

    powers[i].push_back(1);
    for (int j = 1; j <= mods[i].power; j++)
      powers[i].push_back(powers[i].back() * mods[i].prime);
  }
}

int main()
{
  ios::sync_with_stdio(0);
  int type, x, y, v, m, q;
  cin >> n >> m;
  init(m);
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  
  for (int i = 0; i < numMod; i++)
    tree[i] = new SegmentTree(1, n, a, i);

  cin >> q;
  while (q--)
  {
    cin >> type >> x;
    if (type == 1)
    {
      cin >> y >> v;
      for (int i = 0; i < numMod; i++)
        tree[i] -> multiply(x, y, v);
    }
    else if (type == 2)
    {
      cin >> v;
      for (int i = 0; i < numMod; i++)
        tree[i] -> divide(x, v);
    }
    else
    {
      cin >> y;
      long long ans = 0;
      for (int i = 0; i < numMod; i++)
        ans = (ans + tree[i] -> getValue(x, y) * inv2[i]) % m;
      cout << ans << '\n';
    }
  }
}