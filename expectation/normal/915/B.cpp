#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define SZ(a) a.size()
#define LL long long

int n,pos,l,r;
int tmp, ans;

void gol()
{
    if (l == 1) return;
    tmp += abs(l-pos)+1;
    pos = l;
}

void gor()
{
    if (r == n) return;
    tmp += abs(r-pos)+1;
    pos = r;
}

int main()
{
    cin >> n >> pos >> l >> r;
    int cp = pos;
    gol(); gor();
    ans = tmp; pos = cp;
    tmp = 0;
    gor(); gol();
    cout << min(ans,tmp);
}