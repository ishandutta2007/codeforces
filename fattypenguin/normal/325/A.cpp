#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <string>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

int x1[55], x2[55], y1[55], y2[55];
int n;

bool inside(int x, int y) {
    REP(i, n) {
        if (x >= x1[i] && x <= x2[i]) {
            if (y >= y1[i] && y <= y2[i]) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    cin >> n;

    VI dx, dy;

    REP(i, n) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        x1[i] *= 2;
        y1[i] *= 2;
        x2[i] *= 2;
        y2[i] *= 2;
        dx.PB(x1[i]);
        dx.PB(x2[i]);
        dy.PB(y1[i]);
        dy.PB(y2[i]);
    }

    int xMin = *min_element(x1, x1 + n);
    int xMax = *max_element(x2, x2 + n);
    int yMin = *min_element(y1, y1 + n);
    int yMax = *max_element(y2, y2 + n);

    bool flag = false;

    if (yMax - yMin == xMax - xMin) {

        flag = true;

        VI xx, yy;
        TR(it, dx) {
            if (*it != xMin) xx.PB(*it - 1);
            xx.PB(*it);
            if (*it != xMax) xx.PB(*it + 1);
        }

        TR(it, dy) {
            if (*it != yMin) yy.PB(*it - 1);
            yy.PB(*it);
            if (*it != yMax) yy.PB(*it + 1);
        }

        // cout << "HERE";

        TR(ix, xx) TR(iy, yy) {
            // cout << *ix << " " << *iy << endl;
            if (!inside(*ix, *iy)) {
                flag = false;
                break;
            }
        }
    }

    if (flag) {
        puts("YES");
    } else {
        puts("NO");
    }
    return 0;
}