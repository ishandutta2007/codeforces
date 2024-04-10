#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, h;

//char s[MN]; string str;

int main() {
    scanf("%d %d", &n, &h);
    double area = h / 2.0;
    double ai = area / n;

    for(int i=1; i<n; i++) {
        double ad = i * ai;
        double b = sqrt(ad * 2 / h);
        //b * H / 2 = ad
        printf("%.9f\n", ad * 2 / b);
    }
    return 0;
}