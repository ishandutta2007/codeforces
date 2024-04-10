#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <limits>
#include <memory>
#include <queue>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define all(a) (a).begin(), (a).end()
#define sz(a) static_cast<int>((a).size())
#define fillchar(a, x) memset(a, x, sizeof(a))
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define replr(i, a, b) rep(i, a, (b)-1)
#define reprl(i, a, b) irep(i, (b)-1, a)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
typedef vector<string> VS;
const int kitten=0;

int main() {
    int n, m, t; scanf("%d%d%d", &n,&m,&t);
    VS s(n); int ans=0;
    repn(i, n) cin>>s[i];
    repn(j, m) {
        int c=0; repn(i, n) if(s[i][j]=='Y') ++c;
        if(c>=t) ++ans;
    }
    printf("%d\n", ans);

    return 0;
}