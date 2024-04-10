#include <cstdio>
#include <cstring>
#include <map>

int n, m, k;
std::map <int, int> count;

int main() {
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; ++ i) {
        int a;
        scanf("%d", &a);
        count[a] += 1;
    }
    for (int i = 0; i < m; ++ i) {
        int b;
        scanf("%d", &b);
        count[b] -= 1;
    }
    int sum = 0;
    bool found = false;
    for (std::map <int, int> :: reverse_iterator iter = count.rbegin(); iter != count.rend(); ++ iter) {
        sum += iter->second;
        found |= sum > 0;
    }
    puts(found ? "YES" : "NO");
    return 0;
}