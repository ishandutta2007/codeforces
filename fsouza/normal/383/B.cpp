#include <iostream>
#include <cstdio>
#include <algorithm>
#include <numeric>
#include <climits>
#include <sstream>
#include <cstring>
#include <cassert>
#include <vector>
#include <stack>
#include <queue>
#include <cmath>
#include <map>
#include <set>

#define INF (INT_MAX/2)
#define MAXM 100000

typedef long long lint;

using namespace std;

pair <int, int> xy[MAXM];

vector <pair <int, int> > ranges_union(const vector <pair <int, int> > &ranges)
{
        vector <pair <int, int> > ret;

        //assert(sorted(ranges));

        for (int i = 0; i < (int)ranges.size(); i++) {
                if (!ret.empty() && ret.back().second >= ranges[i].first-1)
                        ret.back().second = max(ret.back().second, ranges[i].second);
                else
                        ret.push_back(ranges[i]);
        }

        return ret;
}

int main(int argc, char ** argv)
{
        int n, m;

        scanf("%d %d", &n, &m);

        for (int i = 0; i < m; i++) {
                int x, y;
                scanf("%d %d", &x, &y);
                xy[i] = make_pair(x, y);
        }
        sort(xy, xy + m);

        int i = 0;
        vector <pair <int, int> > ranges(1, make_pair(1, 1));
        for (int x = 1; x <= n; x++) {
                while (i < m && xy[i].first < x) i++;

                if (i == m || xy[i].first != x) {
                        if (!ranges.empty()) ranges = vector <pair <int, int> >(1, make_pair(ranges.front().first, n));
                        if (i < m) x = xy[i].first-1; else x = n;
                } else {
                        vector <pair <int, int> > newranges;
                        int lastend = 0;

                        for (int j = 0; j < (int)ranges.size(); j++) {
                                int start = max(lastend+1, ranges[j].first), end = ranges[j].second;

                                if (start > end) continue;
                                while (i < m && xy[i].first == x && xy[i].second < start) i++;

                                while (i < m && xy[i].first == x && xy[i].second <= end) {
                                        if (start <= xy[i].second-1) {
                                                newranges.push_back(make_pair(start, xy[i].second-1));
                                                lastend = xy[i].second-1;
                                        }

                                        start = xy[i].second+1;
                                        while (i < m && xy[i].first == x && xy[i].second < start) i++;
                                }

                                if (start <= end) {
                                        if (i < m && xy[i].first == x) end = xy[i].second-1;
                                        else end = n;

                                        newranges.push_back(make_pair(start, end));
                                        lastend = end;
                                }
                        }

                        ranges = ranges_union(newranges);
                }
        }

        if (ranges.empty() || ranges.back().second < n) printf("-1\n");
        else printf("%d\n", 2 * (n - 1));

        return 0;
}