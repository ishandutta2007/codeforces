#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

int n;
int arr[100010];

int main() {
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    sort(arr, arr+n);
    
    if (arr[n-1] == 1) arr[n-1] = 2;
    else arr[n-1] = 1;
    
    sort(arr, arr+n);
    
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i+1 != n) printf(" ");
        else printf("\n");
    }
}