#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <ctype.h>
#include <functional>

using namespace std;

int n,k;
int cnt[5];
int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        cnt[k]++;
    }
    
    int tot = cnt[4];
    //printf("%d\n",tot);
    while (cnt[3] && cnt[1]) {
        cnt[3]--;
        cnt[1]--;
        tot++;
    }
    while (cnt[2] >= 2) {
        cnt[2]-=2;
        tot++;
    }
    //printf("%d\n",tot);
    while (cnt[2] && cnt[1]) {
        cnt[2]--;
        if (cnt[1] >= 2) cnt[1]-=2;
        else cnt[1]--;
        tot++;
    }
    
    //printf("%d\n",tot);
    tot += cnt[3]+(cnt[2]+1)/2+(cnt[1]+3)/4;
    
    printf("%d\n",tot);
}