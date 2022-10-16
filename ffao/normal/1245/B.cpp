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


void re(int& x);


void pr(const char *x);
void pr(std::string x);


void ps();
template<class T, class... Ts> void ps(const T& t, const Ts&... ts);


#define REP(i,n) for(int (i)=0;(i)<(int)(n);(i)++)


int t,n;
int can_play[3];
int sn[110000];
int bob_play[3];

char s[110000];
string name = "RPS";

void solve()
{
    for (re(t); t; t--) {
        re(n);
        REP(i,3) {
            bob_play[i] = 0;
            re(can_play[i]);
        }

        scanf("%s", s);
        int l = n;

        REP(i,l) {
            if (s[i]=='R') sn[i] = 0;
            else if (s[i]=='P') sn[i] = 1;
            else sn[i] = 2;
            bob_play[sn[i]]++;
        }

        string ans;
        int cnt = 0;
        REP(i,l) {
            int beats = (sn[i]+1)%3;
            int loses = (sn[i]+2)%3;
            int draws = sn[i];

            if (can_play[beats]) {
                can_play[beats]--;
                ans += name[beats];
                cnt++;
            }
            else if (can_play[draws] && !(can_play[loses] && bob_play[beats] < can_play[loses])) {
                can_play[draws]--;
                ans += name[draws];
            }
            else {
                can_play[loses]--;
                ans += name[loses];
            }

            bob_play[draws]--;
        }
        
        if (cnt >= (n+1)/2) {
            ps("YES");
            ps(ans);
        }
        else ps("NO");
    }    
}


int main() {


    solve();
}


void re(int& x) { scanf("%d", &x); }


void pr(const char *x) { printf("%s", x); }
void pr(std::string x) { printf("%s", x.c_str()); }


void ps() { pr("\n"); }
template<class T, class... Ts> void ps(const T& t, const Ts&... ts) { 
    pr(t); if (sizeof...(ts)) pr(" "); ps(ts...); 
}