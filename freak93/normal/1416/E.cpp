#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
#include <utility>
#include <cassert>

using namespace std;

static const int kInfinite = 1000 * 1000 * 1000;

int main() {
    ios::sync_with_stdio(false);
    int T; cin >> T;

    while (T--) {
        int best = 1;
        set< pair<int64_t, int64_t> > S;
        S.emplace(-kInfinite, kInfinite);

        int N; cin >> N;
        int A = 1;
        int64_t B = 0;
        
        while (N--) {
            int64_t X; cin >> X;
            assert(2 <= X && X <= kInfinite);
            B = B + A * X;
            A = -A;

            int64_t begin = A * 1 + B;
            int64_t end = A * (X - 1) + B;
            if (begin > end)
                swap(begin, end);

            while (!S.empty() && S.begin()->second < begin)
                S.erase(S.begin());
            while (!S.empty() && S.rbegin()->first > end)
                S.erase(*S.rbegin());
            if (!S.empty() && S.begin()->first < begin) {
                auto p = S.extract(S.begin());
                p.value().first = begin;
                S.insert(S.begin(), std::move(p));
            }
            if (!S.empty() && S.rbegin()->second > end) {
                auto p = S.extract(prev(S.end(), 1));
                p.value().second = end;
                S.insert(S.end(), std::move(p));
            }

             if (X % 2 == 0) {
                 int64_t mid = A * (X / 2) + B;
                 auto it = S.lower_bound(make_pair(mid + 1, mid));
                 if (it != S.begin()) {
                     --it;
                     assert(it->first <= mid);
                     if (it->second >= mid)
                         S.clear();
                     else 
                         ++best;
                 } else
                     ++best;
                S.emplace(mid, mid);
             } else {
                 ++best;
             }

             if (S.empty()) {
                 ++best;
                 S.emplace(begin, end);
             }
        }

        cout << best << "\n";
    }
}