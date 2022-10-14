#include <cstdio>
#include <cstring>

int main() {
    int h1, m1, h2, m2;
    scanf("%d:%d%d:%d", &h1, &m1, &h2, &m2);
    printf("%02d:%02d\n", (h1 + 24 - h2 - (m1 < m2)) % 24, (m1 + 60 - m2) % 60);
    return 0;
}