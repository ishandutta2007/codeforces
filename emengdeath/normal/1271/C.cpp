#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 1e6;
int a[N][2], s[2];
int b[8][2]={{1,0},{-1,0},{0,-1},{0,1},{1,1},{1,-1},{-1,1},{-1,-1}};
int ans[2], ansv;
int n;
int get(int x, int y) {
    int sum = 0;
    for (int i = 1; i <= n; i ++)
        sum += (min(a[i][0], s[0]) <= x && max(a[i][0], s[0]) >= x && min(a[i][1], s[1]) <= y && max(a[i][1], s[1]) >= y);
    return sum;
}
int main(){
    scanf("%d %d %d", &n, &s[0], &s[1]);
    for (int i =1; i <= n ; i ++)
        scanf("%d %d", &a[i][0], &a[i][1]);
    for (int i = 0; i < 8; i ++)
        if (get(s[0] + b[i][0], s[1] + b[i][1]) > ansv) {
            ansv = get(s[0] + b[i][0], s[1] + b[i][1]);
            ans[0] = s[0] + b[i][0];
            ans[1] = s[1] + b[i][1];
        }
    printf("%d\n%d %d",ansv, ans[0],ans[1]);
}