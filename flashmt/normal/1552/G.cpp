#include <bits/stdc++.h>
using namespace std;

int n, k;
long long steps[10];

void go(int i, long long valueMask, long long assignedMask)
{
  if (i == k)
  {
    int numOne = __builtin_popcountll(valueMask);
    if ((1LL << n - numOne) - 1 + valueMask != (1LL << n) - 1)
    {
      cout << "REJECTED" << endl;
      exit(0);
    }
    return;
  }

  long long existingMask = steps[i] & assignedMask;
  int existingOne = __builtin_popcountll(valueMask & existingMask);
  int newBit = __builtin_popcountll(steps[i] ^ existingMask);

  // sort assigned bits
  valueMask &= ((1LL << n) - 1) ^ existingMask;
  long long curMask = steps[i];
  while (existingOne--)
  {
    int rightmost = 63 - __builtin_clzll(curMask);
    valueMask |= 1LL << rightmost;
    curMask ^= 1LL << rightmost;
  }

  // assign new bits
  assignedMask |= steps[i];
  for (int j = 0; j <= newBit; j++)
  {
    go(i + 1, valueMask, assignedMask);
    if (j == newBit)
      break;
    int rightmost = 63 - __builtin_clzll(curMask);
    valueMask |= 1LL << rightmost;
    curMask ^= 1LL << rightmost;
  }
}

int main()
{
  cin >> n >> k;
  if (n == 1)
  {
    cout << "ACCEPTED" << endl;
    return 0;
  }

  long long maskAll = 0;
  for (int i = 0; i < k; i++)
  {
    int sz;
    cin >> sz;
    while (sz--)
    {
      int x;
      cin >> x;
      steps[i] |= 1LL << x - 1;
    }
    maskAll |= steps[i];
  }

  if (maskAll != (1LL << n) - 1)
  {
    cout << "REJECTED" << endl;
    return 0;
  }
  go(0, 0, 0);
  cout << "ACCEPTED" << endl;
}