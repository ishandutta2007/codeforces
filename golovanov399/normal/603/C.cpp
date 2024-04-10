#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt(){
    int x;
    scanf("%d", &x);
    return x;
}

int mex(int x, int y){
    if (x && y)
        return 0;
    if (x == 1 || y == 1)
        return 2;
    else
        return 1;
}

const int ff[] = {0, 1, 0, 1, 2, 0, 2, 0, 1, 0, 1, 0};

int f(int n){
    if (n < 12)
        return ff[n];
    if (n % 2)
        return 0;
    if (f(n / 2) == 1)
        return 2;
    else
        return 1;
}

int main(){

    int n = nxt(), k = nxt();
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = nxt();
    k %= 2;
    int qw = 0;
    if (k == 1){
        for (int i = 0; i < n; i++){
            qw ^= f(a[i]);
        }
    } else {
        for (int i = 0; i < n; i++){
            qw ^= (a[i] < 3 ? a[i] : (1 - a[i] % 2));
        }
    }

    puts(qw ? "Kevin" : "Nicky");

    return 0;
}