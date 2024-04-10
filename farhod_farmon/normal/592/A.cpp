#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <deque>
#include <queue>
#include <stack>

#define lli long long int
#define sc scanf
#define pr printf
#define pb push_back
#define p_b pop_back
#define mp make_pair
#define fi first
#define se second
#define fin freopen( "birthday.in", "r", stdin );
#define fout freopen( "birthday.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int cnt1, cnt2, i, j, h, x, y, ans1, ans2;
char c[10][10];

int main()
{
    ans1 = ans2 = 10;
    for( i = 1; i <= 8; i++ ){
        for( j = 1; j <= 8; j++ ){
            cin >> c[i][j];
        }
    }
    for( i = 1; i <= 8; i++ ){
        for( j = 1; j <= 8; j++ ){
            if( c[i][j] == 'B' ){
                h = i + 1;
                cnt1 = 0;
                while( h <= 8 ){
                    if( c[h][j] != '.' ){
                        cnt1 = 10;
                        break;
                    }
                    cnt1++;
                    h++;
                }
                ans1 = min(ans1, cnt1);
            }
            if( c[i][j] == 'W' ){
                h = i - 1;
                cnt1 = 0;
                while( h >= 1 ){
                    if( c[h][j] != '.' ){
                        cnt1 = 10;
                        break;
                    }
                    cnt1++;
                    h--;
                }
                ans2 = min(ans2, cnt1);
            }
        }
    }
    if( ans1 >= ans2 )cout << "A";
    else cout << "B";
}