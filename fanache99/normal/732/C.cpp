#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    long long a, b, c;
    scanf("%I64d%I64d%I64d", &a, &b, &c);
    long long x = min(a, min(b, c));
    a -= x;
    b -= x;
    c -= x;
    if (a + b + c == 0) {
        printf("0\n");
        return 0;
    }
    if (a + b == 0 || b + c == 0 || a + c == 0) {
        if (a != 0)
            printf("%I64d\n", 2 * (a - 1));
        if (b != 0)
            printf("%I64d\n", 2 * (b - 1));
        if (c != 0)
            printf("%I64d\n", 2 * (c - 1));
        return 0;
    }
    long long answer = 0;
    if (a == 0) {
        x = min(b, c);
        answer += x;
        b -= x;
        c -= x;
        if (b + c == 0)
            answer--;
        else
            if (b == 0)
                answer += 2 * (c - 1);
            else
                answer += 2 * (b - 1);
        printf("%I64d\n", answer);
    }
    else
        if (b == 0) {
            x = min(a, c);
            answer += x;
            a -= x;
            c -= x;
            if (a + c == 0)
                answer--;
            if (a == 0 && c != 0)
                answer += 2 * (c - 1);
            if (a != 0 && c == 0)
                answer += 2 * (a - 1);
            printf("%I64d\n", answer);
        }
        else {
            x = min(a, b);
            answer += x;
            a -= x;
            b -= x;
            if (a + b == 0)
                answer--;
            else
                if (b == 0)
                    answer += 2 * (a - 1);
                else
                    answer += 2 * (b - 1);
            printf("%I64d\n", answer);
        }
    return 0;
}