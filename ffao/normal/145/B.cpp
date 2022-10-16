#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

char ans[200010];

int doit(int c4, int c7, int c47, int c74, int la, char* ans) {
    if (c47 > c74 + 1 || c74 > c47 + 1) return -1;
    
    if (c74 > c47 && la != '7') {
        *ans = '7';
    } 
    
    *ans='4'; 
}
int c4, c7, c47,c74;

int main() {
    scanf("%d %d %d %d", &c4, &c7, &c47, &c74);
    
    int need4, need7, start;
    
    
    if (c47 > c74) {
        need4 = need7 = c47;
        start = 4;
    }
    else if (c74 > c47) {
        need7 = need4 = c74;
        start = 7;
    }
    if (c47 == c74) {
        if (c4 >= c47+1) {
            need4 = c47+1;
            need7 = c47;
            start = 4;
        }
        else {
            need4 = c47;
            need7 = c47+1;
            start = 7;
        }
    }
    
    bool do4 = false;
    
    if (need4 > c4 || need7 > c7 || abs(c47-c74) > 1) {
        printf("-1\n");
        return 0;
    }
    
    for (int i = 0; c4 > 0 || c7 > 0; i++) {
        if (start == 4 && !do4) {
            int exc = c4-need4;
            for (int j = 0; j < exc; j++) {c4--; printf("4");}
        }
        
        if (need7 == 1 && start == 7) {
            while (c7) {c7--; printf("7");}
        }
        else {
            printf("%d", start);
        }
        
        if (start == 4) {
            c4--;
            start = 7;
        }
        else {c7--; need7--; start = 4;}
    }
}