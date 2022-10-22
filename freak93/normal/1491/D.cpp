#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    int Q; cin >> Q;
    vector<int> have, need;
    while (Q--) {
        have.clear();
        need.clear();
        int U, V; cin >> U >> V;
        for (int i = 0; i <= 30; ++i)
            if ((1 << i) & U)
                have.push_back(i);
        for (int i = 0; i <= 30; ++i)
            if ((1 << i) & V)
                need.push_back(i);

        if (need.size() > have.size()) {
            cout << "NO\n";
            continue;
        }

        while (!need.empty() && have.back() == need.back()) {
            have.pop_back();
            need.pop_back();
        }

        if (!need.empty() && need.back() < have.back()) {
            cout << "NO\n";
            continue;
        }

        if (!need.empty()) {
            need.pop_back();
            while (have.size() > need.size())
                have.pop_back();
        } else if (!have.empty()) {
            cout << "NO\n";
            continue;
        }
        bool good = true;
        for (int i = 0; i < int(have.size()); ++i)
            if (have[i] > need[i])
                good = false;
        if (good)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}