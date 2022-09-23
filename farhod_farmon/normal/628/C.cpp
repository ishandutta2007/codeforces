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
#include <iomanip>

#define lli long long int
#define sc scanf
#define pr printf
#define pb push_back
#define p_b pop_back
#define mp make_pair
#define fi first
#define se second
#define fin freopen( "input.txt", "r", stdin );
#define fout freopen( "output.txt", "w", stdout );

using namespace std;

lli i, cnt, j, x, k, n;
string s;

int main()
{
    cin >> n >> k;
    cin >> s;
    for( i = 0; i < s.size() && k; i++ ){
        if( abs('a' - s[i]) > abs('z' - s[i]) ){
            x = abs('a' - s[i]);
            k -= x;
            s[i] = 'a';
            while( k < 0 ){
                k++;
                s[i]++;
            }
        }
        else{
            x = abs('z' - s[i]);
            k -= x;
            s[i] = 'z';
            while( k < 0 ){
                k++;
                s[i]--;
            }
        }
    }
    if( k > 0 ){
        cout << -1 << endl;
        return 0;
    }
    cout << s << endl;
}