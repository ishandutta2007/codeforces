#include <fstream>
#include <vector>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int n,a[300105],logs[300105];
int tg[301005][20],tm[301005][20];

void build() {
    for (int i = 0; i < n; ++i) tg[i][0] = tm[i][0] = a[i];
    for (int i = 1; (1 << i) <= n; ++i) {
        for (int j = 0; j + (1 << (i-1)) - 1 < n; ++j) {
            tm[j][i] = min(tm[j][i-1], tm[j + (1 << (i-1))][i-1]);
            tg[j][i] = gcd(tg[j][i-1], tg[j + (1 << (i-1))][i-1]);
        }
    }
    int h = 1, lvl = 0;
    for (int i = 1; i <= n+5; ++i) {
        if (h < i)
            h <<= 1, ++lvl;
        logs[i] = lvl;
    }
}

int gget(int l, int r) {
    if (l == r) return a[l];
    int len = logs[(r - l + 2) >> 1];
    return gcd(tg[l][len], tg[r - (1 << len) + 1][len]);
}

int mget(int l, int r) {
    if (l == r) return a[l];
    int len = logs[(r - l + 2) >> 1];
    return min(tm[l][len], tm[r - (1 << len) + 1][len]);
}

vector<int> ans;

bool check(int len) {
    ans.clear();
    for (int i = 0; i <= n - len; ++i) {
        if (gget(i, i + len - 1) == mget(i, i + len - 1)) ans.push_back(i + 1);
    }
    return ans.size();
}

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) scanf("%d",&a[i]);
    build();
    int l = 1, r = n;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    check(l);
    printf("%d %d\n",ans.size(),l-1);
    for (int i = 0; i < ans.size(); ++i)
        printf("%d ",ans[i]);

    return 0;
}