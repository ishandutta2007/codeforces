//Written by fishy15 (Not my code!)
#include <cassert>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <array>
#include <algorithm>
#include <utility>
#include <map>
#include <queue>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstring>

#define ll long long
#define ld long double
#define eps 1e-8
#define MOD 1000000007

#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3f

// change if necessary
const int MAXN = 1e3+10;

using namespace std;

const int fdx[]={-1,1,-1,1}, fdy[]={-1,-1,1,1};
int x, y, q[4],fd=-1, a, b, c, ro, co;
bool rook[MAXN][MAXN];
array<int, 2> loc[MAXN];

int main() {
    cin >> x >> y;
    x--; y--;

    for (int i = 0; i < 666; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        rook[a][b] = true;
        loc[i] = {a, b};
    }

    while (x != 499 || y != 499) {
        int nx = x;
        int ny = y;
        if (x < 499) nx++;
        else if (x > 499) nx--;
        if (y < 499) ny++;
        else if (y > 499) ny--;

        if (rook[nx][ny]) {
            cout << nx + 1 << ' ' << y + 1 << '\n';
            cin >> a >> b >> c;
						assert(!~a&&!~b&&!~c);
            return 0;
        }
        
        cout << nx + 1 << ' ' << ny + 1 << endl;
        x = nx;
        y = ny;
        cin >> a >> b >> c;
        if (a <= 0) return 0;
        a--; b--; c--;
        ro=loc[a][0], co=loc[a][1];
        loc[a] = {b, c};
        rook[ro][co] = false;
        rook[b][c] = true;
    }


		for(int i=0;i<666;++i)
			++q[loc[i][0]>499|(loc[i][1]>499)<<1];
		for(int i=0;i<4;++i)
			if(666-q[i]>499)
				fd=3-i;
		assert(~fd);

    while (true) {
        int nx = x+fdx[fd];
        int ny = y+fdy[fd];

        if (rook[nx][ny]) {
            cout << nx + 1 << ' ' << y + 1 << '\n';
            cin >> a >> b >> c;
						assert(!~a&&!~b&&!~c);
            return 0;
        }

        cout << nx + 1 << ' ' << ny + 1 << endl;
        x = nx;
        y = ny;
        cin >> a >> b >> c;
        if (a <= 0) return 0;
        a--; b--; c--;
        ro=loc[a][0], co=loc[a][1];
        loc[a] = {b, c};
        rook[ro][co] = false;
        rook[b][c] = true;
    }

    return 0;
}