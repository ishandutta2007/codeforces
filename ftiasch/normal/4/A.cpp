// Codeforecs Beta Round #4
// Problem A -- Watermelon
#include <cstdio>

using namespace std;

int n;

int main()
{
  scanf("%d", &n);
  printf((n & 1 || n == 2)? "NO\n": "YES\n");
  return 0;
}