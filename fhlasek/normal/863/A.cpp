/* Written by Filip Hlasek 2017 */
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <iostream>

#define FOR(i, a, b)   for (int i = (a); i <= (b); i++)
#define FORD(i, a, b)  for (int i = (a); i >= (b); i--)
#define REP(i, b)      for (int i =  0 ; i <  (b); i++)

using namespace std;

bool is_palindrome(int N) {
  int d[20], D = 0;
  while (N) { d[D++] = N % 10; N /= 10; }
  REP(i, D) if (d[i] != d[D - 1 - i]) return false;
  return true;
}

int main(int argc, char *argv[]) {
  int N;
  scanf("%d", &N);
  while (N % 10 == 0) N /= 10;
  printf("%s\n", is_palindrome(N) ? "YES" : "NO");
  return 0;
}