#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int MX = int(1e8);
const int CNT = 2 * MX + 1;

mt19937 mt(time(0));

int query(int x, int y) {
    cout << 0 << ' ' << x << ' ' << y << endl;
    int ans;
    cin >> ans;
    return ans;
}

vector<int> xans, yans;

int main() {
    ios_base::sync_with_stdio(false);
    int xx = 0, yy = 0;
    int dist = 0;
    do {
        xx = int(mt() % CNT) - MX;
        yy = int(mt() % CNT) - MX;
        dist = query(xx, yy);
    } while (dist < 9000);
    int dd = dist;

//    cerr << xx << ' ' << yy << ' ' << dist << endl;
//    cerr << qcnt << endl;

    int x = xx, y = yy;
    while (x + max(1, dist) <= MX) {
        if (dist == 0 && x + 5 <= MX) {
            x += 5;
            int ndist = query(x, y);
            if (ndist == 5) {
                dist = 5;
            } else {
                int tmp = x + 123;
                for (int i = ndist; i < 5; ++i) {
                    if (query(x - i, y) == 0) {
                        xans.pb(x - i);
                        if (tmp == x + 123) {
                            tmp = x - i;
                        }
                    }
                }
                if (tmp == x + 123) {
                    x += ndist;
                    xans.pb(x);
                } else {
                    x = tmp;
                }
                dist = 0;
            }
            continue;
        }
        x += max(1, dist);
        int ndist = query(x, y);
        if (ndist < max(1, dist)) {
            xans.pb(x + ndist);
            x += ndist;
            dist = 0;
        } else {
            dist = ndist;
        }
    }

    dist = dd;
    x = xx, y = yy;
    while (x - max(1, dist) >= -MX) {
        if (dist == 0 && x - 5 >= -MX) {
            x -= 5;
            int ndist = query(x, y);

            if (ndist == 5) {
                dist = 5;
            } else {
                int tmp = x + 123;
                for (int i = ndist; i < 5; ++i) {
                    if (query(x + i, y) == 0) {
                        xans.pb(x + i);
                        if (tmp == x + 123) {
                            tmp = x + i;
                        }
                    }
                }
                if (tmp == x + 123) {
                    x -= ndist;
                    xans.pb(x);
                } else {
                    x = tmp;
                }
                dist = 0;
            }
            continue;
        }
        x -= max(1, dist);
        int ndist = query(x, y);
        if (ndist < max(1, dist)) {
            xans.pb(x - ndist);
            x -= ndist;
            dist = 0;
        } else {
            dist = ndist;
        }
    }

    dist = dd;
    x = xx, y = yy;
    while (y + max(1, dist) <= MX) {
        if (dist == 0 && y + 5 <= MX) {
            y += 5;
            int ndist = query(x, y);
            if (ndist == 5) {
                dist = 5;
            } else {
                int tmp = y + 123;
                for (int i = ndist; i < 5; ++i) {
                    if (query(x, y - i) == 0) {
                        yans.pb(y - i);
                        if (tmp == y + 123) {
                            tmp = y - i;
                        }
                    }
                }
                if (tmp == y + 123) {
                    y += ndist;
                    yans.pb(y);
                } else {
                    y = tmp;
                }
                dist = 0;
            }
            continue;
        }
        y += max(1, dist);
        int ndist = query(x, y);
        if (ndist < max(1, dist)) {
            yans.pb(y + ndist);
            y += ndist;
            dist = 0;
        } else {
            dist = ndist;
        }
    }

    dist = dd;
    x = xx, y = yy;
    while (y - max(1, dist) >= -MX) {
        if (dist == 0 && y - 5 >= -MX) {
            y -= 5;
            int ndist = query(x, y);
            if (ndist == 5) {
                dist = 5;
            } else {
                int tmp = y + 123;
                for (int i = ndist; i < 5; ++i) {
                    if (query(x, y + i) == 0) {
                        yans.pb(y + i);
                        if (tmp == y + 123) {
                            tmp = y + i;
                        }
                    }
                }
                if (tmp == y + 123) {
                    y -= ndist;
                    yans.pb(y);
                } else {
                    y = tmp;
                }
                dist = 0;
            }
            continue;
        }
        y -= max(1, dist);
        int ndist = query(x, y);
        if (ndist < max(1, dist)) {
            yans.pb(y - ndist);
            y -= ndist;
            dist = 0;
        } else {
            dist = ndist;
        }
    }

    cout << 1 << ' ' << (int)xans.size() << ' ' << (int)yans.size() << endl;
    for (int x : xans) {
        cout << x << ' ';
    }
    cout << endl;
    for (int y : yans) {
        cout << y << ' ';
    }
    cout << endl;
    return 0;
}