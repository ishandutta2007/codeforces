#include <cstdio>
#include <set>
#include <algorithm>

using namespace std;

const int MAXN = 200000;

int a[1 + MAXN], t[1 + MAXN];
set<pair<int, int> > full, half;
bool isHalf[1 + MAXN];

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n, w, k;
    int time = 0, value = 0, answer = 0;
    scanf("%d%d%d", &n, &w, &k);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &t[i]);
    int right = n;
    for (int left = n; left >= 1; left--) {
        value += a[left];
        if (half.size() != w) {
            half.insert(make_pair(t[left], left));
            time += (t[left] + 1) / 2;
            isHalf[left] = true;
        }
        else {
            pair<int, int> temp = *half.begin();
            if (t[left] <= temp.first) {
                full.insert(make_pair(t[left], left));
                time += t[left];
            }
            else {
                half.erase(temp);
                time -= (temp.first + 1) / 2;
                time += temp.first;
                full.insert(temp);
                isHalf[temp.second] = false;
                half.insert(make_pair(t[left], left));
                time += (t[left] + 1) / 2;
                isHalf[left] = true;
            }
        }
        while (time > k) {
            value -= a[right];
            if (!isHalf[right]) {
                time -= t[right];
                full.erase(make_pair(t[right], right));
            }
            else {
                time -= (t[right] + 1) / 2;
                half.erase(make_pair(t[right], right));
                if (!full.empty()) {
                    pair<int, int> temp = *full.rbegin();
                    time -= temp.first;
                    time += (temp.first + 1) / 2;
                    full.erase(temp);
                    half.insert(temp);
                    isHalf[temp.second] = true;
                }
            }
            right--;
        }
        answer = max(answer, value);
        /*for (auto &it : full)
            printf("%d ", it.second);
        printf("\n");
        for (auto &it : half)
            printf("%d ", it.second);
        printf("\n");
        printf("\n");*/
    }
    printf("%d\n", answer);
    return 0;
}