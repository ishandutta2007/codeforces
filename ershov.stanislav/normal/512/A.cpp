#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;

void print(vector<int> v) {
    cerr << "(";
    for (int i = 0; i < (int) v.size(); i++) {
        cerr << v[i];
        if (i != (int) v.size() - 1) {
            cerr << ", ";
        }
    }
    cerr << ")" << endl;
}

int n, g[26][26], srt[30], t = 26, used[26];
bool flag = true;
char s[111][111];

void dp(vector<int> v, int i) {
//    for (int i = 0; i < v.size(); i++) {
//        cout << v[i] << ' ';
//    }
//    cout << endl;
    if (v.size() <= 1) return;
    if (i>=100) return;
    for (int j = 0; j < v.size(); j++) {
        for (int k = j+1; k < v.size(); k++) {
            if (s[v[k]][i] == 0) {
                flag = false;
                continue;
            }
            g[s[v[j]][i] - 'a'][s[v[k]][i] - 'a'] = 1;
        }
    }
    vector<int> cur;
    for (int j = 0; j <= v.size(); j++) {
        if (j == v.size()) {
            dp(cur, i+1);
            continue;
        }
        if (j == 0 || s[v[j]][i]==s[v[j-1]][i]) {
            cur.pb(v[j]);
        } else {
            dp(cur, i+1);
            cur.clear();
            cur.pb(v[j]);
        }
    }
}

void topsort(int v) {
    if (srt[v] || used[v]) return;
    used[v] = 1;
    for (int i = 0; i < 26; i++) {
        if (i != v && g[v][i]) topsort(i);
    }
    srt[v] = t--;
}

char ans[26];

int main()
{
#ifdef DEBUG
freopen("in.txt", "r", stdin);
#endif

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    vector<int> v;
    for (int i = 0; i < n; i++) {
        v.pb(i);
    }
    dp(v, 0);
//    for (int i = 0; i < 26; i++) {
//        for (int j = 0; j < 26; j++) {
//            cout << g[i][j];
//        }
//        cout << endl;
//    }
    for (int i = 0; i < 26; i++) {
        topsort(i);
    }

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            if (g[i][j]) {
                if (srt[i] > srt[j]) {
                    flag = false;
                }
            }
        }
    }
    if (flag == false) {
        cout << "Impossible" << endl;
    } else {
        for (int i = 0; i < 26; i++) {
            ans[srt[i]-1] = i+'a';
        }
        for (int i = 0; i <26; i++) {
            cout << ans[i];
        }
    }
    return 0;
}