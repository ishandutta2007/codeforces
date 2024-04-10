#include<bits/stdc++.h>
using namespace std;

int w, h, x, y;
char a[1000][1000];
bool chk[1000][1000];
bool ans;

int main() {
    scanf("%d%d", &w, &h);

    for(int i=0; i<w; i++)
    {
        scanf("%s", a[i]);
    }

    for(int i=0; i<w; i++)
    {
        int cnt = 0;
        for(int j=0; j<h; j++) {
            if(a[i][j] == '*') cnt++;
        }

        if(cnt > 1) x = i;
    }

    for(int j=0; j<h; j++)
    {
        int cnt = 0;
        for(int i=0; i<w; i++) {
            if(a[i][j] == '*') cnt++;
        }

        if(cnt > 1) y = j;
    }

    if(x == 0 || x == w-1 || y == 0 || y == h-1) ans = true;

    for(int i=x; i<w; i++) {
        if(a[i][y] == '.') {
            if(i <= x+1) ans = true;
            break;
        }
        chk[i][y] = true;
    }

    for(int i=x; i>=0; i--) {
        if(a[i][y] == '.') {
            if( i >= x-1 ) ans = true;
            break;
        }
        chk[i][y] = true;
    }

    for(int j=y; j<h; j++) {
        if(a[x][j] == '.') {
            if(j <= y+1) ans = true;
            break;
        }
        chk[x][j] = true;
    }

    for(int j=y; j>=0; j--) {
        if(a[x][j] == '.') {
            if(j >= y-1) ans = true;
            break;
        }
        chk[x][j] = true;
    }

    for(int i=0; i<w; i++) {
        for(int j=0; j<h; j++) {
            if(chk[i][j]) continue;
            if(a[i][j] == '*') {
                printf("NO");
                return 0;
            }
        }
    }

    if(ans) {
        printf("NO");
        return 0;
    }

    printf("YES");
}