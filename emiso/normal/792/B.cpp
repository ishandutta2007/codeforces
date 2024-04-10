#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, k, a, l = 0;
vector<int> ingame;

//char s[MN]; string str;

int main() {
    scanf("%d %d", &n, &k);

    for(int i=1;i<=n;i++) ingame.push_back(i);

    for(int i=0;i<k;i++) {
        scanf("%d", &a);

        a = (l + a) % (int) ingame.size();

        printf("%d ", ingame[a]);
        ingame.erase(ingame.begin() + a);

        a %= (int) ingame.size();
        l = a;
    }
    return 0;
}