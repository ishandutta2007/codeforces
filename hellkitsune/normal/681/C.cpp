#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
char buf[15];
int x;
priority_queue<int, vector<int>, greater<int> > q;
vector<string> ans;

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    REP(i, n) {
        scanf("%s", buf);
        if (buf[0] == 'i') {
            scanf("%d", &x);
            q.push(x);
            ostringstream oss;
            oss << "insert " << x;
            ans.pb(oss.str());
        } else if (buf[0] == 'r') {
            if (q.empty()) {
                ans.pb("insert 1");
            } else {
                q.pop();
            }
            ans.pb("removeMin");
        } else {
            scanf("%d", &x);
            while (!q.empty() && q.top() < x) {
                ans.pb("removeMin");
                q.pop();
            }
            if (q.empty() || q.top() != x) {
                ostringstream oss;
                oss << "insert " << x;
                ans.pb(oss.str());
                q.push(x);
            }
            ostringstream oss;
            oss << "getMin " << x;
            ans.pb(oss.str());
        }
    }
    printf("%d\n", (int)ans.size());
    for (string s : ans) {
        printf("%s\n", s.c_str());
    }
    return 0;
}