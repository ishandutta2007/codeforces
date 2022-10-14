#include <cctype>
#include <cstdio>
#include <set>

const int N = 200;

char s[N + 1];

int main()
{
    int n;
    scanf("%d%s", &n, s);
    std::set<char> c;
    int result = 0;
    for (int i = 0; i < n; ++ i) {
        if (islower(s[i])) {
            c.insert(s[i]);
        } else {
            result = std::max(result, (int)c.size());
            c.clear();
        }
    }
    result = std::max(result, (int)c.size());
    printf("%d\n", result);
}