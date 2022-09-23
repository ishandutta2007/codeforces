#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

using namespace std;

int n, kol, z;
int x[3][3], y[3][3];

int ch(int x1, int y1, int x2, int y2)
{
    int cnt = 0;
    if(2 >= x1 && 2 <= x2 && 2 >= y1 && 2 <= y2)
        cnt++;
    if(3 >= x1 && 3 <= x2 && 4 >= y1 && 5 <= y2)
        cnt++;
    return cnt;
}

int can(int x1, int y1, int x2, int y2)
{
    int cnt;
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    cout.flush();
    //fflush(stdout);
    cin >> cnt;
    if(!kol)
        return cnt;
    if(x[1][1] >= x1 && x[1][2] <= x2 && y[1][1] >= y1 && y[1][2] <= y2)
        cnt--;
    return cnt;
}

void fnd(int g)
{
    int l, r;
    l = 1;
    r = n;
    while(l < r){
        int m = (l + r) / 2;
        if(can(m + 1, y[g][1], x[g][2], y[g][2]) > 0)
            l = m + 1;
        else
            r = m;
    }
    x[g][1] = l;
    l = 1;
    r = n;
    while(l < r){
        int m = (l + r) / 2;
        if(can(x[g][1], m + 1, x[g][2], y[g][2]) > 0)
            l = m + 1;
        else
            r = m;
    }
    y[g][1] = l;
    l = x[g][1];
    r = n;
    while(l < r){
        int m = (l + r) / 2;
        if(can(x[g][1], y[g][1], m, y[g][2]) > 0)
            r = m;
        else
            l = m + 1;
    }
    x[g][2] = l;
    l = y[g][1];
    r = n;
    while(l < r){
        int m = (l + r) / 2;
        if(can(x[g][1], y[g][1], x[g][2], m) > 0)
            r = m;
        else
            l = m + 1;
    }
    y[g][2] = l;
    kol++;
    return;
}

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    //ios_base::sync_with_stdio(0);
    cin >> n;
    x[1][1] = x[2][1] = 1;
    x[1][2] = x[2][2] = n;
    y[1][1] = y[2][1] = 1;
    y[1][2] = y[2][2] = n;
    fnd(1);
    fnd(2);
    cout << "! " << x[1][1] << " " << y[1][1] << " " << x[1][2] << " " << y[1][2] << " " << x[2][1] << " " << y[2][1] << " " << x[2][2] << " " << y[2][2] << endl;
    //cout << "! 2 2 2 2 3 4 3 5" << endl;
    cout.flush();
    return 0;
}