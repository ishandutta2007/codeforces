#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n,T;
priority_queue< pair<int,int> > q;

int main()
{
    scanf("%d%d",&n,&T);
    for (int i = 0; i < n; ++i) {
        int a,b;
        scanf("%d%d",&a,&b);
        if (T-a >= 0)
            q.push(make_pair(T-a, b));
    }

    int ans = 0;
    while (q.size()) {
        if (q.size() == 1 || q.top().first == 0) {
            ans = max(ans, q.top().second);
            q.pop();
        } else {
            pii qqq1 = q.top(); q.pop();
            pii qqq2 = q.top(); q.pop();
            if (qqq1.first != qqq2.first) { qqq1.first--; q.push(qqq1); q.push(qqq2); continue; }
            q.push(make_pair(qqq1.first - 1, qqq1.second + qqq2.second));
        }
    }
    cout << ans;

    return 0;
}