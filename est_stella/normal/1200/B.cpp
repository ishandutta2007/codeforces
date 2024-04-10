#include<bits/stdc++.h>
using namespace std;

int t;
int n, m, k;
int arr[110];

int main() {
    scanf("%d", &t);

    while(t--) {
        scanf("%d%d%d", &n, &m, &k);

        for(int i=0; i<n; i++) {
            scanf("%d", &arr[i]);
        }

        bool flag = false;
        for(int i=0; i<n-1; i++) {
            if(m + arr[i] + k >= arr[i+1]) {
                m = m + arr[i] - max(arr[i+1] - k, 0);
            }
            else {
                printf("NO\n");
                flag = true;
                break;
            }
        }

        if(!flag) printf("YES\n");
    }
}