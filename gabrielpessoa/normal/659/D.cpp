#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;
typedef pair<ll, int> lli;
typedef pair<int, ii> iii;
typedef pair<double, ii> dii;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<iii> viii;

const int SIZE = 1005;
const int INF = 0x3f3f3f3f;
const ll INFll = 0x3f3f3f3f3f3f3f3f;
const ll fat = 1E6;

map<vi, int> pop;

int main() {
    int n;
    cin >> n;
    int x, y, dir = 0, total = 0;
    cin >> x >> y;
    cin >> x >> y;
    for(int i = 1; i < n; i++) {
        int dx, dy;
        cin >> dx >> dy;
        int newDir;
        if(dir == 0 || dir == 2) {
            if(dx > x) newDir = 1;
            else newDir = 3;
            if(newDir != dir + 1) total++;
        } else {
            if(dy > y) newDir = 0;
            else newDir = 2;
            if(newDir == dir - 1) total++;
        }
        dir = newDir;
    }
    printf("%d\n", total);
    return 0;
}