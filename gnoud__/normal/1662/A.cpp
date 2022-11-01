#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int T; cin>>T; while(T--) {
        int n; cin >> n;
        vector<int> best(11, -1);
        while(n--) {
            int b, d;
            cin >> b >> d;
            best[d] = max(best[d], b);
        }

        int sum = 0;
        for (int i = 1; i <= 10; ++i) {
            if (best[i] < 0) {
                sum = -1;
                break;
            }
            sum += best[i];
        }
        if (sum < 0)
            cout << "MOREPROBLEMS\n";
        else
            cout << sum << "\n";
    }
}