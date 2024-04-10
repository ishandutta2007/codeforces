// School Personal Contest #1 
// Problem F -- Smart Boy
#include <map>
#include <string>
#include <cstdio>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 222;
const int M = 22222;

struct Result {
    bool win;
    int first, second;
   
    Result () : win(false), first(0), second(0) {}
    Result (bool a, int b, int c) : win(a), first(b), second(c) {}
};

bool operator < (const Result &a, const Result &b) {
    if (a.win != b.win) {
        return a.win < b.win;
    }
    if (a.first != b.first) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int n, cnt[M], strCnt;
string buf[N], str[M];
Result dp[M];
map<string, int> id;

bool cmp (const string &a, const string &b) {
    if (a.size() == b.size()) {
        return a < b;
    }
    return a.size() < b.size();
}

void update (Result &x, const string &s) {
    if (id.count(s) == 0) {
        return;
    }
    int tmp = id[s];
    x = max(x, Result(not dp[tmp].win, 
                dp[tmp].second + cnt[tmp], dp[tmp].first));
}

int main () {
    cin >> n;
    strCnt = 0;
    str[strCnt ++] = "";
    for (int i = 0; i < n; ++ i) {
        cin >> buf[i];
        for (int j = 0; j < (int)buf[i].size(); ++ j) {
            for (int k = 1; j + k <= (int)buf[i].size(); ++ k) {
                str[strCnt ++] = buf[i].substr(j, k);
            }
        }
    }
    sort(str, str + strCnt, cmp);
    id.clear();
    memset(cnt, 0, sizeof(cnt));
    id[""] = 0;
    cnt[0] += 1;
    int tmpStrCnt = 1;
    for (int i = 1; i < strCnt; ++ i) {
        if (str[tmpStrCnt - 1] != str[i]) {
            id[str[i]] = tmpStrCnt;
            str[tmpStrCnt ++] = str[i];
        }
    }        
    strCnt = tmpStrCnt; 
    for (int i = 0; i < strCnt; ++ i) {
        cnt[i] = 0;
        for (int j = 0; j < n; ++ j) {
            if ((int)buf[j].find(str[i]) != -1) {
                cnt[i] += 1;
            }
        }
        int sigma = 0, maximum = 0;
        for (int j = 0; j < (int)str[i].size(); ++ j) {
            sigma += str[i][j] - 'a' + 1;
            maximum = max(maximum, str[i][j] - 'a' + 1);
        }
        cnt[i] += sigma * maximum;
    }
    for (int i = strCnt - 1; i > -1; -- i) { 
        for (int j = 0; j < 26; ++ j) {
            string tmp(1, 'a' + j);
            update(dp[i], tmp + str[i]);
            update(dp[i], str[i] + tmp);
        }
    }
    printf("%s\n%d %d\n", dp[0].win? "First": "Second", dp[0].first, dp[0].second);
    return 0;
}