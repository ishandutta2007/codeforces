#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <ctime>
#include <cstring>
#include <cassert>
#include <complex>

#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define FORN(i, k, n) for(int i = (int)(k); i <= (int)(n); i++)
#define FORD(i, n, k) for(int i = (int)(n); i >= (int)(k); i--)

#define fi first
#define se second
#define sqr(x) ((x)*(x))
#define odd(x) ((x) % 2 == 1)
#define next(i,n) ((i == n) ? 1 : i + 1)   //1..n
#define prev(i,n) ((i == 1) ? n : i - 1)   //1..n

typedef long long int64;

const int MAXN = (int)1E3+100;
const int INF = (int)1E9;
const long double eps = 1e-9;
const long double pi = 3.1415926535897932384626433832795;

using namespace std;

char c1[2], c2[2];
const int dx[]= {-1,1,0,0,-1,-1,1,1};
const int dy[]= {0,0,-1,1,-1,1,-1,1};
const string ds[]= {"U", "D", "L", "R", "LU", "RU", "LD", "RD"};

bool correct(int a)
{
    return((0 <= a) && (a <= 7) ? 1 : 0);
}

string s[8][8];
int v[8][8], x[8][8], y[8][8];

void way(int n, int cx, int cy)
{
    if (n != 0) {
        way(n-1, x[cx][cy], y[cx][cy]);
        printf("%s\n", s[cx][cy].c_str());
    }
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    scanf("%c%c\n", &c1[0], &c2[0]);
    scanf("%c%c\n", &c1[1], &c2[1]);
    pair<int, int> p1 = make_pair('8' - c2[0], c1[0] - 'a');
    pair<int, int> p2 = make_pair('8' - c2[1], c1[1] - 'a');

    forn(i, 8)
        forn(j, 8)
            v[i][j] = 1000;
    v[p1.fi][p1.se] = 0;

    queue< pair<int, int> > q;
    queue<int> w;
    q.push(make_pair(p1.fi, p1.se));
    w.push(0);

        while (!q.empty()) {
            pair<int, int> cur = q.front();
            int cw = w.front();
            q.pop();
            w.pop();
            forn(i, 8) {
                int cx = cur.fi + dx[i];
                int cy = cur.se + dy[i];
                if (correct(cx) && correct(cy) && (v[cx][cy] > cw + 1)) {
                    v[cx][cy] = cw + 1;
                    q.push(make_pair(cx, cy));
                    w.push(cw + 1);
                    x[cx][cy] = cur.fi;
                    y[cx][cy] = cur.se;
                    s[cx][cy] = ds[i];
                }
            }
        }

    printf("%d\n", v[p2.fi][p2.se]);
    way(v[p2.fi][p2.se], p2.fi, p2.se);

    return 0;
}