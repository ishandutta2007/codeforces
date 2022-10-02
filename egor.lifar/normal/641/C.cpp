#include <iostream>
#include <sstream>
#include <cstdio>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>
#include <set>
#include <vector>


using namespace std;


int n, q;
int sdvig = 0;
int sdvig1[2];
int ans[1000001];
int who[1000001];


int main() {
    cin >> n >> q;
    int curpos = 0, curpos1 = 1;
    for (int i = 0; i < q; i++) {
        int t;
        scanf("%d", &t);
        if (t == 2) {
            if (curpos % 2 == 0) {
                curpos++;
            } else {
                curpos--;
            }
            if (curpos1 % 2 == 0) {
                curpos1++;
            } else {
                curpos1--;
            }
            curpos %= n;
            curpos1 %= n;
        } else {
            int a;
            scanf("%d", &a);
            curpos += a;
            curpos1 += a;
            curpos %= n;
            curpos1 %= n;
        }   
    }
    if (curpos < 0) {
        curpos += n;
    }
    if (curpos1 < 0) {
        curpos1 += n;
    }
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            int newpos = curpos + (i / 2) * 2;
            newpos %= n;
            if (newpos < 0) {
                newpos += n;
            }
            ans[i] = newpos;
        } else {
            int newpos = curpos1 + (i / 2) * 2;
            newpos %= n;
            if (newpos < 0) {
                newpos += n;
            }
            ans[i] = newpos;
        }
    }
    for (int i = 0; i < n; i++) {
        who[ans[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        printf("%d ", who[i] + 1);
    }
    printf("\n");
    return 0;
}