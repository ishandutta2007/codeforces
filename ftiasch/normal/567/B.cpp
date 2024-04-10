#include <cstdio>
#include <set>

const int N = 100;

char c[N];
int id[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        char buffer[2];
        scanf("%s%d", buffer, id + i);
        c[i] = *buffer;
    }
    std::set <int> set;
    int count = 0;
    for (int i = 0; i < n; ++ i) {
        if (c[i] == '-' && !set.count(id[i])) {
            count ++;
        }
        set.insert(id[i]);
    }
    int result = count;
    for (int i = 0; i < n; ++ i) {
        count += c[i] == '+' ? 1 : -1;
        result = std::max(result, count);
    }
    printf("%d\n", result);
    return 0;
}