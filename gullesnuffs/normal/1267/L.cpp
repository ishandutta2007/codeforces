#include <bits/stdc++.h>
using namespace std;

#define rep(i,f,t) for (int i = (f); i < (t); i++)
#define all(x) (x).begin(), (x).end()
#define trav(a,x) for (auto& a : x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main() {
    cin.sync_with_stdio(false);
    int n, l, k;
    cin >> n >> l >> k;
    vector<string> words(n);
    string letters;
    cin >> letters;
    vector<int> important;
    rep(i,0,k)
        important.push_back(i);
    sort(all(letters));
    int ind = 0;
    rep(i,0,l) {
        for (int j : important) {
            words[j].push_back(letters[ind++]);
        }
        vector<int> newImportant;
        for (int j : important) {
            if (words[j].back() == words[k-1].back())
                newImportant.push_back(j);
        }
        important = newImportant;
    }
    rep(i,0,n)
        while (sz(words[i]) < l)
            words[i].push_back(letters[ind++]);
    rep(i,0,n)
        cout << words[i] << endl;
}