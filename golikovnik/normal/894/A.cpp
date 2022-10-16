#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<vi> vvi;
typedef vector<pi> vpi;

#define forn(i, n) for(int i = 0; i < n; i++)
#define for1(i, n) for(int i = 1; i <= n; i++)
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    string s;
    cin >> s;
    int n = s.length();
    int cnt = 0;
    forn(i, n) {
        for(int j = i+1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                if (s[i] == 'Q' && s[j] == 'A' && s[k] == 'Q')
                    cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}