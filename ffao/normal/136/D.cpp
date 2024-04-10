#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;


struct point {
    int x, y;
    bool operator==(point b) {return x == b.x && y == b.y;}
};

point points[8];

int acnt = 0, bcnt = 0;
int a[4], b[4];

int ccm(point a, point b, point c)
{
    return (b.x - a.x) * (b.x - c.x) + (b.y - a.y) * (b.y - c.y) == 0;
}

int isrect(point a, point b, point c, point d)
{
    return
        ccm(a, b, c) &&
        ccm(b, c, d) &&
        ccm(c, d, a);
}

int is_rect(point a, point b, point c, point d)
{
    return isrect(a, b, c, d) ||
           isrect(b, c, a, d) ||
           isrect(c, a, b, d);
}


int dist(point a, point b) {
    int dx = a.x-b.x;
    int dy = a.y-b.y;
    return dx*dx+dy*dy;
}

int check() {
    set<int> x;
    for (int i = 0; i < 4; i++) {
        for (int j = i; j < 4; j++) {
            x.insert(dist(points[a[i]], points[a[j]]));
        }
    }
    
    if (x.size() != 3) return 0;
    
    if (!is_rect(points[b[0]],points[b[1]],points[b[2]],points[b[3]])) return 0;
    
    for (int i = 0; i < 4; i++) {
        for (int j = i+1; j < 4; j++) {
            if (points[a[i]] == points[a[j]]) return 0;
            if (points[b[i]] == points[b[j]]) return 0;
        }
    }
    
    printf("YES\n");
    for (int i = 0; i < 4; i++) {
        printf("%d", a[i]+1);
        if (i != 3) printf(" ");
        else printf("\n");
    }
    for (int i = 0; i < 4; i++) {
        printf("%d", b[i]+1);
        if (i != 3) printf(" ");
        else printf("\n");
    }
    
    return 1;
} 

int perm (int final) {
    if (final == 8) return check();
    if (acnt != 4) {
        a[acnt++] = final;
        if (perm(final+1)) return 1;
        acnt--;
    }
    
    if (bcnt != 4) {
        b[bcnt++] = final;
        if (perm(final+1)) return 1;
        bcnt--;
    }
    
    return 0;
}   

int main() {
    for (int i = 0; i < 8; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }
    if (!perm(0)) printf("NO\n");
}