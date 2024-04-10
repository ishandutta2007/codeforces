#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl

using namespace std;
typedef long long ll;

set<pair<int,int> > p;

int main() {
    int x[3], y[3], ans=0, rx[3], ry[3];

    scanf("%d %d",&x[0], &y[0]);
    scanf("%d %d",&x[1], &y[1]);
    scanf("%d %d",&x[2], &y[2]);

    int ratiox, ratioy;
    ratiox = x[0] - x[1];
    ratioy = y[0] - y[1];

    p.insert(make_pair(x[2] + ratiox, y[2] + ratioy));
    p.insert(make_pair(x[2] - ratiox, y[2] - ratioy));

    ratiox = x[0] - x[2];
    ratioy = y[0] - y[2];

    p.insert(make_pair(x[1] + ratiox, y[1] + ratioy));
    p.insert(make_pair(x[1] - ratiox, y[1] - ratioy));

    printf("%d\n",p.size());
    while(!p.empty()) {
        printf("%d %d\n", (*p.begin()).first, (*p.begin()).second);
        p.erase(p.begin());
    }
    return 0;
}