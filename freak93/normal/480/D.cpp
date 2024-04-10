#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Parcel {
    int in, out;
    int weight, strength;
    int value;

    bool fits_in(const Parcel& other) const {
        return in >= other.in && out <= other.out;
    }
};

istream& operator>>(istream& stream, Parcel &parcel) {
    return stream >> parcel.in >> parcel.out >> parcel.weight >> parcel.strength >> parcel.value;
}

void dfs(int node, const vector< vector<int> > &arcs, vector<bool> &used, vector<int> &order) {
    if (used[node])
        return;
    used[node] = true;
    for (auto &x : arcs[node])
        dfs(x, arcs, used, order);
    order.push_back(node);
}

int main() {
    ios::sync_with_stdio(false);
    int N, S; cin >> N >> S;

    vector<Parcel> parcels(N);
    for (int i = 0; i < N; ++i)
        cin >> parcels[i];

    parcels.emplace_back(Parcel{0, 2 * N, 0, S, 0});
    ++N;
    vector< vector<int > > inside(N);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (i != j && parcels[i].fits_in(parcels[j]))
                inside[j].emplace_back(i);

    for (int i = 0; i < N; ++i)
        sort(inside[i].begin(), inside[i].end(), [&](int x, int y) {
            return parcels[x].out < parcels[y].out;
        });

    vector<int> order;
    vector<bool> used(N, false);
    for (int i = 0; i < N; ++i)
        dfs(i, inside, used, order);

    vector< vector<int> > dp(N, vector<int>(S + 1, 0));
    vector<int> inner(2 * N);
    for (auto &box : order) {
        for (int i = 0; i <= S; ++i) {
            fill(inner.begin(), inner.end(), 0);
            int k = 0;
            for (auto &son: inside[box]) {
                while (k < parcels[son].out) {
                    inner[k + 1] = max(inner[k + 1], inner[k]);
                    ++k;
                }
                if (parcels[son].weight > i)
                    continue;
                inner[parcels[son].out] = 
                    max(
                        inner[parcels[son].out], 
                        inner[parcels[son].in] + dp[son][min(i - parcels[son].weight, parcels[son].strength)] + parcels[son].value
                    );
            }
            dp[box][i] = inner[k];
        }
    }

    cout << dp[N - 1][S] << "\n";
}