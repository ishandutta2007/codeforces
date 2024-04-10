#include <set>
#include <stdio.h>
#include <vector>

using namespace std;

set<int> alive;
int beat[1000000];

int n,m,l,r,x;

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) alive.insert(i);

    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &l, &r, &x);

        set<int>::iterator first = alive.lower_bound(l);
        vector<int> rem;

        while (first != alive.end() && *first <= r) {
            if (*first != x) {
                rem.push_back(*first);
                beat[*first]=x;
            }
            first++;
        }

        for (int j = 0; j < rem.size(); j++) {
            alive.erase(rem[j]);
        }
    }

    for (int i = 1; i <= n; i++) {
        printf("%d ", beat[i]);
    }
}