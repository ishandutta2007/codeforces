#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#include <deque>
using namespace std;

int a[9],b[9],cura,curb,nexta,nextb;

void res(string ans) {
    cout << ans;
    exit(0);
}

int check() {
    if (cura > nextb && curb > nexta) return 1;
    if (cura < nextb && curb < nexta) return 2;
    return 0;
}

int attempt() {
    nexta = a[2]; nextb = b[3];
    int a1 = check();
    nexta = a[3]; nextb = b[2];
    int a2 = check();
    if (a1 == 2 || a2 == 2) return 2;
    if (a1 == 0 || a2 == 0) return 0;
    return 1;
}

int main()
{
    for (int i = 0; i < 4; ++i)
        cin >> a[i] >> b[i];

    cura = a[0]; curb = b[1];
    int r1 = attempt();
    cura = a[1]; curb = b[0];
    int r2 = attempt();
    if (r1 == 1 || r2 == 1) res("Team 1");
    if (r1 == 0 || r2 == 0) res("Draw");
    res("Team 2");

    return 0;
}