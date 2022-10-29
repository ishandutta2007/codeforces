#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
int n, m;
long long t;
vector<pair<int, int> >q;
vector<pair<int, int> > p;
vector<int> work(const vector<pair<int, int> > &P, int m, long long t) {//nmlong long
    vector<int> q;
    p = P;
    int n = p.size();
    const long long nm = 1ll * n * m;
    long long O = 0, S = 0;
    for (auto u:p) {
        q.push_back(((t * u.second + u.first) % m + m) % m);
        O = (O + q[q.size() - 1] - u.first) % nm;
        S += u.second;
    }
    long long ST = 0;
    while (t) {
        if (t & 1)
            (ST += S) %= nm;
        (S += S) %= nm, t >>= 1;
    }
    sort(q.begin(), q.end());
    int offset = (ST - O + nm) % nm / m;
    vector<int>id(n);
    for (int i = 0; i < n; i ++)
        id[i] = i;
    sort(id.begin(), id.end(),[](int x, int y){return p[x].first < p[y].first;});
    vector<int> output(n);
    for (int i = 0; i < n; i ++)
        output[id[i]] = q[(i + offset) %n];
    return output;
}
int main() {
    scanf("%d %d %lld", &n, &m, &t);
    for (int i = 1; i <= n; i ++) {
        int x;
        char c;
        scanf("%d %c", &x, &c);
        x --;
        q.push_back(make_pair(x, (c == 'R') * 2 - 1));
    }
    vector<int> a = work(q, m, t);
    for (auto u:a)
        printf("%d ", u + 1);
    return 0;
}