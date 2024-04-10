#include <bits/stdc++.h>
using namespace std;

#define sc scanf
#define pr printf
#define pb push_back

typedef long long ll;
typedef vector<int> vi;

int main() {
    int n;
    map<string, int> fuck;
    fuck["00"] = 0;
    fuck["01"] = 1;
    fuck["10"] = 2;
    fuck["11"] = 3;
    string str;
    priority_queue<int> que[4];
    int x;
    cin >> n;
    while (n--) {
        cin >> str >> x;
        que[fuck[str]].push(x);
    }
    int res = 0;
    while (!que[1].empty() && !que[2].empty()) {
        res += que[1].top() + que[2].top();
        que[1].pop();
        que[2].pop();
    }
    if (que[1].empty()) {
        while (!que[2].empty()) {
            que[0].push(que[2].top());
            que[2].pop();
        }
    }
    else {
        while (!que[1].empty()) {
            que[0].push(que[1].top());
            que[1].pop();
        }
    }
    while (!que[0].empty() && !que[3].empty()) {
        res += que[0].top() + que[3].top();
        que[0].pop();
        que[3].pop();
    }
    while (!que[3].empty()) {
        res += que[3].top();
        que[3].pop();
    }
    cout << res << endl;
    return 0;
}