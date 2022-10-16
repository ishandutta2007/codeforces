//#include <fstream>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <queue>

using namespace std;

//ifstream cin("tema.in");
//ofstream cout("tema.out");

const int MAXVAL = 1024;

int seen[2][1 + MAXVAL];

int main() {
    int n, k, x, now = 1, before = 0;
    cin >> n >> k >> x;
    for (int i = 1; i <= n; i++) {
        int y;
        cin >> y;
        seen[now][y]++;
    }
    for (int i = 1; i <= k; i++) {
        swap(now, before);
        memset(seen[now], 0, sizeof(seen[now]));
        int type = 1;
        for (int i = 0; i <= MAXVAL; i++)
            if (seen[before][i]) {
                if (type == 1) {
                    seen[before][i]--;
                    seen[now][i ^ x]++;
                    type = 0;
                }
                int change = seen[before][i] / 2;
                seen[now][i ^ x] += change;
                seen[now][i] += (seen[before][i] - change);
                if (seen[before][i] % 2)
                    type = 1;
            }
    }
    for (int i = MAXVAL; i >= 0; i--)
        if (seen[now][i]) {
            cout << i << " ";
            break;
        }
    for (int i = 0; i <= MAXVAL; i++)
        if (seen[now][i]) {
            cout << i << " ";
            break;
        }
    return 0;
}