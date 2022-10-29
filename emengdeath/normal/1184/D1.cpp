#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <cmath>
#include <set>
using namespace std;
struct node{
    int last, next;
    bool is_doctor;
}f[10000];
int n, k, m, t, head, tail, all;
int main() {
    scanf("%d %d %d %d", &n, &k, &m, &t);
    for (int i = 1; i <= n ; i ++)
        f[i].last = i - 1, f[i].next = i + 1;
    f[k].is_doctor = 1;
    f[n].next = 0;
    head = 1;
    all = n;
    tail = n;
    while (t -- ){
        int x ,y ;
        scanf("%d %d", &x, &y);
        if (x == 0) {
            x = head;
            bool have_doctor = f[x].is_doctor;
            int sum = y;
            y --;
            while (y --)  x = f[x].next, have_doctor |= f[x].is_doctor;
            if (have_doctor) {
                all = sum;
                f[x].next=  0;
                tail = x;
            } else {
                all -= sum;
                f[f[x].next].last = 0;
                head = f[x].next;
            }
        } else {
            if (all < y) {
                f[tail].next = ++n;
                f[n].last = tail;
                tail = n;
            } else
            if (y == 1){
                f[head].last = ++n;
                f[n].next = head;
                head = n;
            } else{
                x = head;
                y --;
                while (y --)  x = f[x].next;
                f[++n].next = x;
                f[n].last = f[x].last;
                f[f[x].last].next = n;
                f[x].last = n;
            }
            all ++;
        }
        x = head;
        y = 1;
        while (!f[x].is_doctor) x = f[x].next, y ++;
        printf("%d %d\n", all, y);
    }
    return 0;
}