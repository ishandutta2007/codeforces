#include <bits/stdc++.h>

using namespace std;
#define MOD 1000000007

set<int> nsei, b, s;
int ans = 1, n, p;
char ss[20];

void fim() {
    puts("0");
    exit(0);
}

int main() {
    scanf("%d", &n);
    while(n--) {
        scanf("%s %d", ss, &p);
        if(ss[1] == 'C') {
            if(b.count(p)) {
                if(*(b.rbegin()) == p) {
                    for(int x : nsei) s.insert(x);
                    nsei.clear();
                    b.erase(p);
                } else fim();
            } else if(s.count(p)) {
                if(*(s.begin()) == p) {
                    for(int x : nsei) b.insert(x);
                    nsei.clear();
                    s.erase(p);
                } else fim();
            } else {
                ans *= 2; if(ans >= MOD) ans -= MOD;
                for(int x : nsei) {
                    if(x < p) b.insert(x);
                    if(x > p) s.insert(x);
                }
                nsei.clear();
            }
        } else if(ss[1] == 'D') {
            if(!b.empty() && p < *(b.rbegin()) ) b.insert(p);
            else if(!s.empty() && p > *(s.begin()) ) s.insert(p);
            else nsei.insert(p);
        } else assert(false);
    }

    printf("%d\n", (1LL * ans * (nsei.size()+1))%MOD);
    return 0;
}