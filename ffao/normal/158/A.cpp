#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <ctype.h>
#include <functional>

using namespace std;

int n,k;
int arr[1000];
int main() {
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    int cnt = 0;
    for (int i = 0; i < k; i++) {
        if (arr[i] > 0) cnt++;
    }
    
    for (int i = k; i < n; i++) {
        if (arr[i] == arr[k-1] && arr[i]) cnt++;
    }
    
    printf("%d\n",cnt);
}