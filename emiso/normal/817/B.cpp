#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, a;
map<long long, long long> mapa;
vector<long long> quant;

long long comb3(long long n) {
    return n * (n - 1) * (n - 2) / 6;
}

long long comb2(long long n) {
    return n * (n - 1) / 2;
}

int main() {
    scanf("%d", &n);

    for(int i=1; i<=n; i++) {
        scanf("%d",&a);
        mapa[a]++;
    }

    int s = 0;
    while(s < 3) {
        quant.push_back((*mapa.begin()).second);
        s += quant.back();
        mapa.erase(mapa.begin());
    }

    long long ans = 1;
    if(quant[0] >= 3) {
        ans = max(ans,  comb3(quant[0]));
    } else {
        if(quant[0] + quant[1] >= 3) {
            if(quant[0] == 1) {
                ans = max(ans, comb2(quant[1]));
            } else {
                ans = max(ans, quant[1]);
            }
        }

        else {
            ans = max(ans, quant[2]);
        }
    }

    cout << ans << endl;

    return 0;
}