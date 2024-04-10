#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
string s1, s2;
int n, i, cnt[5][5];
char a[2000015], b[2000015];
int main(){
    scanf("%d", &n);
    scanf("%s", a);
    scanf("%s", b);
    for (i = 0; i < n + n; i++) cnt[a[i] - '0'][b[i] - '0']++;
    for (i = 1; i <= n + n; i++){
        if (i & 1){
            if (cnt[1][1]){
                s1 += "1";
                cnt[1][1]--;
            }else if (cnt[1][0]){
                s1 += "1";
                cnt[1][0]--;
            }else if (cnt[0][1]){
                s1 += "0";
                cnt[0][1]--;
            }else{
                s1 += "0";
                cnt[0][0]--;
            }
        }else{
            if (cnt[1][1]){
                s2 += "1";
                cnt[1][1]--;
            }else if (cnt[0][1]){
                s2 += "1";
                cnt[0][1]--;
            }else if (cnt[1][0]){
                s2 += "0";
                cnt[1][0]--;
            }else{
                s2 += "0";
                cnt[0][0]--;
            }
        }
    }
    if (s1 == s2) puts("Draw"); else if (s1 > s2) puts("First"); else puts("Second");
}