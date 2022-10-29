#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <stack>
#include <cstring>
#include <math.h>
#include<cstdio>
#include<deque>
#include<sstream>
#define mp make_pair
#define eps 1e-6
using namespace std;
int dx[] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[] = { 1, -1, 0, 0, 1, -1, 1, -1 };
string s, a;
int b[100105];
int bb[100105];
void fun() {
    int m = s.length();
    int i = 0, j = -1;
    b[0] = -1;
    while (i < m) {
        while (j >= 0 && s[i] != s[j])
            j = b[j];
        i++, j++;
        b[i] = j;
    }
}
void fun2() {
    int n = a.length();
    int i = 0, j = -1;
    bb[0] = -1;
    while (i < n) {
        while (j >= 0 && a[i] != a[j])
            j = bb[j];
        i++, j++;
        bb[i] = j;
    }
}
int main() {
    //freopen("b.txt", "rt", stdin);
    cin >> s >> a;

    if (s.length() > a.length()) {
        string tmp = s;
        s = a;
        a = tmp;
    }
    fun();
    fun2();
    int len = s.length();
    bool ff = 1;
    int z = len - b[len], g = 1;
    if (len % z == 0)
        g = len / z;
    else
        ff = 0;

    len = a.length();
    bool fff = 1;
    int zz = len - bb[len], gg = 1;
    if (len % zz == 0)
        gg = len / zz;
    else
        fff = 0;

    if (a == s && !fff)
        puts("1");
    else if (!ff) {
        bool f = 1;
        for (int i = 0; i < s.length(); i++)
            if (s[i] != a[i])
                f = 0;
        if (f && fff)
            puts("1");
        else
            puts("0");
    } else if (z == zz && fff && ff) {
        bool f = 1;
        for (int i = 0; i < z; i++)
            if (s[i] != a[i])
                f = 0;

        if (!f)
            puts("0");
        else {

            int res = 0, n = __gcd(gg, g);
            for (int i = 1; i * i <= n; ++i) {
                if (n % i == 0) {
                    res++;
                    if (i * i != n)
                        res++;
                }
            }
            printf("%d\n", res);
        }

    } else
        puts("0");

    return 0;
}