#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

int n,a,b,c,d,curidx;
ll ans;
vector< pair< int, pii > > hor,ver;
set<int> s;
map<int,int> mp;

void reduce(vector< pair< int, pii > > &v) {
    vector< pair< int, pii > > nv;
    for (int i = 0; i < v.size(); ++i) {
        if (nv.size() && (nv.back().first == v[i].first &&
                          nv.back().second.second + 1 >= v[i].second.first)) {
             pair< int, pii > qqq = nv.back();
             nv.pop_back();
             nv.push_back(make_pair(qqq.first, make_pair(qqq.second.first,
                                                         max(qqq.second.second, v[i].second.second))));
        } else nv.push_back(v[i]);
    }
    v = nv;
}

struct entry {
    int type,x,ai,bi; /// 0 - open hor, 1 - vert, 2 - close hor
    bool operator<(const entry& rhs) const {
        return x == rhs.x ? type == rhs.type ? ai < rhs.ai : type < rhs.type : x < rhs.x;
    }
} e[500105];
int ei;

int t[500105];
int sum(int R) {
    int res = 0;
    for (; R >= 0; R = (R & (R + 1)) - 1)
        res += t[R];
    return res;
}
inline int sum(int L, int R) {
    return sum(R) - sum(L - 1);
}
void add(int idx, int val) {
    for (; idx < 500105; idx = (idx | (idx + 1)))
        t[idx] += val;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a >> b >> c >> d;
        if (a > c) swap(a, c);
        if (b > d) swap(b, d);
        if (a == c) {
            ver.push_back(make_pair(a, make_pair(b, d)));
        } else {
            hor.push_back(make_pair(b, make_pair(a, c)));
        }
    }
    sort(hor.begin(), hor.end());
    sort(ver.begin(), ver.end());
    reduce(hor);
    reduce(ver);
    for (int i = 0; i < hor.size(); ++i) {
        ans += ll(hor[i].second.second - hor[i].second.first + 1);
    }
    for (int i = 0; i < ver.size(); ++i)
        ans += ll(ver[i].second.second - ver[i].second.first + 1);

    /// compress horizontal
    s.clear();
    mp.clear();
    for (int i = 0; i < hor.size(); ++i) {
        s.insert(hor[i].second.first);
        s.insert(hor[i].second.second);
    }
    for (int i = 0; i < ver.size(); ++i)
        s.insert(ver[i].first);
    curidx = 0;
    for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
        mp[*it] = curidx++;

    for (int i = 0; i < hor.size(); ++i) {
        hor[i].second.first = mp[hor[i].second.first];
        hor[i].second.second = mp[hor[i].second.second];
    }
    for (int i = 0; i < ver.size(); ++i)
        ver[i].first = mp[ver[i].first];

    /// compress vertical
    s.clear();
    mp.clear();
    for (int i = 0; i < ver.size(); ++i) {
        s.insert(ver[i].second.first);
        s.insert(ver[i].second.second);
    }
    for (int i = 0; i < hor.size(); ++i)
        s.insert(hor[i].first);
    curidx = 0;
    for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
        mp[*it] = curidx++;

    for (int i = 0; i < ver.size(); ++i) {
        ver[i].second.first = mp[ver[i].second.first];
        ver[i].second.second = mp[ver[i].second.second];
    }
    for (int i = 0; i < hor.size(); ++i)
        hor[i].first = mp[hor[i].first];

    for (int i = 0; i < hor.size(); ++i) {
        e[ei].type = 0;
        e[ei].x = hor[i].second.first;
        e[ei].ai = hor[i].first;
        ++ei;

        e[ei].type = 2;
        e[ei].x = hor[i].second.second;
        e[ei].ai = hor[i].first;
        ++ei;
    }

    for (int i = 0; i < ver.size(); ++i) {
        e[ei].type = 1;
        e[ei].x = ver[i].first;
        e[ei].ai = ver[i].second.first;
        e[ei].bi = ver[i].second.second;
        ++ei;
    }

    sort(e, e + ei);
    for (int i = 0; i < ei; ++i) {
        if (e[i].type == 0)
            add(e[i].ai, 1);
        else if (e[i].type == 2)
            add(e[i].ai, -1);
        else
            ans -= sum(e[i].ai, e[i].bi);
    }
    cout << ans;

    return 0;
}