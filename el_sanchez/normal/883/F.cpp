//#pragma GCC optimize("O3")
//#pragma GCC target("sse4.1")
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define ford(i, n) for (int i = ((int)(n) - 1); i >= 0; --i)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<char> vc;
typedef vector<vc> vvc;
typedef pair<int, int> pii;
typedef vector<pii> vii;
#define sz(c) (int)(c).size()
#define all(c) (c).begin(), (c).end()

void solve (int n)
{
    set<string> forms;

    forn (i, n)
    {
        string s;
        cin >> s;
        {
            string ns;
            for (char ch : s)
            {
                if (ch == 'u')
                    ns += "oo";
                else
                    ns += ch;
            }
            s = ns;
        }

        {
            string ns;
            for (int i = 0; i < sz(s); )
            {
                if (s[i] != 'k')
                {
                    ns += s[i++];
                    continue;
                }

                int j = i;
                while (j < sz(s) && s[j] == s[i])
                    j++;

                if (j != sz(s) && s[j] == 'h')
                {
                    ns += "h";
                    i = j + 1;
                }
                else
                {
                    ns += string(j - i, 'k');
                    i = j;
                }
            }

            s = ns;
        }

        //cerr << s << endl;
        forms.insert(s);
    }

    cout << sz(forms) << endl;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n)
        solve(n);
}