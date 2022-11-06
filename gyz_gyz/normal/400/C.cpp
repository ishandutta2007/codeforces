#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int n, m;
int x, y;

void clockwise(int cnt)
{
    for (int i = 1; i <= cnt; i++)
    {
        int t = x;
        x = y;
        y = n-t+1;
        swap(n, m);
    }
}

void hor_rotate(){
    y = m - y + 1;
}

void counterclockwise(int cnt)
{
    for (int i = 1; i <= cnt; i++)
    {
        int t = x;
        x = m - y + 1;
        y = t;
        swap(n, m);
    }
}

int main(){
    int i, a, b, c, p;
    while (scanf("%d%d%d%d%d%d", &n, &m, &a, &b, &c, &p) != EOF){
        int tn, tm;
        tn = n;
        tm = m;
        for (i = 1; i <= p; i++){
            n = tn;
            m = tm;
            scanf("%d%d", &x, &y);
            if (a % 4)
                clockwise(a%4);
            if (b % 2)
               hor_rotate();
            if (c % 4)
                counterclockwise(c%4);
            printf("%d %d\n", x, y);
        }
    }
}