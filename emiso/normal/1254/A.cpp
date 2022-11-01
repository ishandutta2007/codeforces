#include <bits/stdc++.h>

using namespace std;

int t, r, c, k, rice, quant, modi;
char gr[110][110], ans[110][110];

char g(int x) {
    x = min(x, k-1);
    if(x < 26) return 'A' + x;
    else if(x < 52) return 'a' + (x - 26);
    else return '0' + (x - 52);
}

int main() {
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d %d", &r, &c, &k);
        rice = 0;
        for(int i = 0; i < r; i++) {
            scanf("%s", gr[i]);
            for(int j = 0; j < c; j++) rice += (gr[i][j] == 'R');
        }
        quant = rice / k;
        modi = rice - rice / k * k;

        int id = 0, dir = 0, tmp = 0;
        for(int i = 0; i < r; i++) {
            if(!dir) {
                for(int j = 0; j < c; j++) {
                    ans[i][j] = g(id);
                    if(gr[i][j] == 'R') {
                        tmp++;
                        if((id < modi && (tmp >= quant + 1)) || (id >= modi && tmp >= quant)) {
                            id++;
                            tmp = 0;
                        }
                    }
                    dir = 1;
                }
            }
            else {
                for(int j = c-1; j >= 0; j--) {
                    ans[i][j] = g(id);
                    if(gr[i][j] == 'R') {
                        tmp++;
                        if((id < modi && (tmp >= quant + 1)) || (id >= modi && tmp >= quant)) {
                            id++;
                            tmp = 0;
                        }
                    }
                    dir = 0;
                }
            }
        }
        assert(tmp == 0);

        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                printf("%c", ans[i][j]);
            }
            puts("");
        }
    }
    return 0;
}