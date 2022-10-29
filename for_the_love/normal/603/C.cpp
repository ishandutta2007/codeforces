#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;


map <int, int> sg;
int k;

int dfs(int x){
    if (sg.find(x) != sg.end()) return sg[x];
    if (x % 2 == 0){
        if (k % 2 == 0){
            return sg[x] = 1;
        }else{
            if (dfs(x / 2) == 1) return sg[x] = 2;
            else return sg[x] = 1;
        }
    }else return sg[x] = 0;
}

int main(){
    int n, ans = 0, x;
    scanf("%d%d", &n, &k);
    if (k % 2 == 0){
        sg[0] = 0;
        sg[1] = 1;
        sg[2] = 2;
        sg[3] = 0;
        sg[4] = 1;
        sg[5] = 0;
    }else{
        sg[0] = 0;
        sg[1] = 1;
        sg[2] = 0;
        sg[3] = 1;
        sg[4] = 2;
        sg[5] = 0;
    }

    for (int i = 0; i < n; i++){
        scanf("%d", &x);
        ans ^= dfs(x);
    }
    puts(ans == 0 ? "Nicky" : "Kevin");
}