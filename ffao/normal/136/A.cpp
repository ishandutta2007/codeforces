#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    
    int rev[1000];
    
    for (int i = 0; i < n; i++) {
        int p;
        scanf("%d", &p);
        
        rev[p] = i+1;
    }
    
    for (int i = 1; i <= n; i++) {
        printf("%d", rev[i]);
        if (i != n) printf(" ");
        else printf("\n");
    }
}