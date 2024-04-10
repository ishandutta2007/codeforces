#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

int n, a;
pair<ll, ll> v[111111], vv[111111];
ll mind=1e12;
template<class T> T sqr(T a) { return a*a; }
inline bool compare(pair<ll, ll> a, pair<ll, ll> b) {
    return (a.second==b.second) ? (a.first<b.first) : (a.second<b.second);
}
inline void check(pair<ll, ll> a, pair<ll, ll> b) {
    mind=min(mind, sqr(a.first-b.first)+sqr(a.second-b.second));
}

void calc(int vl, int vr) {
    if (vr==vl) return;
    int mid=(vl+vr)/2;
    ll minx=v[mid].first;
    calc(vl, mid);
    calc(mid+1, vr);
    merge(v+vl, v+mid+1, v+mid+1, v+vr+1, vv, compare);
    copy(vv, vv+vr-vl+1, v+vl);
    int sz=0;
    for (int i=vl; i<=vr; i++) if (sqr(v[i].first-minx)<mind) {
        for (int j=sz-1; j>=0&&sqr(vv[j].second-v[i].second)<mind; j--) check(vv[j], v[i]);
        vv[sz++]=v[i];
    }
}

int main() {
    scanf("%d", &n);
    for (long long i=0, sum=0; i<n; i++) {
        scanf("%d", &a);
        sum+=a;
        v[i]=make_pair((double)i, (double)sum);
    }
    sort(v, v+n);
    calc(0, n-1);
    cout << mind;
    return 0;
}