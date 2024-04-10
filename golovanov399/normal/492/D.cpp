#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

int a[100010];
LL wq[2000010];

int main(){

    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);
    int g = __gcd(x, y);
    for (int i = 0; i < n; i++)
        scanf("%d", a + i);
    x /= g;
    y /= g;
    // swap(x, y);
    int s = x + y;
    int cnt = 0;
    long long l = x, r = y;
    while (l != r){
        if (l < r){
            wq[cnt++] = 2;
            l += x;
        } else {
            wq[cnt++] = 1;
            r += y;
        }
    }
    wq[s - 1] = wq[s - 2] = 0;
    string A[3] = {"Both", "Vanya", "Vova"};
    for (int i = 0; i < n; i++){
        a[i]--;
        a[i] %= s;
        int X = wq[a[i]];
        cout << A[X] << "\n";
    }

    return 0;
}