#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 101000;
const int CHARNUM = 26;

int N;
int dogs[CHARNUM];

int main() {
    scanf("%d", &N);
    
    for(int i = 0;i < CHARNUM;i++) {
        dogs[i] = 0;
    }
    
    char c;
    for(int i = 0;i < N;i++) {
        scanf(" %c", &c);
        dogs[static_cast<int> (c - 97)]++;
    }
    
    bool ans = false;
    if(N == 1) ans = true;
    for(int i = 0;i < CHARNUM;i++) {
        if(dogs[i] >= 2) ans = true;
    }
    
    if(ans) printf("Yes\n");
    else printf("No\n");
    
    return 0;
}