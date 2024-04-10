#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
#include <stack>
#include <queue>
using namespace std;
const int mod =  998244353;
int n, m;
int main()
{
    scanf("%d %d", &n, &m);
    long long ans = 4;
    for (int i = 1; i <= n + m -  2;  i++)
        ans = ans * 2 % mod;
    printf("%lld\n", ans);
    return 0;
}