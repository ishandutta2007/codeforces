#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int s, v1, v2, t1, t2, a1, a2;
//char s[MN]; string str;

int main() {
    scanf("%d %d %d %d %d", &s, &v1, &v2, &t1, &t2);

    a1 = s * v1 + 2 * t1;
    a2 = s * v2 + 2 * t2;

    if(a1 != a2) printf("%s\n", (a1 > a2) ? "Second" : "First");
    else puts("Friendship");

    return 0;
}