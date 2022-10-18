/* Written by Filip Hlasek 2014 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

priority_queue<long long> pq1, pq2, pq3;

int main(int argc, char *argv[]) {
  int k, n1, n2, n3, t1, t2, t3;
  scanf("%d%d%d%d%d%d%d", &k, &n1, &n2, &n3, &t1, &t2, &t3);

  REP(i, n1) pq1.push(0);
  REP(i, n2) pq2.push(0);
  REP(i, n3) pq3.push(0);

  REP(i, k) {
    long long s1 = -pq1.top(), s2 = -pq2.top(), s3 = -pq3.top();
    pq1.pop(); pq2.pop(); pq3.pop();
    long long start = max(s1, max(s2 - t1, s3 - t1 - t2));
    pq1.push(-start-t1);
    pq2.push(-start-t1-t2);
    pq3.push(-start-t1-t2-t3);
    if (i == k - 1) cout << start + t1 + t2 + t3 << endl;
  }

  return 0;
}