#include <bits/stdc++.h>
#define MN 200020

using namespace std;

int n, L, a[MN], b[2*MN];
vector<pair<int, int> > interv, tmp1, tmp2;

int main() {
    scanf("%d %d", &n, &L);
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }
    sort(b, b + n);
    for(int i = n; i < 2*n; i++) {
        b[i] = b[i-n] + L;
    }

    int l = 0, r = L / 2, m;
    while(l < r) {
        m = (l + r) / 2;
        interv.clear();
        tmp1.clear();
        tmp2.clear();

        int lft, rite, mini = INT_MAX, k = -1;
        for(int i = 0; i < n; i++) {
            lft = (a[i] - m + L);
            if(lft >= L) lft -= L;

            rite = (a[i] + m);
            if(rite >= L) rite -= L;

            if(rite < lft) {
                tmp1.push_back({lft, rite + L});
            }
            else {
                tmp1.push_back({lft, rite});
                tmp2.push_back({lft + L, rite + L});
            }
        }

        for(int i = 0; i < tmp1.size(); i++) {
            if(tmp1[i].first < mini) {
                mini = tmp1[i].first;
                k = i;
            }
        }

        for(int i = k, j = 0; j < tmp1.size(); j++, i++) {
            if(i == tmp1.size()) i = 0;
            interv.push_back(tmp1[i]);
        }

        for(auto p : tmp2) interv.push_back(p);

        int f = 1, id = 0;
        for(auto p : interv) {
            lft = p.first, rite = p.second;
            while(id < 2*n && b[id] < lft) id++;
            if(b[id] > rite) {
                f = 0;
                break;
            }
            id++;
        }
        if(f) r = m;
        else l = m + 1;
    }

    printf("%d\n", l);
    return 0;
}