#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x, hard = 0;
    scanf("%d", &n);
    while(n--) {
        scanf("%d", &x);
        if(x) hard = 1;
    }
    puts(hard ? "Hard" : "Easy");
    return 0;
}