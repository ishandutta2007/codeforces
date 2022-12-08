#include <cassert>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

#define all(a) a.begin(), a.end()
#define rep(i, a, b) for(int i=int(a); i<=int(b); ++i)
#define irep(i, a, b) for(int i=int(a); i>=int(b); --i)
#define repn(i, n) rep(i, 0, (n)-1)
#define irepn(i, n) irep(i, (n)-1, 0)
#define fillchar(a, x) memset(a, x, sizeof(a))
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#ifdef DEBUG
    #define _debug(args...) { fprintf(stderr, args); fflush(stderr); }
#else
    #define _debug(args...) {}
#endif
typedef long long LL;
typedef pair<LL,LL> PLL;
typedef pair<int,int> PII;
typedef pair<double,double> PDD;
typedef vector<LL> VL;
typedef vector<int> VI;
typedef vector<PII> VPI;
typedef vector<string> VS;
template<class T> bool setmax(T &_a, T _b) { if(_b>_a) { _a=_b; return true; } return false; }
template<class T> bool setmin(T &_a, T _b) { if(_b<_a) { _a=_b; return true; } return false; }
template<class T> T gcd(T _a, T _b) { return _b==0?_a:gcd(_b,_a%_b); }

int cnt[26];
int num;

int main() {
    scanf("%d", &num);
    repn(i, num) scanf("%d", &cnt[i]);
    int sum=0; repn(i, num) sum+=cnt[i];

    int g=cnt[0]; repn(i, num) g=gcd(g, cnt[i]);
    repn(i, num) cnt[i]/=g;

    string ans;
    if(g%2==1) {
        int x=0; repn(i, num) x+=cnt[i]%2;
        if(x>1) {
            repn(i, num) repn(j, cnt[i]*g) ans+=char('a'+i);
            g=0;
        }
    }

    if(g>0) {
        string t; 
        repn(i, num) if(cnt[i]%2==0) repn(j, cnt[i]/2) t+=char('a'+i);
        repn(i, num) if(cnt[i]%2==1) repn(j, cnt[i]) t+=char('a'+i);
        irepn(i, num) if(cnt[i]%2==0) repn(j, cnt[i]/2) t+=char('a'+i);
        repn(i, g) { ans+=t; reverse(all(t)); }
    }
    printf("%d\n%s\n",g,ans.c_str());

    /*
    if(num==1) {
        printf("%d\n", cnt[0]);
        repn(i, cnt[0]) printf("a"); printf("\n");
    } else if(s%2==1) {
        int k=0;
        repn(i, num) k+=cnt[i]%2;
        assert(k>0);
        if(k==1) {
            printf("%d\n", 1);
            repn(i, num) if(cnt[i]%2==0) repn(j, cnt[i]/2) printf("%c", char('a'+i));
            repn(i, num) if(cnt[i]%2==1) repn(j, cnt[i]) printf("%c", char('a'+i));
            irepn(i, num) if(cnt[i]%2==0) repn(j, cnt[i]/2) printf("%c", char('a'+i));
        } else {
            printf("0\n");
            repn(i, num) repn(j, cnt[i]) printf("%c", char('a'+i));
            printf("\n");
        }
    } else {
        int k=0; repn(i, num) k+=cnt[i]%2;
        if(k>0) {
            printf("0\n");
            repn(i, num) repn(j, cnt[i]) printf("%c", char('a'+i));
            printf("\n");
        } else {
            int g=cnt[0]/2;
            repn(i, num) g=gcd(g, cnt[i]/2);
            printf("%d\n", g);
            string str;
            repn(i, num) repn(j, cnt[i]/2/g) str+=char('a'+i);
            irepn(i, num) repn(j, cnt[i]/2/g) str+=char('a'+i);
            string ans;
            repn(i, g) ans+=str;
            printf("%s\n", ans.c_str());
        }
    }
    */

    return 0;
}