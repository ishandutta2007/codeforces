#include <bits/stdc++.h>

#define X first
#define Y second

using namespace std;

bool path[8], check[8];
pair<int,int> pos[8];

int main() {
    int n, x, y, nx, ny;
    char t;

    cin >> n >> x >> y;

    for(int i=0;i<n;i++) {
        scanf(" %c %d %d", &t, &nx, &ny);
        if(nx == x) {
            if(ny > y) {
                if(!path[0] || (path[0] && ny < pos[0].Y)) {
                    path[0] = 1;
                    pos[0] = {nx, ny};
                    if(t == 'B') check[0] = 0;
                    else check[0] = 1;
                }
            }
            else {
                if(!path[1] || (path[1] && ny > pos[1].Y)) {
                    path[1] = 1;
                    pos[1] = {nx, ny};
                    if(t == 'B') check[1] = 0;
                    else check[1] = 1;
                }
            }
        }

        if(ny == y) {
            if(nx > x) {
                if(!path[2] || (path[2] && nx < pos[2].X)) {
                    path[2] = 1;
                    pos[2] = {nx, ny};
                    if(t == 'B') check[2] = 0;
                    else check[2] = 1;
                }
            }
            else {
                if(!path[3] || (path[3] && nx > pos[3].X)) {
                    path[3] = 1;
                    pos[3] = {nx, ny};
                    if(t == 'B') check[3] = 0;
                    else check[3] = 1;
                }
            }
        }

        if(nx + ny == x + y) {
            if(nx > x) {
                if(!path[4] || (path[4] && nx < pos[4].X)) {
                    path[4] = 1;
                    pos[4] = {nx, ny};
                    if(t == 'R') check[4] = 0;
                    else check[4] = 1;
                }
            }
            else {
                if(!path[5] || (path[5] && nx > pos[5].X)) {
                    path[5] = 1;
                    pos[5] = {nx, ny};
                    if(t == 'R') check[5] = 0;
                    else check[5] = 1;
                }
            }
        }

        if(nx - ny == x- y) {
            if(nx > x) {
                if(!path[6] || (path[6] && nx < pos[6].X)) {
                    path[6] = 1;
                    pos[6] = {nx, ny};
                    if(t == 'R') check[6] = 0;
                    else check[6] = 1;
                }
            }
            else {
                if(!path[7] || (path[7] && nx > pos[7].X)) {
                    path[7] = 1;
                    pos[7] = {nx, ny};
                    if(t == 'R') check[7] = 0;
                    else check[7] = 1;
                }
            }
        }
    }

    int flag = 0;
    for(int i=0;i<8;i++) {
        if(check[i]) flag = 1;
    }
    if(flag) printf("YES\n");
    else printf("NO\n");

    return 0;
}