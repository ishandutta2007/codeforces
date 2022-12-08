#include <iostream>
#include <cstdio>

using namespace std;

int N, H, A, B, K;

int main() {
    scanf("%d%d%d%d%d", &N, &H, &A, &B, &K);
    
    for(int i = 0;i < K;i++) {
        int a, ta, b, tb;
        scanf("%d%d%d%d", &ta, &a, &tb, &b);
        
        if(ta == tb) {
            printf("%d\n", abs(b - a));
        }
        else if(a > B and b > B)
        {
            printf("%d\n", (a-B) + (b-B) + abs(tb-ta));
        }
        else if (a < A and b < A)
        {
            printf("%d\n", (A-a) + (A-b) + abs(tb-ta));
        }
        else printf("%d\n", abs(a-b) + abs(tb-ta));
    }
    
    return 0;
}