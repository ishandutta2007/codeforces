#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9 + 100;
const ll lINF = 4e18;
const double EPS = 1e-12;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

vector<string> names = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven"
, "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
vector<string> names2 = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

int main()
{
#ifdef DEBUG
//    freopen ("in.txt", "r", stdin);
#endif
    int n;
    cin >> n;
    if (n < 20) {
        cout << names[n];
    } else if (n % 10) {
        cout << names2[n / 10 - 2] << '-' << names[n % 10];
    } else cout << names2[n / 10 - 2];
    return 0;
}