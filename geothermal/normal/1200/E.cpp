    //testing for a friend, not my code
    
    #include <bits/stdc++.h>
     
    using namespace std;
     
    typedef pair<int,int> pii;
    typedef long long ll;
     
    #define mp make_pair
    #define pb push_back
     
    const int MAXN = 1e6 + 10;
    const int MOD = 1e9 + 7;
     
    int n;
    vector<string> words;
    string ans = "";
     
    vector<int> precomp(string pat) {
        vector<int> ret(pat.length());
        ret[0] = 0;
        int len = 0; // length of prev longest prefix suffix
        for (int i = 1; i < pat.length(); ) {
            if (pat[i] == pat[len]) {
                len++;
                ret[i] = len;
                i++;
            } else if (len != 0) {
                len = ret[len - 1];
            } else {
                ret[i] = 0; i++;
            }
        }
        return ret;
    }
     
    int KMP(string* text, string pat) {
        vector<int> lps = precomp(pat);
        int i = max(0, (int)(text->length()-pat.length()));
        int j = 0;
        while (i < text->length() && j < pat.length()) {
            if ((*text)[i] == pat[j]) {
                i++; j++;
            } else if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
        return j;
    }
     
    int main() {
        ios_base::sync_with_stdio(0); cin.tie(0);
        cin >> n;
        for (int i = 0; i < n; i++) {
            string s; cin >> s;
            words.pb(s);
        }
        ans += words[0];
        for (int i = 1; i < n; i++) {
            int startIndex = KMP(&ans, words[i]);
            for (int j = startIndex; j < words[i].length(); j++) {
                ans.pb(words[i][j]);
            }
        }
        cout << ans;
        return 0;
    }