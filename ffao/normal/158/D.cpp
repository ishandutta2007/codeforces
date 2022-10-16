#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <ctype.h>
#include <functional>

using namespace std;

#define INF 1000000000

int n,k;
int arr[30000];

int main() {
    scanf("%d",&n);
    
    int best = -INF;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    for (int i = 1; i*i <= n && 3*i <= n; i++) {
        if (n%i==0) {
            int div = i;
            for (int j = 0; j < div; j++) {
                int sum=0;
                for (int k = j; k < n; k+=div){
                    sum+=arr[k];
                }
                best=max(best,sum);
            }
            
            if (i >= 3) {
                div = n/i;
                for (int j = 0; j < div; j++) {
                    int sum=0;
                    for (int k = j; k < n; k+=div){
                        sum+=arr[k];
                    }
                    best=max(best,sum);
                }
            }
        }
    }
    
    printf("%d\n",best);
}