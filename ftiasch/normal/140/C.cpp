#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

const int N = 111111;

int n, a[N], tmpRes[3 * N];
map <int, int> cnt;
vector <pair <int, int> > nums;
vector <int> res[N];

bool check(int limit) {
    int i = 0;
    for (vector <pair <int, int> > :: iterator iter = nums.begin(); iter != nums.end(); ++ iter) {
        if (i == 3 * limit) {
            break;
        }
        int tmp = min(iter->first, limit);
        while (tmp > 0 && i < 3 * limit) {
            tmp --;
            tmpRes[i ++] = iter->second;
        }
    }
    return i == 3 * limit;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", a + i);
        cnt[a[i]] ++;
    }
    for (map <int, int> :: iterator iter = cnt.begin(); iter != cnt.end(); ++ iter) {
        nums.push_back(make_pair(iter->second, iter->first));
    }
    sort(nums.begin(), nums.end(), greater <pair <int, int> > ());
    int lower = 0;
    int upper = n;
    while (lower < upper) {
        int mider = (lower + upper + 1) >> 1;
        if (check(mider)) {
            lower = mider;
        } else {
            upper = mider - 1;
        }
    }
    printf("%d\n", lower);
    check(lower);
    for (int i = 0; i < lower; ++ i) {
        res[i].clear();
    }
    for (int i = 0; i < 3 * lower; ++ i) {
        res[i % lower].push_back(tmpRes[i]);
    }
    for (int i = 0; i < lower; ++ i) {
        sort(res[i].begin(), res[i].end(), greater <int> ());
        printf("%d %d %d\n", res[i][0], res[i][1], res[i][2]);
    }
    return 0;
}