#include <bits/stdc++.h>

using namespace std;
#define f0r(a, b) for (a = 0; a < b; a++)
#define f1r(a, b, c) for (a = b; a < c; a++)
#define ms(arr, v) memset(arr, v, sizeof(arr))
#define pb push_back
int i, j, k, q;
typedef long long ll;

int arr[200200];

int main() {
  ll n;
  cin >> n;
  f0r(i, n) cin >> arr[i];

  int lp = 0, rp = n - 1, i = -1, len = 0;
  string seq = "";
  while (lp <= rp) {
    if (arr[rp] > i && arr[lp] <= i) {
      len++;
      i = arr[rp];
      rp--;
      seq += "R";
    } else if (arr[lp] > i && arr[rp] <= i) {
      len++;
      i = arr[lp];
      lp++;
      seq += "L";
    } else if (arr[lp] < arr[rp] && arr[lp] > i) {
      len++;
      i = arr[lp];
      lp++;
      seq += "L";
    } else if (arr[rp] > i) {
      len++;
      i = arr[rp];
      rp--;
      seq += "R";
    } else break;
  }

  cout << len << endl << seq << endl;
}