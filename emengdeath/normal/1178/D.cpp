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
int n;
vector<pair<int, int> > ans;
bool isprime(int x) {
    for (int i = 2 ;(long long)i * i <= x;  i ++)
        if (!(x % i)) return 0;
    return 1;
}
int main()
{
    scanf("%d", &n);
    int x = n;
    for (int i = 1 ;i <= n; i ++)
        ans.push_back(make_pair(i, i % n + 1));
    int l = 1;
    while (!isprime(x)) {
        ans.push_back(make_pair(l, l + n / 2));
        ++l;
        x ++;
    }
    printf("%d\n", ans.size());
    for (auto u:ans)
        printf("%d %d\n", u.first, u.second);
    return 0;
}