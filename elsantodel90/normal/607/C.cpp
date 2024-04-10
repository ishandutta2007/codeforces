#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <functional>
#include <stack>
#include <sstream>

#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define dforn(i,n) for(int i=(n)-1;i>=0; i--)
#define dforsn(i,s,n) for(int i=(n)-1;i>=(int)(s); i--)

#define esta(x,c) ((c).find(x) != (c).end())

using namespace std;

typedef long long tint;
typedef pair<int,int> pint;


const int MAXL = 2000000;

// kmp[i+1] da el maximo k en [0,i) tal que s[0,k) = s[i-k,i)
int kmp[MAXL];
void preMp(char *x, int L){
  int i=0, j = kmp[0] = -1;
  while(i<L){
    while(j>-1 && x[i] != x[j]) j = kmp[j];
      kmp[++i] = ++j;
  }
}


char s[2*MAXL];

char op[256];

const char *ans[2] = {"NO", "YES"};

int main() 
{
    #ifdef ACMTUYO
        if (!freopen("c.in" ,"r",stdin)) return 1;
    #endif
    int _sc = 0;
    int N;
    op['N'] = 'S';
    op['E'] = 'W';
    op['S'] = 'N';
    op['W'] = 'E';
    while (scanf("%d", &N) != EOF)
    {
        N--;
        _sc = scanf("%s",s);
        _sc = scanf("%s",s+N);
        reverse(s,s+N);
        forn(i,N)
            s[i] = op[(int)s[i]];
        preMp(s, 2*N);
        int L = kmp[2*N];
        while (L > N) L = kmp[L];
        printf("%s\n", ans[L==0]);
    }
    if (_sc) return 0;
    return 0;
}