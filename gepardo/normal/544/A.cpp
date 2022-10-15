#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool used[256];

int main()
{
    int k; cin >> k;
    string s; cin >> s;
    int n = s.length();
    int lu = 0;
    vector <string> ans;
    for (int i = 0; i < n; i++)
        if (used[s[i]])
            *(ans.rbegin()) += s[i];
        else
            used[s[i]] = true, ans.push_back(s.substr(i, 1));
    if (ans.size() < k)
        cout << "NO" << endl;
    else
    {
        cout << "YES";
        for (int i = 0; i < ans.size(); i++)
        {
            if (i < k) cout << endl;
            cout << ans[i];
        }
    }
}