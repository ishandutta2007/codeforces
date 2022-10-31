#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>

#define w1 while(1)
#define pint(n) printf("%d\n",n)
#define fill(n,m) memset(n,m,sizeof(n))

using namespace std;

int f[3],flag[3];

int main()
{
    int n;
    string str;
    cin >> n >> str;
    for(int i=0;i<str.size();i++) {
        if(str[i] == 'R') f[2]++;
        else if(str[i] == 'B') f[0]++;
        else f[1]++;
    }

    for(int i=0;i<3;i++) {
        if(f[i] && !f[(i+1)%3] && !f[(i+2)%3]) flag[i] = 1;
    }

    if(n == 2) {
        if(f[0] && f[1]) flag[2] = 1;
        else if(f[0] && f[2]) flag[1] = 1;
        else if(f[1] && f[2]) flag[0] = 1;
    }

    else if(f[0] && f[1] && f[2]) {
        flag[0] = 1;
        flag[1] = 1;
        flag[2] = 1;
    }

    else {
        for(int i=0;i<3;i++) {
            if(f[i] > 1 && f[(i+1)%3] > 1 && !f[(i+2)%3]) {
                flag[0] = 1;
                flag[1] = 1;
                flag[2] = 1;
            }

            if(f[i] > 1 && f[(i+1)%3] == 1 && !f[(i+2)%3]) {
                flag[(i+1)%3] = 1;
                flag[(i+2)%3] = 1;
            }

            if(f[i] == 1 && f[(i+1)%3] > 1 && !f[(i+2)%3]) {
                flag[i] = 1;
                flag[(i+2)%3] = 1;
            }
        }
    }

    if(flag[0]) printf("B");
    if(flag[1]) printf("G");
    if(flag[2]) printf("R");
    puts("");

    return 0;
}