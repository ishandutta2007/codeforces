#include <cstdio>

using namespace std;

int cows[2000005];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        scanf("%d", cows + i);
    long long ans = 0;
    int rightCows = 0;
    for (int i = 0; i < n; ++i){
        if (cows[i] == 0){
            ans += rightCows;
        }
        else
            ++rightCows;
    }
    printf("%I64d\n", ans);
    return 0;
}