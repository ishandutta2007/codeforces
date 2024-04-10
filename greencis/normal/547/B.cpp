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

int n,a[200105],ans[200105];
priority_queue< pii > q;
set<int> s, sr;

int leftmargin(int idx) {
    set<int>::iterator it = sr.lower_bound(-idx);
    if (it == sr.end()) return 1;
    return -(*it) + 1;
}

int rightmargin(int idx) {
    set<int>::iterator it = s.lower_bound(idx);
    if (it == s.end()) return n;
    return (*it) - 1;
}

int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d",&a[i]);
        q.push(make_pair(-a[i],i));
    }

    while (!q.empty()) {
        pii qqq = q.top();
        q.pop();
        int lge = leftmargin(qqq.second);
        int rge = rightmargin(qqq.second);
        s.insert(qqq.second);
        sr.insert(-qqq.second);
        ans[rge-lge+1] = max(ans[rge-lge+1], -qqq.first);
    }

    for (int i = n-1; i >= 1; --i) {
        ans[i] = max(ans[i], ans[i+1]);
    }

    for (int i = 1 ; i<= n;++i)
        printf("%d ",ans[i]);

    return 0;
}