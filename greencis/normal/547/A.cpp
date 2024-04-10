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

#define x1 dkjhfjdshfldsjs
#define x2 dkjhfjfdsfddsjs
#define y1 zkjhfjdshfldsjs
#define y2 qkjhfjdshfldsjs

int m,h1,a1,h2,a2,x1,x2,y1,y2;

void ans(ll qqq) {
    cout << qqq << endl;
    exit(0);
}

int main()
{
    cin >> m >> h1 >> a1 >> x1 >> y1 >> h2 >> a2 >> x2 >> y2;

    int first1 = 0, second1 = 0;
    int cur = h1;
    for (int i = 0; i <= 10000000; ++i) {
        if (cur == a1) {
            if (first1 == 0) first1 = i;
            else { second1 = i; break; }
        }
        cur = int((ll(x1) * ll(cur) + ll(y1)) % ll(m));
    }

    int first2 = 0, second2 = 0;
    cur = h2;
    for (int i = 0; i <= 10000000; ++i) {
        if (cur == a2) {
            if (first2 == 0) first2 = i;
            else { second2 = i; break; }
        }
        cur = int((ll(x2) * ll(cur) + ll(y2)) % ll(m));
    }

    if (first1 == 0 || first2 == 0) ans(-1);
    if (second1 == 0 && second2 == 0) {
        if (first1 == first2) ans(first1);
        else ans(-1);
    }
    if (second1 == 0) {
        int curans = (first1 - first2) / (second2 - first2);
        if ((first1 - first2) % (second2 - first2) == 0 && curans >= 0) ans(first1);
        else ans(-1);
    } else if (second2 == 0) {
        int curans = (first2 - first1) / (second1 - first1);
        if ((first2 - first1) % (second1 - first1) == 0 && curans >= 0) ans(first2);
        else ans(-1);
    }

    second1 -= first1;
    second2 -= first2;

    /// cerr << "LOL!";

    ll qqq = first2 - first1;
    for (int i = 0; i <= 10000000; ++i) {
        if (qqq >= 0ll && qqq % ll(second1) == 0ll)
            ans(ll(second1) * ll(qqq / ll(second1)) + ll(first1));
        qqq += ll(second2);
    }
    ans(-1);

    return 0;
}