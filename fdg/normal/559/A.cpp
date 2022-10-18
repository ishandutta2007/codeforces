#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

int get(int x) {
  return x * x;
}

int main() {
  int arr[6] = {0};
  for (int i = 0; i < 6; ++i) {
    cin >> arr[i];
  }
  int sd = arr[0] + arr[1] + arr[2];
  cout << get(sd) - get(arr[0]) - get(arr[2]) - get(arr[4]) << endl;
  return 0;
}