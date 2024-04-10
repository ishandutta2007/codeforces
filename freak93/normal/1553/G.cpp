#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class DisjointSet {
  public:
    DisjointSet(int size): m_anc(size) {
        for (int i = 0; i < size; ++i)
            m_anc[i] = i;
    }

    int anc(int x) {
        if (m_anc[x] == x)
            return x;
        return (m_anc[x] = anc(m_anc[x]));
    }

    void merge(int x, int y) {
        x = anc(x);
        y = anc(y);
        m_anc[y] = x;
    }

  private:
    vector<int> m_anc;
};

int main() {
    ios::sync_with_stdio(false);

    int N, Q; cin >> N >> Q;

    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    vector<int> prime(*max_element(A.begin(), A.end()) + 2, 0);
    for (int i = 2; i < int(prime.size()); ++i)
        if (prime[i] == 0) {
            for (int j = i; j < int(prime.size()); j += i)
                prime[j] = i;
        }

    DisjointSet D(prime.size());
    set< pair<int, int> > S;
    for (auto x : A) {
        int group = prime[x];
        while (x > 1) {
            D.merge(group, prime[x]);
            x /= prime[x];
        }
    }

    vector<int> aux;
    for (auto x : A) {
        int group = D.anc(prime[x]);
        int y = x + 1;
        while (y > 1) {
            int group2 = D.anc(prime[y]);
            S.emplace(group, group2);
            S.emplace(group2, group);
            y /= prime[y];
            aux.push_back(group2);
        }
        for (auto u : aux)
            for (auto v : aux)
                S.emplace(u, v);
        aux.clear();
    }

    while (Q--) {
        int s, t; cin >> s >> t;
        --s; --t;
        int group1 = D.anc(prime[A[s]]);
        int group2 = D.anc(prime[A[t]]);

        if (group1 == group2)
            cout << "0\n";
        else if (S.count(make_pair(group1, group2)))
            cout << "1\n";
        else
            cout << "2\n";
    }
}