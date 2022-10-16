#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

char bd[1100][1100];
int n, m;

int rt[1100][1100];
int down[1100][1100];
int cnt[1100][1100];

int check(int width, int height, int x, int y) {
    //printf("checking %d %d\n", width, height);
    int filled = 0;
    bool first = true;

    while (true) {
        int godown = down[x][y] - height;
        if (godown < 0) break;

        //printf("godown %d\n", godown);
        if (cnt[x][y] - cnt[x][y+width] - cnt[x+down[x][y]][y] + cnt[x+down[x][y]][y+width]
            == width * down[x][y]) {

            if (first) {
                filled += width * down[x][y];
                first = false;
            }
            else {
                filled += height + width * godown; 
            }
        }
        else break;

        //printf("filled is now %d\n", filled);

        if ((y+1) + width <= m) {
            y++;
            x += godown;
        }
        else break;
    }

    return filled;
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) scanf("%s", bd[i]);

    for (int i = n-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--) {
            if (bd[i][j] == '.') {
                rt[i][j] = down[i][j] = 0;
            }
            else {
                rt[i][j] = 1 + rt[i][j+1];
                down[i][j] = 1 + down[i+1][j];
            }
        }
    }   

    int tlx = -1;
    int tly = -1;
    int tot = 0;
    for (int i = n-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--) {
            if (bd[i][j]=='X') {
                tlx = i;
                tly = j;
                tot++;
            }

            cnt[i][j] = (bd[i][j]=='X') + cnt[i+1][j] + cnt[i][j+1] - cnt[i+1][j+1];
        }
    }

    int best = 1000000000;
    for (int height = 1; height <= down[tlx][tly]; height++) {
        int width = rt[tlx][tly];
        int filled = check(width, height, tlx, tly);
        if (filled == tot) best = min(best, width*height);
    }
    for (int width = 1; width <= rt[tlx][tly]; width++) {
        int height = down[tlx][tly];
        int filled = check(width, height, tlx, tly);
        if (filled == tot) best = min(best, width*height);
    }

    printf("%d\n", best == 1000000000 ? -1 : best);
}