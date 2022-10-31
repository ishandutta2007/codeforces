#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <string>
#include <deque>

using namespace std;

#define INF 10000000000LL
long long n, x[1111], x1 = INF/2, y1 = INF/2, ans = 0;
char d[1111];
vector<long long> x2, y2;
int a[3333][3333];

void mark(int xx, int yy, int xxx, int yyy) {
    if (xx > xxx) swap(xx, xxx);
    if (yy > yyy) swap(yy, yyy);
    for (int i=xx; i<=xxx; i++)
        for (int j=yy; j<=yyy; j++) a[i][j] = 1;
}

void dfs(int xx, int yy) {
    if (xx<0||xx>=x2.size()||yy<0||yy>=y2.size()||a[xx][yy]) return;
    else a[xx][yy] = 2;
    dfs(xx-1, yy);
    dfs(xx, yy-1);
    dfs(xx+1, yy);
    dfs(xx, yy+1);
}

int main()
{
    cin >> n;
    x2.push_back(0);
    x2.push_back(INF);
    y2.push_back(0);
    y2.push_back(INF);
    for (int i=0; i<=n; i++) {
        x2.push_back(x1);
        x2.push_back(x1+1);
        y2.push_back(y1);
        y2.push_back(y1+1);
        if (i==n) break;
        cin >> d[i] >> x[i];
        switch (d[i]) {
            case 'R': {x1+=x[i]; break;}
            case 'L': {x1-=x[i]; break;}
            case 'U': {y1+=x[i]; break;}
            case 'D': y1-=x[i];
        }
    }
    sort(x2.begin(), x2.end());
    sort(y2.begin(), y2.end());
    x2.erase(unique(x2.begin(), x2.end()), x2.end());
    y2.erase(unique(y2.begin(), y2.end()), y2.end());
    int xnow = lower_bound(x2.begin(), x2.end(), INF/2) - x2.begin(),
        ynow = lower_bound(y2.begin(), y2.end(), INF/2) - y2.begin();
    long long xx=INF/2, yy=INF/2;
    for (int i=0; i<n; i++) {
        int x4 = xnow, y4 = ynow;
        switch (d[i]) {
            case 'R': {xx+=x[i]; break;}
            case 'L': {xx-=x[i]; break;}
            case 'U': {yy+=x[i]; break;}
            case 'D': yy-=x[i];
        }
        xnow = lower_bound(x2.begin(), x2.end(), xx) - x2.begin();
        ynow = lower_bound(y2.begin(), y2.end(), yy) - y2.begin();
        mark(xnow, ynow, x4, y4);
    }
    dfs(0, 0);
    for (int i=0; i+1<x2.size(); i++) for (int j=0; j+1<y2.size(); j++) if (a[i][j]!=2){
        ans+=(x2[i+1]-x2[i])*(y2[j+1]-y2[j]);
    }
    cout << ans;
    return 0;
}