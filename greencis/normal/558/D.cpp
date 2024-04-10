#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long double ld;
typedef long long ll;

int n,lvl,ans;
ll h,L,R;
map<ll,int> mp;

struct entry {
    ll x;
    bool start,yes;
} e[200005];

int comp(entry a, entry b) {
    return a.x == b.x ? a.start > b.start : a.x < b.x;
}

vector< pair<ll,ll> > yesv, nov;

void cheat() {
    puts("Game cheated!");
    exit(0);
}

void suff() {
    puts("Data not sufficient!");
    exit(0);
}

int main()
{
    scanf("%I64d%d",&h,&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%I64d%I64d%d",&lvl,&L,&R,&ans);
        while ((ll)lvl < h) {
            ++lvl;
            L <<= 1ll;
            R <<= 1ll;
            R ^= 1ll;
        }
        e[i+i].x = L;
        e[i+i].start = true;
        e[i+i].yes = ans;

        e[i+i+1].x = R;
        e[i+i+1].start = false;
        e[i+i+1].yes = ans;

        if (ans) yesv.push_back(make_pair(L, R));
    }
    sort(e,e+n+n,comp);
    ll final_L = 1ll << (h - 1ll), final_R = (1ll << h) - 1ll;
    for (int i = 0; i < yesv.size(); ++i) {
        ll curl = yesv[i].first;
        ll curr = yesv[i].second;
        if (curr < final_L || curl > final_R) cheat();
        if (curr < final_R) final_R = curr;
        if (curl > final_L) final_L = curl;
    }

    int balance = 0;
    ll st = -1, fi = -1, len = 0;
    for (int i = 0; i < n + n; ++i) {
        if (!e[i].yes) {
            if (e[i].start) {
                if (balance == 0) st = e[i].x;
                ++balance;
            } else {
                if (balance == 1) {
                    fi = e[i].x;
                    if (st < final_L) st = final_L;
                    if (fi > final_R) fi = final_R;
                    if (st <= fi) nov.push_back(make_pair(st, fi)), len += fi - st + 1ll;
                }
                --balance;
            }
        }
    }

    if ((final_R - final_L + 1ll) - len <= 0ll) cheat();
    if (len + 1ll != final_R - final_L + 1ll) suff();
    ll myans = final_R;
    if (nov.size() && nov.back().second == final_R) myans = final_L;
    for (int i = 0; i + 1 < nov.size(); ++i) {
        if (nov[i].second + 1ll < nov[i+1].first) myans = nov[i].second + 1ll;
    }
    cout << myans;

    return 0;
}