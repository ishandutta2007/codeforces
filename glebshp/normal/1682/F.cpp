#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const long long mdl = 1000 * 1000 * 1000 + 7;
const int maxn = 200 * 1000 + 100;

struct TRSQ {
    int total;
    int shift;
    vector <long long> body;

    TRSQ(int n) {
        int k = 1;
        while (k < n) {
            k *= 2;        
        }
        total = 2 * k;
        shift = k;
        body.resize(total);
    }

    long long getsum(int i, int j) {
        return rss(1, 1, shift, i + 1, j + 1);
    }

    long long rss(int v, int lb, int rb, int i, int j) {
        if (lb > j || rb < i) {
            return 0;
        }
        if (lb >= i && rb <= j) {
            return body[v];
        }
        return (rss(v * 2, lb, (lb + rb) / 2, i, j) + rss(v * 2 + 1, (lb + rb) / 2 + 1, rb, i, j)) % mdl;
    }

    void change(int p, long long x) {
        p = p + shift;
        body[p] = x % mdl;
        while (p > 1) {
            p /= 2;
            body[p] = (body[p * 2] + body[p * 2 + 1]) % mdl;
        }
    }
};

int n, q;
int a[maxn];
int b[maxn];
int lb[maxn];
int rb[maxn];
long long d[maxn];
long long ans[maxn];
long long sum[maxn];

int main() {
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    scanf("%d%d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);    
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    for (int i = 0; i < q; i++) {
        scanf("%d%d", &lb[i], &rb[i]);
        lb[i]--, rb[i]--;
    }
    d[0] = 0;
    for (int i = 0; i < n; i++) {
        d[i + 1] = d[i] + b[i];
    }
    sum[0] = 0;
    for (int i = 0; i < n - 1; i++) {
        sum[i + 1] = (sum[i] + (d[i + 1] % mdl * (a[i + 1] - a[i])) % mdl) % mdl;
    }

    vector <pair <long long, int> > qs;
    for (int i = 0; i < q; i++) {
        qs.pb(mp(d[lb[i]], i));        
    }
    sort(qs.begin(), qs.end());

    vector <pair <long long, int> > postoturn;
    for (int i = 0; i < n - 1; i++) {
        postoturn.pb(mp(d[i + 1], i));
    }
    sort(postoturn.begin(), postoturn.end());

    TRSQ rsq(n - 1);
    TRSQ rsqa(n - 1);
    int p = 0;
    for (int i = 0; i < q; i++) {
        while (p < (int) postoturn.size() && postoturn[p].fs <= qs[i].fs) {
            int ps = postoturn[p].sc;
            long long val = ((d[ps + 1] % mdl + mdl) % mdl * (a[ps + 1] - a[ps])) % mdl;
//            cerr << "shift " << i << ' ' << p << ' ' << ps << ' ' << val << endl;
            rsq.change(ps, val);    
            rsqa.change(ps, a[ps + 1] - a[ps]);

            p++;
        }

        int qnum = qs[i].sc;

    //    cerr << qnum << ' ' << p << endl;

        long long totalsum = (sum[rb[qnum]] - sum[lb[qnum]] + mdl) % mdl;
        long long sumbelow = rsq.getsum(lb[qnum], rb[qnum] - 1);
        long long sumabove = (totalsum - sumbelow + mdl) % mdl;
        long long asumbelow = rsqa.getsum(lb[qnum], rb[qnum] - 1);
  //      cerr << totalsum << ' ' << sumbelow << ' ' << sumabove << ' ' << asumbelow << endl;
        long long corsumbelow = (((asumbelow * ((d[lb[qnum]] % mdl + mdl) % mdl)) % mdl) - sumbelow + mdl) % mdl;
        long long asumabove = a[rb[qnum]] - a[lb[qnum]] - asumbelow;
        long long corsumabove = (sumabove - (asumabove * (d[lb[qnum]] % mdl)) % mdl + mdl) % mdl;
        ans[qnum] = (corsumbelow + corsumabove) % mdl;
    }

    for (int i = 0; i < q; i++) {
        if (ans[i] < 0) {
            ans[i] = (ans[i] % mdl + mdl) % mdl;
        }
        printf("%lld\n", ans[i]);
    }


    return 0;
}