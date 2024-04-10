#include <cstdio>
#include <set>
#include <cstring>

using namespace std;

int Contain(int a1, int b1, int a2, int b2, int x1, int y1, int x2, int y2) {
    if (a1 <= x1 && x2 <= a2 && b1 <= y1 && y2 <= b2)
        return 1;
    return 0;
}

int main() {
    //freopen("tema.in", "r", stdin);
    //freopen("tema.out", "w", stdout);
    int n;
    int x11, y11, x12, y12, x21, y21, x22, y22;
    scanf("%d", &n);
    int left = 1, right = n, answer;
    while (left <= right) {
        int middle = (left + right) / 2;
        printf("? %d %d %d %d\n", middle, 1, n, n);
        fflush(stdout);
        int ok;
        scanf("%d", &ok);
        if (ok >= 1) {
            answer = middle;
            left = middle + 1;
        }
        else
            right = middle - 1;
    }
    x11 = answer;
    left = x11, right = n, answer;
    while (left <= right) {
        int middle = (left + right) / 2;
        printf("? %d %d %d %d\n", x11, 1, middle, n);
        fflush(stdout);
        int ok;
        scanf("%d", &ok);
        if (ok >= 1) {
            answer = middle;
            right = middle - 1;
        }
        else
            left = middle + 1;
    }
    x12 = answer;
    left = 1, right = n, answer;
    while (left <= right) {
        int middle = (left + right) / 2;
        printf("? %d %d %d %d\n", x11, middle, x12, n);
        fflush(stdout);
        int ok;
        scanf("%d", &ok);
        if (ok >= 1) {
            answer = middle;
            left = middle + 1;
        }
        else
            right = middle - 1;
    }
    y11 = answer;
    left = y11, right = n, answer;
    while (left <= right) {
        int middle = (left + right) / 2;
        printf("? %d %d %d %d\n", x11, y11, x12, middle);
        fflush(stdout);
        int ok;
        scanf("%d", &ok);
        if (ok >= 1) {
            answer = middle;
            right = middle - 1;
        }
        else
            left = middle + 1;
    }
    y12 = answer;


    left = 1, right = n, answer;
    while (left <= right) {
        int middle = (left + right) / 2;
        printf("? %d %d %d %d\n", middle, 1, n, n);
        fflush(stdout);
        int ok;
        scanf("%d", &ok);
        int subtract = Contain(middle, 1, n, n, x11, y11, x12, y12);
        if (ok - subtract >= 1) {
            answer = middle;
            left = middle + 1;
        }
        else
            right = middle - 1;
    }
    x21 = answer;
    left = x21, right = n, answer;
    while (left <= right) {
        int middle = (left + right) / 2;
        printf("? %d %d %d %d\n", x21, 1, middle, n);
        fflush(stdout);
        int ok;
        scanf("%d", &ok);
        int subtract = Contain(x21, 1, middle, n, x11, y11, x12, y12);
        if (ok - subtract >= 1) {
            answer = middle;
            right = middle - 1;
        }
        else
            left = middle + 1;
    }
    x22 = answer;
    left = 1, right = n, answer;
    while (left <= right) {
        int middle = (left + right) / 2;
        printf("? %d %d %d %d\n", x21, middle, x22, n);
        fflush(stdout);
        int ok;
        scanf("%d", &ok);
        int subtract = Contain(x21, middle, x22, n, x11, y11, x12, y12);
        if (ok - subtract >= 1) {
            answer = middle;
            left = middle + 1;
        }
        else
            right = middle - 1;
    }
    y21 = answer;
    left = y21, right = n, answer;
    while (left <= right) {
        int middle = (left + right) / 2;
        printf("? %d %d %d %d\n", x21, y21, x22, middle);
        fflush(stdout);
        int ok;
        scanf("%d", &ok);
        int subtract = Contain(x21, y21, x22, middle, x11, y11, x12, y12);
        if (ok - subtract >= 1) {
            answer = middle;
            right = middle - 1;
        }
        else
            left = middle + 1;
    }
    y22 = answer;
    printf("! %d %d %d %d %d %d %d %d\n", x11, y11, x12, y12, x21, y21, x22, y22);
    fflush(stdout);
    return 0;
}