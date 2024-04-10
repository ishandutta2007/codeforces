#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 300300;

using namespace std;

int n;
int x;
int y;
int cnt;

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n;
    int lx = 0,
        ly = 0;
    for(int i = 1; i <= n; i++){
        char c;
        cin >> c;
        int nx = x,
            ny = y;
        if(c == 'R')
            ny++;
        if(c == 'L')
            ny--;
        if(c == 'U')
            nx--;
        if(c == 'D')
            nx++;
        if(abs(nx - lx) + abs(ny - ly) < abs(x - lx) + abs(y - ly)){
            cnt++;
            lx = x;
            ly = y;
        }
        x = nx;
        y = ny;
    }
    cout << cnt + 1 << endl;
}