#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ii pair <int, int>
#define app push_back
#define all(a) a.begin(), a.end()
#define bp __builtin_popcount
#define ll long long
#define mp make_pair
#define f first
#define s second
#define Time (double)clock()/CLOCKS_PER_SEC

vector <int> get(string s) {
    int n = s.size() + 1;
    int ptr = n;
    vector <int> ans;
    ans.app(n);
    ptr = n - 1;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '>') {
            ans.app(ptr);
            --ptr;    
        }
        else {
            int j;
            for (j = i; j < n && s[j] == '<'; ++j);
            int r = j - 1;
            int len = r - i + 2;
            
            ans.pop_back();
            ++ptr;
            for (int j = ptr - len + 1; j <= ptr; ++j)
                ans.app(j);
            ptr -= len;

            i = r;
        }   
    }   
    return ans;
}   

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    {
    vector <int> ans = get(s);
    for (int e : ans)
        cout << e << ' ';
    cout << '\n';
    }

    {
    string t;
    for (char c : s)
        if (c == '<')
            t += '>';
        else
            t += '<';
    vector <int> ans = get(t);
    for (int e : ans)
        cout << n - e + 1 << ' ';
    cout << '\n';
    }
}   
signed main() {
    #ifdef HOME
    freopen("input.txt", "r", stdin);
    #else
    #define endl '\n'
    ios_base::sync_with_stdio(0); cin.tie(0);
    #endif
    int t;
    cin >> t;
    while (t--) 
        solve();
}