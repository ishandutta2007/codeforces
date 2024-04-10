#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, k;
queue <int> myQueue;
vector <int> lucky;

bool isLucky (int n) {
    while (n) {
        int r = n % 10;
        if (r != 4 && r != 7) {
            return false;
        }
        n /= 10;
    }
    return true;
}

int getNumber (int n, int k, int i) {
    if (n > 15) {
        if (i <= n - 15) {
            return i;
        }
        return getNumber(15, k, i - (n - 15)) + (n - 15);
    }
    int bak = i;
    int per[16], ret[16];
    bool vis[16];
    long long cnt[16];
    cnt[0] = 1;
    for (int i = 1; i <= n; ++ i) {
        cnt[i] = cnt[i - 1] * i;
    }
    for (int i = 1; i <= n; ++ i) {
        int j = 1;
        while (cnt[n - i] < k) {
            k -= cnt[n - i];
            j ++;
        }
        per[i] = j;
    }
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; ++ i) {
        int j = 0;
        while (per[i]) {
            j ++;
            while (vis[j]) {
                j ++;
            }
            per[i] --;
        }
        vis[j] = true;
        ret[i] = j ++;
    }
    return ret[bak];
}

int main () {    
    scanf("%d%d", &n, &k);
    myQueue.push(4);
    myQueue.push(7);
    while (!myQueue.empty()) {
        long long cur = myQueue.front();
        myQueue.pop();
        lucky.push_back(cur);
        if (cur * 10 + 4 <= n) {
            myQueue.push(cur * 10 + 4);
        }
        if (cur * 10 + 7 <= n) {
            myQueue.push(cur * 10 + 7);
        }
    }
    if (n <= 15) {
        long long cnt = 1;
        for (int i = 1; i <= n; ++ i) {
            cnt *= i;
        }
        if (cnt < k) {
            printf("-1\n");
            return 0;
        }
    }
    sort(lucky.begin(), lucky.end());
    int result = 0;
    for (vector <int> :: iterator iter = lucky.begin();
            iter != lucky.end(); ++ iter) {
        result += isLucky(getNumber(n, k, *iter));
    }
    printf("%d\n", result);
    return 0;
}