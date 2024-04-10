#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;


char s[MN], grid[12][12]; string str;

int main() {
    for(int i=0; i<10; i++) {
        scanf("%s", s);
        for(int j=0; j<10; j++) {
            grid[i][j] = s[j];
        }
    }

    bool ans = false;
    for(int i=0; i<10; i++) {
        for(int j=0; j<10; j++) {
            int flag = 1;
            for(int k = 0; k < 5; k++) {
                if(i+k >= 10 || grid[i+k][j] == 'O') { flag = 10; break; }
                if(grid[i+k][j] == '.') flag--;
            } if(flag == 0) ans = true;

            flag = 1;
            for(int k = 0; k < 5; k++) {
                if(j+k >= 10 || grid[i][j+k] == 'O') { flag = 10; break; }
                if(grid[i][j+k] == '.') flag--;
            } if(flag == 0) ans = true;

            flag = 1;
            for(int k = 0; k < 5; k++) {
                if((i+k >=10) || (j+k >= 10) || grid[i+k][j+k] == 'O') { flag = 10; break; }
                if(grid[i+k][j+k] == '.') flag--;
            } if(flag == 0) ans = true;

            flag = 1;
            for(int k = 0; k < 5; k++) {
                if((i-k < 0) || (j+k >= 10) || grid[i-k][j+k] == 'O') { flag = 10; break; }
                if(grid[i-k][j+k] == '.') flag--;
            } if(flag == 0) ans = true;
        }
    }

    printf(ans ? "YES" : "NO");
    return 0;
}