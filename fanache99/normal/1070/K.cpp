#include <fstream>

using namespace std;

const int MAXN = 100000;
const int MAXK = 100000;

int v[1 + MAXN];
int answer[1 + MAXK];

int main() {
    //freopen("K.in", "r", stdin);
    //freopen("K.out", "w", stdout);
    int n, k, sum = 0;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &v[i]);
        sum += v[i];
    }
    if (sum % k != 0) {
        printf("No\n");
        return 0;
    }
    int target = sum / k;
    for (int i = 1, j = 1; i <= k; i++) {
        sum = 0;
        int start = j;
        while (sum < target) {
            sum += v[j];
            j++;
        }
        if (sum > target) {
            printf("No\n");
            return 0;
        }
        answer[i] = j - start;
    }
    printf("Yes\n");
    for (int i = 1; i <= k; i++)
        printf("%d ", answer[i]);
    return 0;
}