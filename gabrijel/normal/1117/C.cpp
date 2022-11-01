#include <bits/stdc++.h>
using namespace std;

#define REP(i, a, b) for(int i = a; i < b; i++)

const int maxn = 100100;
const long long int inf = 1e9;

int n;
int px, py, kx, ky, trxk, tryk;

char a[maxn];

//pair <int, int> uk [maxn];
//pair <int, int> tr;

//int razx[maxn];
//int razy[maxn];

//long long int rjx = inf, rjy = inf;

int main()
{
    cin >> px >> py >> kx >> ky;
    cin >> n;
    REP(i, 0, n)
    {
        //scanf("%c", &a[i]);
        cin >> a[i];
    }
    /*int pocxraz = abs(kx - px);
    int pocyraz = abs(ky - py);
    int pomaky, pomakx;
    REP(i, 0, n)
    {
        pomakx = 0; pomaky = 0;
        if(a[i] == 'U' && ky - py > 0) {pomaky = -2; pomakx = -1;}
        else if(a[i] == 'U' && ky - py < 0) {pomaky = 0; pomakx = -1;}
        else if(a[i] == 'U') {pomaky = -1; pomakx = -1;}
        else if(a[i] == 'D' && ky - py < 0) {pomaky = -2; pomakx = -1;}
        else if(a[i] == 'D' && ky - py > 0) {pomaky = 0; pomakx = -1;}
        else if(a[i] == 'D') {pomaky = -1; pomakx = -1;}
        else if(a[i] == 'L' && kx - px > 0) {pomakx = 0; pomaky = -1;}
        else if(a[i] == 'L' && kx - px < 0) {pomakx = -2; pomaky = -1;}
        else if(a[i] == 'L') {pomakx = 0; pomaky = -1;}
        else if(a[i] == 'R' && kx - px < 0) {pomakx = 0; pomaky = -1;}
        else if(a[i] == 'R' && kx - px > 0) {pomakx = -2; pomaky = -1;}
        else if(a[i] == 'R') {pomakx = -1; pomaky = -1;}
        if(i == 0)
        {
            razx[i] = pomakx;
            razy[i] = pomaky;
        }
        else
        {
            razx[i] = razx[i - 1] + pomakx;
            razy[i] = razy[i - 1] + pomaky;
        }
        if(pocxraz - razx[i] <= 0) rjx = min(rjx, (long long) i + 1);
        if(pocyraz - razy[i] <= 0) rjy = min(rjy, (long long) i + 1);
    }
    int ukrazx = -razx[n - 1];
    int ukrazy = -razy[n - 1];
    cout << pocxraz << pocyraz << endl;
    cout << ukrazx << ukrazy << endl;
    int dodaj = max(pocxraz / ukrazx, pocyraz / ukrazy);
    cout << dodaj << endl;
    pocxraz -= dodaj * ukrazx;
    pocyraz -= dodaj * ukrazy;
    //cout << pocxraz << pocyraz << endl;
    REP(i, 0, n + 1)
    {
        if(pocxraz <= 0 && pocyraz <= 0)
        {
            cout << (long long) dodaj * n + i << endl;
            exit(0);
        }
        pocxraz += razx[i];
        pocyraz += razy[i];
    }*/
    int razx = 0, razy = 0;
    REP(i, 0, n)
    {
        if(a[i] == 'U') razy++;
        else if(a[i] == 'D') razy--;
        else if(a[i] == 'L') razx--;
        else razx++;
    }
    int cijeli;
    int lo = 0, hi = inf + 100, mid;
    while(lo < hi)
    {
        mid = (lo + hi) / 2;
        if((long long) abs((long long) px - kx + (long long) mid * razx) + abs(py - ky + (long long) mid * razy) <= (long long) mid * n) hi = mid;
        else lo = mid + 1;
    }
    if(lo > inf) {cout << -1 << endl; exit(0);}
    if(lo > 0) lo--;
    int trrazx = 0, trrazy = 0;
    int i = 0;
    while(1)
    {
        if((long long) abs((long long) px - kx + (long long) lo * razx + trrazx) + abs(py - ky + (long long) lo * razy + trrazy) <= (long long) lo * n + i)
        {
            cout << (long long) lo * n + i << endl;
            exit(0);
        }
        if(a[i] == 'U') trrazy++;
        else if(a[i] == 'D') trrazy--;
        else if(a[i] == 'L') trrazx--;
        else trrazx++;
        i++;
    }
    return 0;
}