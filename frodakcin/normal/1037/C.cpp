#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1010000;

int N;

bool a[MAXN], c[MAXN];

int main() {
    scanf("%d", &N);
    
    char inp;
    for(int i = 0;i < N;i++) {
        scanf(" %c", &inp);
        a[i] = (inp == '1');
    }
    for(int i = 0;i < N;i++) {
        scanf(" %c", &inp);
        c[i] = ((inp == '1') xor a[i]);
    }
    
    int ans = 0;
    for(int i = 0;i < N;i++) ans += c[i];
    
    
    for(int i = 1;i < N;i++) {
        if(c[i] and c[i - 1] and (a[i] != a[i-1])) {
            ans--;
            i++;
        }
    }
    
    printf("%d\n", ans);
}