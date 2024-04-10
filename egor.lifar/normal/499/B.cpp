    
#include <iostream>
#include <sstream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>


using namespace std;


int n, m;
string s[100000];
map<string, string> M;
string ans[100000];


int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        string a, b;
        cin >> a >> b;
        M[a] = b;
    }
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        if (s[i].size() <= M[s[i]].size()) {
            ans[i] = s[i];
        } else {
            ans[i] = M[s[i]];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
    return 0;
}