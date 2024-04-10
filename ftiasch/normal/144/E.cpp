// Codeforces Round #103
// Problem E -- Competition
#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 111111;

int n, m;
pair <pair <int, int>, int> intervals[N];
priority_queue <pair <int, int> > heap;
vector <int> result;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++ i) {
        int r, c;
        scanf("%d%d", &r, &c);
        intervals[i] = make_pair(make_pair(n - r, c - 1), i);
    }
    sort(intervals, intervals + m);
    for (int i = 0, j = 0; i < n; ++ i) {
        while (j < m && intervals[j].first.first <= i) {
            heap.push(make_pair(-intervals[j].first.second, 
                        intervals[j].second));
            j ++;
        }
        while (!heap.empty()) {
            pair <int, int> ret = heap.top();
            heap.pop();
            if (-ret.first >= i) {
                result.push_back(ret.second);
                break;
            }
        }
    }
    sort(result.begin(), result.end());
    printf("%d\n", (int)result.size());
    for (int i = 0; i < (int)result.size(); ++ i) {
        printf("%d%c", result[i] + 1, i + 1 == (int)result.size()? 
                '\n': ' ');
    }
    return 0;
}