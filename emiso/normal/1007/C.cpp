#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, LBX = 1, qs, RBX, LBY = 1, RBY, last, i, magic = 200;

ll query(ll x, ll y) {
    printf("%lld %lld\n", x, y);
    fflush(stdout);

    assert(++qs <= 600);

    ll ret;
    scanf("%lld", &ret);

    if(ret == 0) exit(0);
    return ret;
}

int main() {
    scanf("%lld", &n);
    RBX = RBY = n;

    while(++i) {
        last = n+1;
        if(i % 2) {
            ll my = LBY + (RBY - LBY) / magic;
            int flag = 0;

            ll lx = LBX, rx = RBX;
            while(lx <= rx) {
                ll mx = lx + (rx - lx) / 2;

                ll q = query(mx, my);

                if(q == 1) {
                    LBX = lx = mx + 1;
                } else if(q == 3) {
                    rx = mx - 1;
                    last = mx;
                } else if(q == 2) {
                    flag = 1;
                    break;
                }
            }

            if(flag) {
                LBY = my + 1;
                RBX = min(RBX, last - 1);
            }
            else RBY = my - 1;

        } else {
            ll mx = LBX + (RBX - LBX) / magic;
            int flag = 0;

            ll ly = LBY, ry = RBY;
            while(ly <= ry) {
                ll my = ly + (ry - ly) / 2;

                ll q = query(mx, my);

                if(q == 2) {
                    LBY = ly = my + 1;
                } else if(q == 3) {
                    ry = my - 1;
                    last = my;
                } else if(q == 1) {
                    flag = 1;
                    break;
                }
            }

            if(flag) {
                LBX = mx + 1;
                RBY = min(RBY, last - 1);
            }
            else RBX = mx - 1;
        }
    }

    return 0;
}