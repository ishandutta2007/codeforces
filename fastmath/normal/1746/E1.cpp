#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <fstream>
#include <array>
#include <functional>
#include <stack>
#include <memory>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcountll
#define ll long long
#define mp make_pair
#define x first
#define y second
#define Time (double)clock()/CLOCKS_PER_SEC

#ifdef LOCAL
#define debug(x) std::cerr << #x << ": " << x << '\n';
#define debug2(x, y) std::cerr << #x << ", " << #y << ": " << x << ", " << y << '\n';
#define debug3(x, y, z) std::cerr << #x << ", " << #y << ", " << #z << ": " << x << ", " << y << ", " << z << '\n';
#else
#define debug(x)
#define debug2(x, y) 
#define debug3(x, y, z) 
#endif

#define FORI(i,a,b) for (int i = (a); i < (b); ++i)
#define FOR(i,a) FORI(i,0,a)
#define ROFI(i,a,b) for (int i = (b)-1; i >= (a); --i)
#define ROF(i,a) ROFI(i,0,a)
#define rep(a) FOR(_,a)
#define each(a,x) for (auto& a: x)
#define FORN(i, n) FORI(i, 1, n + 1)

using vi = vector<int>;
template <typename T>
std::istream& operator >>(std::istream& input, std::pair <T, T> & data)
{
    input >> data.x >> data.y;
    return input;
}
template <typename T>
std::istream& operator >>(std::istream& input, std::vector<T>& data)
{
    for (T& x : data)
        input >> x;
    return input;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const pair <T, T> & data)
{
    output << "(" << data.x << "," << data.y << ")";
    return output;
}
template <typename T>
std::ostream& operator <<(std::ostream& output, const std::vector<T>& data)
{
    for (const T& x : data)
        output << x << " ";
    return output;
}
std::ostream& operator <<(std::ostream& output, const __int128 &x)
{
    __int128 n = x;
    if (n == 0) {
        output << "0";
        return output;
    }
    if (n < 0) {
        n = -n;
        output << "-";
    }
    string s;
    while (n) {
        s += '0' + (n%10);
        n /= 10;
    }
    reverse(all(s));
    cout << s;
    return output;
}
ll div_up(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll div_down(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down 
ll math_mod(ll a, ll b) { return a - b * div_down(a, b); }
#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>; 
tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; 
} // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; 
}
ll gcd(ll a, ll b) {
    while (b) {
        tie(a, b) = mp(b, a % b);
    }
    return a;
}
int Bit(int mask, int bit) { return (mask >> bit) & 1; }

#ifdef LOCAL
mt19937 rnd(2007);
#else
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
#endif
int get(int l, int r) {
    int len = r - l + 1;
    return l + (ll)(rnd()%len);
}

signed main() {
  int n;
    cin >> n;

    vi a;
    FORN (i, n) {
      a.app(i);
    }

    int ask = 0;
    while (a.size() > 3) {
      int h = div_down(a.size(),4);
      ask += 2;

      vi b[2][2];
      FOR (i, a.size()) {
        int c = i/h;
        ckmin(c, 3ll);
        debug(c);
        b[c/2][c%2].app(a[i]);
      }

      FOR (t, 2) {
        if (get(0, 1)) {
          swap(b[t][0], b[t][1]);
        }
      }

      cout << "? " << b[1][0].size() + b[1][1].size() << ' ' << b[1][0] << b[1][1] << endl;
      string ans1;
      cin >> ans1;

      int a1 = ans1 == "YES";

      cout << "? " << b[0][1].size() + b[1][1].size() << ' ' << b[0][1] << b[1][1] << endl;
      string ans2;
      cin >> ans2;

      int a2 = ans2 == "YES";

      debug2(a1, a2);

      int was = a.size();
      a.clear();
      FOR (x, 2) {
        FOR (y, 2) {
          if (x == a1 || y == a2) {
            each (e, b[x][y]) {
              a.app(e);
            }
          }
        }
      }

      debug(a);
    } 

    string s;
    if (a.size() == 1) {
      cout << "! " << a[0] << endl;
      cin >> s;
      assert(s==":)");
    }
    else if (a.size() == 2) {
      cout << "! " << a[0] << endl;
      cin >> s;
      if (s!=":)") {
              cout << "! " << a[1] << endl;
              cin >> s;
              assert(s==":)");

      }
    }
    else {

      cout << "? " << 1 << ' ' << a[0] << endl;
      string t;
      cin >> t;
      if (t == "YES") {
        cout << "! " << a[0] << endl;
        cin >> s;
        if (s!=":)") {
          cout << "? " << 1 << ' ' << a[1] << endl;
          string ans;
          cin >> ans;
          if (ans == "YES") {
            cout << "! " << a[1] << endl;
          }
          else {
            cout << "! " << a[2] << endl;
          }
                cin >> s;
                assert(s==":)");

        }        
      }
      else {
        cout << "? " << 1 << ' ' << a[0] << endl;
        cin >> t;
        if (t == "YES") {
          cout << "! " << a[0] << endl;
          cin >> s;
          if (s!=":)") {
            cout << "? " << 1 << ' ' << a[1] << endl;
            string ans;
            cin >> ans;
            if (ans == "YES") {
              cout << "! " << a[1] << endl;
            }
            else {
              cout << "! " << a[2] << endl;
            }
                  cin >> s;
                  assert(s==":)");

          }        
        }
        else {

          a.erase(a.begin());
      cout << "! " << a[0] << endl;
      cin >> s;
      if (s!=":)") {
              cout << "! " << a[1] << endl;
              cin >> s;
              assert(s==":)");

      }

        }
      }
    }
}