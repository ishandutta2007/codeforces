#include <string>
#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 


using namespace std;


#include <tuple>


int n,m,k;

int bd[4100][4100];
int bd2[4100][4100];

int get1(int bd[4100][4100], int x, int y) {
    int s = 0;
    for (int tx = x; tx > 0; tx -= tx&-tx) {
        for (int ty = y; ty > 0; ty -= ty&-ty) s += bd[tx][ty];
    }
    return s;
}

int get(int bd[4100][4100], int x1, int x2, int y1, int y2) {
    return get1(bd, x2,y2) - get1(bd, x1-1,y2) - get1(bd, x2,y1-1) + get1(bd, x1-1,y1-1);
}

void upd(int bd[4100][4100], int x, int y) {
    for (int tx = x; tx <= n+m; tx += tx&-tx) {
        for (int ty = y; ty <= n+m; ty += ty&-ty) bd[tx][ty]++;
    }
}

int calc(int x1, int x2, int y1, int y2) {
    return get(bd2, x1, x2, y1, y2);
    //int area = (y2-y1+1) * (x2-x1+1);

    //int should_parity = !(m&1);
    //if ( (x1 % 2 == y1 % 2) ^ should_parity) {
    //    return (area+1)/2;
    //}
    //return area/2;
}

void solve()
{
    scanf("%d %d %d", &n, &m, &k);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            upd(bd2, i+j-1, i-j+m);
        }
    }

    for (int i = 0; i < k; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        int x = a+b, y = a-b;
        x -= 1; y += m;

        int st = 0, ed = n+m;
        while (st < ed) {
            int md = (st+ed)/2;
            
            int x1 = max(1,x - md);
            int x2 = min(n+m-1, x + md);
            int y1 = max(1,y - md);
            int y2 = min(n+m-1, y + md);

            int has = get(bd, x1,x2,y1,y2);
            int should = calc(x1,x2,y1,y2);
            if (has < should) ed = md;
            else st = md+1;
        }

        //printf("st=%d\n",st);
        pair<int, int> ans = {n+m+1, n+m+1};

        int x1 = max(1,x - st);
        int x2 = min(n+m, x + st);
        int y1 = max(1,y - st);
        int y2 = min(n+m-1, y + st);
        
        if (x - st >= 1 && get(bd, x1,x1,y1,y2) < calc(x1,x1,y1,y2)) {
            int st = y1, ed = y2;
            while (st < ed) {
                int md = (st+ed)/2;
                int has = get(bd, x1,x1,y1,md);
                int should = calc(x1,x1,y1,md);
                if (has < should) ed = md;
                else st = md+1;
            }
            //x = a+b-1, y = a-b+m
            //x+y = 2a+m
            //a = (x+y+m)/2
            //b = (x+y+m)/2
            int aa = (x1+st-m+1)/2;
            //printf("x=%d\n aa=%d st=%d\n", x, aa, st);
            ans = min(ans, {aa, x1-aa+1});
        }

        if (x + st <= n+m-1 && get(bd, x2,x2,y1,y2) < calc(x2,x2,y1,y2)) {
            int st = y1, ed = y2;
            while (st < ed) {
                int md = (st+ed)/2;
                int has = get(bd, x2,x2,y1,md);
                int should = calc(x2,x2,y1,md);
                if (has < should) ed = md;
                else st = md+1;
            }
            //x = a+b, y = a-b+m
            //x+y = 2a+m
            //a = (x+y+m)/2
            //b = (x+y+m)/2
            int aa = (x2+st-m+1)/2;
            ans = min(ans, {aa, x2-aa+1});
        }

        if (y - st >= 1 && get(bd, x1,x2,y1,y1) < calc(x1,x2,y1,y1)) {
            int st = x1, ed = x2;
            while (st < ed) {
                int md = (st+ed)/2;
                int has = get(bd, x1,md,y1,y1);
                int should = calc(x1,md,y1,y1);
                if (has < should) ed = md;
                else st = md+1;
            }
            //x = a+b, y = a-b+m
            //x+y = 2a+m
            //a = (x+y+m)/2
            //b = (x+y+m)/2
            int aa = (y1+st-m+1)/2;
            ans = min(ans, {aa, st-aa+1});
        }

        if (y + st <= n+m-1 && get(bd, x1,x2,y2,y2) < calc(x1,x2,y2,y2)) {
            int st = x1, ed = x2;
            while (st < ed) {
                int md = (st+ed)/2;
                int has = get(bd, x1,md,y2,y2);
                int should = calc(x1,md,y2,y2);
                if (has < should) ed = md;
                else st = md+1;
            }
            //x = a+b-1, y = a-b+m
            //x+y = 2a+m-1
            //a = (x+y-m+1)/2
            //b = (x+y+m)/2
            int aa = (y2+st-m+1)/2;
            ans = min(ans, {aa, st-aa+1});
        }

        printf("%d %d\n", ans.first, ans.second);
        upd(bd, ans.first+ans.second-1, ans.first-ans.second+m);
    }
}


int main() {


    solve();
}