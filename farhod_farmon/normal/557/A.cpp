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
#define fin freopen( "typo.in", "r", stdin );
#define fout freopen( "typo.out", "w", stdout );
#define dist( x, xx, y, yy ) sqrt( (x - y) * (x - y) + (xx - yy) * (xx - yy) )
using namespace std;
int a, max1, max2, max3, d[4], i;

int main()
{
    cin >> a;
    cin >> d[1] >> max1;
    cin >> d[2] >> max2;
    cin >> d[3] >> max3;
    a = a - (d[1] + d[2] + d[3]);
    max1 -= d[1];
    max2 -= d[2];
    max3 -= d[3];
    while(a){
        if( max1 ){
            max1--;
            d[1]++;
        }
        else if( max2 ){
            max2--;
            d[2]++;
        }
        else if( max3 ){
            max3--;
            d[3]++;
        }
        else break;
        a--;
    }
    cout << d[1] << " " << d[2] << " " << d[3];
}