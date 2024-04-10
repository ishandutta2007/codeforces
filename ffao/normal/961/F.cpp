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


void re(int& x);


void pr(int x);


void pr(char x);


#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#include <sys/time.h>


int p[1100000];
int n;
char sss[1100000];

typedef long long H;
static const H M = INT_MAX;
static H C; 

#define sz(x) (int)(x).size()

struct K {
	H x; K(H x=0) : x(x) {}
	K operator+(K o) { H y = x + o.x; return y - (y >= M) * M; }
	K operator*(K o) { return x*o.x % M; }
	H operator-(K o) { H y = x - o.x; return y + (y < 0) * M; }
};

struct HashInterval {
	vector<K> ha, pw;
	HashInterval(string& str) : ha(sz(str)+1), pw(ha) {
		pw[0] = 1;
		rep(i,sz(str))
			ha[i+1] = ha[i] * C + str[i],
			pw[i+1] = pw[i] * C;
	}
	H hashInterval(int a, int b) { // hash [a, b)
		return ha[b] - ha[a] * pw[b - a];
	}
};

string s;

void solve()
{
    timeval tp;
	gettimeofday(&tp, 0);
	C = tp.tv_usec; 

    re(n);
    scanf("%s", sss);
    s = sss;

    HashInterval hash(s);
    memset(p,-1,sizeof(p));

    int b = (n-1)/2;
    if (n % 2 == 0 && s[b]==s[b+1]) p[0]=1;
    
    for (int i = 1; i <= b; i++) {
        for (int j = p[i-1]+2; j >= 1; j -= 2) {
            int ri = b+i+(n%2==0);
            if (hash.hashInterval(b-i,b-i+j) == hash.hashInterval(ri+1-j,ri+1)) {
                p[i] = j;
                break;
            }
        }
    }

    for (int i = b; i >= 0; i--) {
        if (p[i]) pr(p[i]);
        else pr(-1);
        pr(' ');
    }
}


int main() {


    solve();
}


void re(int& x) { scanf("%d", &x); }


void pr(int x) { printf("%d", x); }


void pr(char x) { printf("%c", x); }