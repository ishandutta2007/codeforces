#include <math.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <sstream>


using namespace std;


const int prime_cnt = 7;
const int primes[7] = {2, 3, 5, 7, 11, 13, 17};


struct target {
  int num;
  int aa[prime_cnt];
  int point;
  bool operator < (const target & another) const {
    return point < another.point;
  }
};


int cnt;
int aa[prime_cnt];
target t[100000];


void search(int idx, int sum, int limit, int r) {
  if (idx == r) {
    t[cnt].num = sum;
    t[cnt].point = 0;
    for (int i = 0; i < r; i++) {
      t[cnt].aa[i] = aa[i];
      t[cnt].point -= (aa[i] > 0) * 2000;
    }
    t[cnt].point -= cnt % 1181;
    cnt ++;
    return;
  }
  aa[idx] = 0;
  while (sum <= limit) {
    search(idx + 1, sum, limit, r);
    sum *= primes[idx];
    aa[idx]++;
  }
}

 
int main() {
  int k;
  cin >> k;
  int limit = 2 * k * k;
  int r = 0;
  for (int r = 1; r <= prime_cnt; r++) {
    cnt = 0;
    search(0, 1, limit, r);
    if (cnt >= k) {
      break;
    }
  }
  sort(t, t + cnt);
  for (int i = 0; i < k; i++) {
    cout << t[i].num << " ";
  }
  cout << endl;
  return 0;
}