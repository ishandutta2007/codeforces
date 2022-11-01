#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int INF = 1e9;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int& x : p) {
            cin >> x;
        }
        vector<int> nextBigger(n), nextLower(n);
        stack<pair<int, int>> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && p[i] > st.top().first) {
                nextBigger[st.top().second] = i;
                st.pop();
            }
            st.push({p[i], i});
        }
        st = stack<pair<int, int>>();
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && p[i] < st.top().first) {
                nextLower[st.top().second] = i;
                st.pop();
            }
            st.push({p[i], i});
        }
        int pos = 0;
        int len = 0;
        while (pos != n - 1) {
            int can = pos + 1;
            if (p[pos] < p[pos + 1]) {
                while (true) {
                    int newCan = nextBigger[can];
                    if (newCan == 0 || (nextLower[pos] != 0 && newCan >= nextLower[pos])) {
                        break;
                    }
                    can = newCan;
                }
            } else {
                while (true) {
                    int newCan = nextLower[can];
                    if (newCan == 0 || (nextBigger[pos] != 0 && newCan >= nextBigger[pos])) {
                        break;
                    }
                    can = newCan;
                }
            }
            pos = can;
            ++len;
        }
        cout << len << '\n';
    }
    return 0;
}