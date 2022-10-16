#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;
#define INF 1000000000

int arr[300001];
int last[300001];

int nextL[300001];
int nextR[300001];
int n;

int do_it(int one) {
    int ans = -1;

    int j = one;
    int C = 0;
    for (int i = one; i >= 0; i--) {
        if (nextR[i] != -1 && nextR[i] <= one) break;
        else if (nextR[i] != -1 && nextR[i] <= j) j = nextR[i]-1;

        C = max(C, arr[i]);

        while (j+1<n && arr[j+1] < C && (nextL[j+1] == -1 || nextL[j+1] < i)) {
            j++;
        }

        if (j-i+1 == C) ans++;
    }

    int i = one;
    C = 0;
    for (int j = one; j < n; j++) {
        if (nextL[j] != -1 && nextL[j] >= one) break;
        else if (nextL[j] != -1 && nextL[j] >= i) i = nextL[j]+1;

        C = max(C, arr[j]);

        while (i-1>=0 && arr[i-1] < C && (nextR[i-1] == -1 || nextR[i-1] > j)) {
            i--;
        }

        if (j-i+1 == C) ans++;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    scanf("%d", &n);
    memset(last,-1,sizeof(last));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);

        nextL[i] = last[arr[i]];
        last[arr[i]]=i;
    }

    memset(last,-1,sizeof(last));
    for (int i = n; i >= 0; i--) {
        nextR[i] = last[arr[i]];
        last[arr[i]]=i;
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 1) {
            ans += do_it(i);
        }
    }

    printf("%d\n", ans);
    return 0;
}