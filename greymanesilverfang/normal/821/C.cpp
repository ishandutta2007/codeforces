#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n, i = 1, ans = 0; cin >> n;
    stack<int> S;
    while (i <= n) {
        string order; cin >> order;
        if (order == "add") {
            int x; cin >> x;
            S.push(x);
        } else {
            if (S.top() == i)
                S.pop();
            else S.push(-i);
            i++;
        }
    }
    while (!S.empty()) {
        while (!S.empty() && S.top() < 0)
            S.pop();
        while (!S.empty() && S.top() > 0)
            S.pop();
        ans++;
    }
    cout << ans;
    return 0;
}