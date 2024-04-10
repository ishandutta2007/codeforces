#include <iostream>
#include <vector>

using namespace std;

int Queries = 0;

int Get(int pos) {
    ++Queries;
    cout << "? " << pos + 1 << endl;
    int x;
    cin >> x;
    return x - 1;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<bool> used(n);
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            if (!used[i]) {
                vector<int> cycle;
                int x = Get(i);
                while (!used[x]) {
                    cycle.push_back(x);
                    used[x] = true;
                    x = Get(i);
                }
                int sz = (int) cycle.size();
                for (int j = 0, nxt = (j + 1) % sz; j < sz; ++j, nxt = (nxt + 1) % sz) {
                    p[cycle[j]] = cycle[nxt];
                }
            }
        }
        cout << "! ";
        for (int i = 0; i < n; ++i) {
            cout << p[i] + 1 << ' ';
        }
        cout << '\n';
    }
    return 0;
}

/*
2
4
1
4
3
1
2
2
 */