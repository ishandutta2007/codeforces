#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <numeric>

using namespace std;

typedef long long lint;

int main() {
  int n;
  cin >> n;
  string field;
  cin >> field;

  int first = -1, last = -1;
  for (int i = 0; i < n; i++) {
    if (field[i] != '.' && first == -1) first = i;
    if (field[i] == field[first]) last = i;
  }

  int start, end;

  if (count(field.begin(), field.end(), 'R') > 0) {
    start = first;
    if (count(field.begin(), field.end(), 'L') == 0)
      end = last+1;
    else
      end = last;
  } else {
    start = last;
    end = first-1;
  }

  cout << start+1 << " " << end+1 << endl;

  return 0;
}