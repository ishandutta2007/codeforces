#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <tuple>

using namespace std;

vector< tuple<int, int, int, int> > answer;
void solve(set< pair<int, int> > have, set< pair<int, int> > need, vector<int>& values) {
    if (have.size() == 0)
        return;

    auto cost = [&](pair<int, int> v) {
        int a = v.first;
        int b = v.second;
        if (a > b)
            swap(a, b);
        a = lower_bound(values.begin(), values.end(), a) - values.begin();
        b = lower_bound(values.begin(), values.end(), b) - values.begin();
        return min<int>(b - a, a - b + values.size());
    };

    pair<int, int> which(-1, -1);
    for (auto &p : need)
        if (which == make_pair(-1, -1) || cost(which) < cost(p))
            which = p;
    auto next = [&](int a) {
        auto it = lower_bound(values.begin(), values.end(), a);
        ++it;
        if (it == values.end())
            return values.front();
        return *it;
    };

    auto prev = [&](int a) {
        auto it = lower_bound(values.begin(), values.end(), a);
        if (it == values.begin())
            return values.back();
        --it;
        return *it;
    };

    int a = which.first;
    int b = which.second;
    if (a > b)
        swap(a, b);

    auto exists = [&](int a, int b) {
        return have.count(make_pair(a, b)) || have.count(make_pair(b, a)) || next(a) == b || prev(a) == b;
    };

    auto swap2 = [&](int x, int y, int a, int b) {
        answer.push_back(make_tuple(x, y, a, b));
        have.erase(make_pair(x, y));
        have.erase(make_pair(y, x));
        have.insert(make_pair(a, b));
    };

    if (!have.count(make_pair(a, b)) && !have.count(make_pair(b, a))) {
        int leftMost = prev(a);
        int rightMost = next(a);

        for (auto &p : have) {
            int u = p.first;
            int v = p.second;
            if (v == a)
                swap(u, v);
            if (u != a)
                continue;
            if (v > a && v < b)
                rightMost = max(rightMost, v);
            else {
                if (leftMost < a && v > b)
                    leftMost = v;
                else if (leftMost > b && v < a)
                    continue;
                else
                    leftMost = min(leftMost, v);
            }
        }
        do {
            bool repeat = true;
            for (auto &x : values)
                if (exists(x, leftMost) && exists(x, rightMost) && x != a) {
                    swap2(leftMost, rightMost, a, x);
                    if (x > a && x < b) {
                        rightMost = x;
                        break;
                    } else if (x != b) {
                        leftMost = x;
                        break;
                    } else
                        repeat = false;
                }
            if (!repeat)
                break;
        } while (true);
    }

    set< pair<int, int> > left, right, leftNeed, rightNeed;
    vector<int> vLeft, vRight;
    for (auto &p : have) {
        if (p == make_pair(a, b) || p == make_pair(b, a))
            continue;
        if (p.first >= a && p.first <= b && p.second >= a && p.second <= b)
            left.insert(p);
        else
            right.insert(p);
    }
    for (auto &p : need) {
        if (p == make_pair(a, b) || p == make_pair(b, a))
            continue;
        if (p.first >= a && p.first <= b && p.second >= a && p.second <= b)
            leftNeed.insert(p);
        else
            rightNeed.insert(p);
    }
    for (auto &x : values) {
        if (x >= a && x <= b)
            vLeft.push_back(x);
        else
            vRight.push_back(x);
        if (x == a || x == b)
            vRight.push_back(x);
    }
    solve(left, leftNeed, vLeft);
    solve(right, rightNeed, vRight);
}

int main() {
    int N; cin >> N;

    vector< pair<int, int> > V(N - 3), V2(N - 3);
    for (int i = 0; i < N - 3; ++i) {
        cin >> V[i].first >> V[i].second;
    }

    for (int i = 0; i < N - 3; ++i)
        cin >> V2[i].first >> V2[i].second;
    vector<int> values(N);
    for (int i = 1; i <= N; ++i)
        values[i - 1] = i;
    solve(set<pair<int, int> >(V.begin(), V.end()), set<pair<int, int>>(V2.begin(), V2.end()), values);
    cout << answer.size() << "\n";

    for (auto &p : answer) {
        int x, y, a, b;
        tie(x, y, a, b) = p;
        cout << x << " " << y << "\n";
    }
}