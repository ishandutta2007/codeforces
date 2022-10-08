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

const int maxn = 10 * 1000 * 1000 + 100;

int n;
int a[maxn];
int maxa;
bool used[maxn];
int nxt[maxn];
int prv[maxn];

pair <long long, long long> go(int cur) {
    int stp = nxt[0];
    int seglen = cur + 1;
    long long shift = cur * 1ll * cur - stp;
//    cerr << shift << endl;
    long long minadd = cur * 1ll * cur - stp;
    long long maxadd = cur * 1ll * cur - stp + seglen - 1;
    
    long long i = cur;
    while (minadd <= maxadd) {
        long long lb = (i * i + (i - 1) * (i - 1) + 1) / 2;
        long long rb = (i * i + (i + 1) * (i + 1)) / 2;

  //      cerr << i << ' ' << lb << ' ' << rb << ' ' << minadd << ' ' << maxadd << endl;

        lb -= shift;
        rb -= shift;

        if (lb > maxa) {
            break;
        }
        //    cerr << lb << ' ' << rb << endl;
      //  cerr << "stp " << stp << ' ' << nxt[lb] << endl;
        if (lb < stp) {
            lb = stp;
        } else {
            lb = nxt[lb];
        }
        if (rb < stp) {
            rb = stp;
        } else {
            rb = prv[rb];
        }
        //cerr << lb << ' ' << rb << endl;
        if (lb <= rb) {
            minadd = max(minadd, i * i - lb);
            maxadd = min(maxadd, i * i + i - rb);
        }
        //cerr << minadd << ' ' << maxadd << endl;

        i++;
    }    

    return mp(minadd, maxadd);
}

int main() {
    /*
    freopen("input.txt", "w", stdout);
    cout << 1000 * 1000 << endl;
    for (int i = 0; i < 1000 * 1000; i++) {
        cout << i + 1 << ' ';
    }
    cout << endl;
    return 0;
    */
    
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        maxa = max(maxa, a[i]);
        used[a[i]] = true;
    }

    nxt[maxn - 1] = maxn - 1;
    for (int i = maxn - 2; i >= 0; i--) {
        if (used[i]) {
            nxt[i] = i;
        } else {
            nxt[i] = nxt[i + 1];
        }
    }
    for (int i = 1; i < maxn; i++) {
        if (used[i]) {
            prv[i] = i;
        } else {
            prv[i] = prv[i - 1];
        }
    }

    int cur = 1;
    while (true) {
        pair <long long, long long> ans = go(cur);
        if (ans.fs <= ans.sc && ans.sc >= 0) {
            printf("%lld\n", max(ans.fs, 0ll));

            break;
        }

        cur++;
    }

    return 0;
}