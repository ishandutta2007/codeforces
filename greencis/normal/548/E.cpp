#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
typedef long long ll;

int n,q,x,a[200005],u[200005];
int lastdiv[500005];
int cnt[500005];
ll ans,cnt_activated;

vector<int> prime,v[200005];

int main()
{
    for (int i = 2; i <= 500000; ++i) {
        if (!lastdiv[i]) {
            lastdiv[i] = i;
            prime.push_back(i);
        }
        for (int j = 0; j < prime.size() && prime[j] <= lastdiv[i] && i * prime[j] <= 500000; ++j)
            lastdiv[i * prime[j]] = prime[j];
    }

    scanf("%d%d",&n,&q);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&x);
        a[i] = x;
        while (lastdiv[x]) {
            if (!v[i].size() || v[i].back() != lastdiv[x])
                v[i].push_back(lastdiv[x]);
            x /= lastdiv[x];
        }
        if (x != 1 && (!v[i].size() || v[i].back() != x)) v[i].push_back(x);
    }

    while (q--) {
        scanf("%d",&x); --x;
        if (u[x]) {
            --cnt_activated;
            for (int mask = (1 << v[x].size()) - 1; mask > 0; --mask) {
                int curnum = 1;
                int curcnt = 0;
                int qqq = mask;
                for (int i = 0; i < v[x].size(); ++i) {
                    if (qqq & 1) {
                        ++curcnt;
                        curnum *= v[x][i];
                    }
                    qqq >>= 1;
                }
                --cnt[curnum];
                if (curcnt & 1) ans -= (ll)cnt[curnum];
                else ans += (ll)cnt[curnum];
            }
        } else {
            ++cnt_activated;
            for (int mask = (1 << v[x].size()) - 1; mask > 0; --mask) {
                int curnum = 1;
                int curcnt = 0;
                int qqq = mask;
                for (int i = 0; i < v[x].size(); ++i) {
                    if (qqq & 1) {
                        ++curcnt;
                        curnum *= v[x][i];
                    }
                    qqq >>= 1;
                }
                //cerr << mask << " " << ans << " " << curcnt << " " << curnum << " " << cnt[curnum] << endl;
                if (curcnt & 1) ans += (ll)cnt[curnum];
                else ans -= (ll)cnt[curnum];
                ++cnt[curnum];
                //cerr << mask << " " << ans << " " << curcnt << " " << curnum << " " << cnt[curnum] << endl;
            }
        }
        //cerr << cnt_activated << " " << ans << endl;
        u[x] ^= 1;
        printf("%I64d\n", cnt_activated * (cnt_activated - 1ll) / 2ll - ans);
    }

    return 0;
}