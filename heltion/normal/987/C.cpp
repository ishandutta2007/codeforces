#include<bits/stdc++.h>
using namespace std;
#define maxn 3000
int s[3000], c[3000];
int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i += 1) scanf("%d", s + i);
    for(int i = 0; i < n; i += 1) scanf("%d", c + i);
    int ans = 1000000000;
    for(int j = 0; j < n ; j += 1){
        int ansi = 300000000;
        for(int i = j - 1; i >= 0; i -= 1)
            if(s[i] < s[j]) ansi = min(ansi, c[i]);
        if(ansi == 300000000) continue;
        int ansk = 300000000;
        for(int k = j + 1; k < n; k += 1)
            if(s[k] > s[j]) ansk = min(ansk, c[k]);
        if(ansk == 300000000) continue;
        ans = min(ans, ansi + ansk + c[j]);
    }
    printf("%d", ans == 1000000000 ? -1 : ans);
}