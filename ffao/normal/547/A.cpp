#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

int m, h1, a1, x1, y1, h2, a2, x2, y2;

pair<int, int> solve(int h, int a, int x, int y) {
    pair<int, int> ans = {-1,-1};
    int occ = 0;
    int curr = h;
    for (int i = 0; i < 3*m; i++) {
        if (curr == a) {
            if (occ == 0) {
                ans.first = i;
                occ++;
            }
            else {
                ans.second = i;
                return ans;
            } 
        }

        curr = (curr * 1ll * x + y) % m;
    }

    return ans;
}

int main() {
    scanf("%d",&m);
    scanf("%d %d", &h1, &a1);
    scanf("%d %d", &x1, &y1);
    scanf("%d %d", &h2, &a2);
    scanf("%d %d", &x2, &y2);

    pair<int, int> xaniar = solve(h1,a1,x1,y1);
    pair<int, int> abol = solve(h2,a2,x2,y2);

    if (abol.second == -1) swap(abol, xaniar);

    if (xaniar.second == -1) {
        if (abol.second == -1) {
            if (xaniar.first == abol.first) printf("%d\n", xaniar.first);
            else printf("-1\n");
        }
        else {
            int cyc = abol.second - abol.first;
            if (xaniar.first >= abol.first && (xaniar.first - abol.first) % cyc == 0) printf("%d\n", xaniar.first);
            else printf("-1\n");
        }
        return 0;
    }

    int cyc_x = xaniar.second - xaniar.first;
    int cyc_a = abol.second - abol.first;

    long long curr = abol.first;
    for (int i = 0; i < 3*m; i++) {
        if (curr >= xaniar.first && (curr % cyc_x) == (xaniar.first % cyc_x)) {
            printf("%lld\n", curr);
            return 0;
        }
        curr += cyc_a;
    }
    printf("-1\n");
}