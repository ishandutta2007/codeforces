#include <stdio.h>
#include <algorithm>
#include <cstring>
using namespace std;

char digA[100010], digB[100010];
int cntA[10], cntB[10];

int main() {
    gets(digA);
    gets(digB);
    
    int l = strlen(digA);
    
    int mm = 0;
    for (int i = 0; i < l; i++) {
        if (digA[i] != digB[i]) mm++;
        cntA[digA[i]-'0']++;
        cntB[digB[i]-'0']++;
    }
    
    int tot = abs(cntA[4]-cntB[4]);
    printf("%d\n", tot+(mm-tot)/2);
}