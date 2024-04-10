#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, a, b;
//char s[MN]; string str;

int main() {
    scanf("%d %d", &a, &b);

    int i = 1;
    while(1) {
        if(a < i) {
            printf("Vladik\n");
            return 0;
        }

        a -= i;
        i++;

        if(b < i) {
            printf("Valera\n");
            return 0;
        }

        b -= i;
        i++;
    }

    return 0;
}