#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

int n, m, nums[200200], sol[200200];

struct oper {
    int type;
    int siz;
} opers[200200];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    int longest = 0, last = 1;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &opers[i].type, &opers[i].siz);
        longest = max(longest, opers[i].siz);
        last = opers[i].type;
    }

    sort(nums, nums+longest);

    vector < oper > opers1;

    opers1.push_back(opers[m-1]);

    for(int i = m-2; i >= 0; i--) {
        if (opers[i].siz > opers1.back().siz)
            opers1.push_back(opers[i]);
    }

    for (int i = longest; i < n; i++)
        sol[i] = nums[i];

    int ini = 0, fim = longest-1, next = longest-1;

    reverse(opers1.begin(), opers1.end());

    for (int pos = 0; pos < opers1.size(); pos++) {
        if (ini > fim) break;

        if (opers1[pos].type == 1 && pos < opers1.size()-1) {
            for (int i = 0; i < opers1[pos].siz - opers1[pos+1].siz; i++) {
                sol[next--] = nums[fim];
                fim--;
                if (ini > fim) break;
            }
        }
        else if (opers1[pos].type == 2 && pos < opers1.size()-1) {
            for (int i = 0; i < opers1[pos].siz - opers1[pos+1].siz; i++) {
                sol[next--] = nums[ini];
                ini++;
                if (ini > fim) break;
            }
        }
    }

    if (last == 1)
        for (int i = 0; i < opers1[opers1.size()-1].siz; i++) {
            sol[next--] = nums[fim];
            fim--;
            if (ini > fim) break;
        }
    else
        for (int i = 0; i < opers1[opers1.size()-1].siz; i++) {
            sol[next--] = nums[ini];
            ini++;
            if (ini > fim) break;
        }

    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", sol[i]);
    }
    printf("\n");
    return 0;
}