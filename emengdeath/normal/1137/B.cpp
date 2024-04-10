#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
char s[2000000], t[2000000];
int n;
int sum[2];
int Next[2000000], Next1[2000000][2];
int main(){
    scanf("%s", s);
    scanf("%s", t);
    n = strlen(t);
    Next[0] = 0;
    for (int i=1, j = 0 ;i<n;i++){
        while (j && t[i] != t[j]) j = Next[j - 1];
        if (t[i] == t[j]) j ++;
        Next[i] = j;
        int k = Next[i - 1];
        Next1[i][0] = Next1[k][0];
        Next1[i][1] = Next1[k][1];
        Next1[i][t[k] - '0'] = k;
    }
    int lens = strlen(s);
    for (int i = 0; i < lens; i++)
        sum[s[i] - '0'] ++;
    int l = 0;
    for (int i = 0; i < lens; i ++){
        bool x = t[l] - '0';
        if (!sum[x]) l = Next1[l][x];
        if (!sum[x]) {
            putchar(((x) ^ 1) + '0');
            sum[(x) ^ 1] --;
        } else {
            putchar(x + '0');
            sum[x] --;
            if (l == n - 1) l = Next[l];
            else
                l ++;
        }
    }
    return 0;
}