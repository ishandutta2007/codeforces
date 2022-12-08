#include <iostream>
#include <cstdio>

using namespace std;

int N;

int main() {
    bool ans = false;
    scanf("%d", &N);
    
    int v;
    for(int i = 0;i < N;i++) {
        scanf("%d", &v);
        if(v) ans = true;
    }
    
    if(ans) printf("HARD\n");
    else printf("EASY\n");
    
    return 0;
}