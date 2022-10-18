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
using namespace std;
typedef long long ll;
typedef long double ld;

int gcd(int aa, int bb) {
    return bb ? gcd(bb, aa % bb) : aa;
}

int n,l[999],c[999];
map<int,int> mp,mp2;
priority_queue< pair<int,int> > q;

int main()
{
    scanf("%d",&n);
    for (int i = 1; i <= n; ++i) scanf("%d",&l[i]);
    for (int i = 1; i <= n; ++i) scanf("%d",&c[i]);
    mp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        mp2 = mp;
        for (map<int,int>::iterator it = mp.begin(); it != mp.end(); ++it) {
            int curidx = (*it).first;
            int cursum = (*it).second;
            int newidx = gcd(curidx, l[i]);
            int newsum = cursum + c[i];
            if (!mp2[newidx]) mp2[newidx] = newsum;
            else mp2[newidx] = min(mp2[newidx], newsum);
        }
        mp = mp2;
    }
    if (!mp[1]) printf("-1");
    else printf("%d",mp[1]);

    return 0;
}