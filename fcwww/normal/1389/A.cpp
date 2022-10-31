#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
void solve() {
    int l,r;
    scanf("%d%d",&l,&r);
    if(r>=2*l) {
        printf("%d %d\n",l,2*l); return ;
    }else {
        puts("-1 -1");
    }
}
int main() {
    int cas;
    scanf("%d",&cas);
    while(cas--) solve();
}