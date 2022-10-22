#include<vector>
#include<set>
#include<map>
#include<queue>
#include<string>
#include<algorithm>
#include<iostream>
#include<bitset>
#include<functional>
#include<numeric>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<cmath>
#include<iomanip>
#include<random>
#include<ctime>
#include<complex>
using namespace std;
typedef long long LL;
typedef double D;
#define all(v) (v).begin(), (v).end()
mt19937 gene(233);
typedef complex<double> Complex;
#define fi first
#define se second
#define ins insert
#define pb push_back
inline char GET_CHAR(){
    const int maxn = 131072;
    static char buf[maxn],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,maxn,stdin),p1==p2)?EOF:*p1++;
}
inline int getInt() {
    int res(0);
    char c = getchar();
    while(c < '0') c = getchar();
    while(c >= '0') {
        res = res * 10 + (c - '0');
        c = getchar();
    }
    return res;
}

inline LL fastpo(LL x, LL n, LL mod) {
    LL res(1);
    while(n) {
        if(n & 1) {
            res = res * (LL)x % mod;
        }
        x = x * (LL) x % mod;
        n /= 2;
    }
    return res;
}
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }

inline string itoa(int x, int width = 0) {
    string res;
    if(x == 0) res.push_back('0');
    while(x) {
        res.push_back('0' + x % 10);
        x /= 10;
    }
    while((int)res.size() < width) res.push_back('0');
    reverse(res.begin(), res.end());
    return res;
}
const int _B = 131072;
char buf[_B];
int _bl = 0;
inline void flush() {
    fwrite(buf, 1, _bl, stdout);
    _bl = 0;
}
__inline void _putchar(char c) {
    if(_bl == _B) flush();
    buf[_bl++] = c;
}
inline void print(LL x, char c) {
    static char tmp[20];
    int l = 0;
    if(!x) tmp[l++] = '0';
    else {
        while(x) {
            tmp[l++] = x % 10 + '0';
            x /= 10;
        }
    }
    for(int i = l - 1; i >= 0; i--) _putchar(tmp[i]);
    _putchar(c);
}
struct P {
    D x, y;
};
const int N = 1111;
const int LOG = 20;
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int n, k;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int o[N];
char a[N][N];
bool vst[N], ins[N];
vector<int> vec;
vector<int> s;
void dfs(int v, char c) {
    vst[v] = true;
    //printf("v = %d\n", v);
    ins[v] = true;
    if(vec.empty()) s.push_back(v);
    for(int i = 1; i <= n; i++) {
        if(i == v) continue;
        if(a[v][i] != c) continue;
        if(vst[i] && vec.empty() && ins[i]) {
            while(s.back() != i) {
                vec.pb(s.back());
                s.pop_back();
                if(s.empty()) assert(false);
            }
            vec.pb(i);
            reverse(all(vec));
        }
        if(!vst[i]) {
            dfs(i, c);
        }
    }
    ins[v] = false;
    if(vec.empty()) s.pop_back();
}
void calc(char c) {
    fill(vst + 1, vst + 1 + n, false);
    fill(ins + 1, ins + 1 + n, false);
    
    for(int i = 1; i <= n; i++) {
        if(!vst[i]) dfs(i, c);
    }
}
int main() {
    int t;
    scanf("%d", &t);
    for(int qq = 1; qq <= t; qq++) {
        scanf("%d%d", &n, &k);
//n = 1000;
//k = 1000;
        for(int i = 1; i <= n; i++) scanf("%s", a[i] + 1);
//for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) a[i][j] = i == j ? '*' : rand() % 2 ? 'a' : 'b';
//printf("??\n");
        vec.clear();
        s.clear();
        calc('a');
//printf("??\n");
        //for(int i = 0; i < (int)vec.size(); i++) printf("?%d", vec[i]); printf("\n");
        calc('b');
//printf("??\n");
        //for(int i = 0; i < (int)vec.size(); i++) printf("?%d", vec[i]); printf("\n");
        if(vec.size() >= 2) {
            printf("YES\n");
            for(int i = 0; i <= k; i++) printf("%d%c", vec[i % (int)vec.size()], i == k ? '\n' : ' ');
        }else {
            if(k % 2 == 0 && n == 2) {
                printf("NO\n");
            }else {
                if(k % 2 == 1) {
                    printf("YES\n");
                    for(int i = 0; i <= k; i++) printf("%d%c", i % 2 + 1, i == k ? '\n' : ' ');
                }else {
                    for(int i = 1; i <= n; i++) o[i] = i;
                    sort(o + 1, o + 1 + n, [&](int x, int y) { return a[x][y] == 'a'; });
                    printf("YES\n");
                    for(int i = 0; i <= k; i++) printf("%d%c", abs(i - (k / 2)) % 2 == 0 ? o[2] : i <= k / 2 ? o[1] : o[3], i == k ? '\n' : ' ');
                }
                
            }
        }
    }
}