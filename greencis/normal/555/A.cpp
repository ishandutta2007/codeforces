#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,k,x,a,ans;
vector<int> v;

int main()
{
    scanf("%d%d",&n,&k);
    ans = n - 1;
    while (k--) {
        scanf("%d",&x);
        ans += x - 1;
        v.clear();
        while (x--) {
            scanf("%d", &a);
            v.push_back(a);
        }
        int good = 0;
        for (int i = 0; i + 1 < v.size(); ++i) {
            if (v[i] + 1 == v[i+1]) {
                if (v[i] == 1) good = 1;
                if (good) ans -= 2;
            } else good = 0;
        }
    }
    cout << ans;

    return 0;
}