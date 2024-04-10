#include <cstdio>
#include <algorithm>

using namespace std;

int main(void)
{
  int n, m;
  scanf("%d%d", &n, &m);
  puts(min(n, m) % 2 ? "Akshat" : "Malvika");

  return 0;
}