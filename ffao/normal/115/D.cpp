#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <memory.h>


#include <cmath>


void re(char* c);


void pr(int x);


void pr(const char *x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


#include <array>


#include <cstring>


const int mod = 1000003;

int n;
char s[4000];
int pdN[2100][2100];

int parse(int pos, int nesting) {
    int opos = pos;
    if (nesting >= 2000) return 0;
    if (pos == n) return 0;

    int &ret = pdN[pos][nesting];
    if (ret == -1) {
        ret = parse(pos, nesting+1);
        if (s[pos] == '+' || s[pos] == '-') ret = (ret + parse(pos+1, nesting)) % mod;
        else if (s[pos] == '*' || s[pos] == '/') return (ret = 0);
        else {
            while (s[pos] >= '0' && s[pos] <= '9') pos++;
            if (pos == n && nesting == 0) ret = (ret + 1) % mod;
            if (nesting > 0 && pos != n) ret = (ret + parse(pos+1, nesting-1)) % mod;  
        }
    }

    //if (ret != 0) dbg(opos,nesting,ret);
    return ret;
}

void solve()
{
    memset(pdN,-1,sizeof(pdN));

    re(s);
    n = strlen(s);
    ps(parse(0, 0));
}


int main() {


    solve();
}


 // and triples


void re(char* c) { scanf("%s", c); }


void pr(int x) { printf("%d", x); }


void pr(const char *x) { printf("%s", x); }


void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}