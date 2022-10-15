#include <iostream>
#include <vector>

using namespace std;

bool solve(vector <int> v, vector <int> &ans)
{
    int n = v.size();
    vector < vector <int> > lst(n+1);
    ans.clear();
    for (int i = 0; i < n; i++) lst[v[i]].push_back(i + 1);
    int left = 0;
    for (int i = 0; i < n; i++)
    {
        while (left >= 0 && lst[left].empty()) left -= 3;
        if (left < 0 || lst[left].empty()) left += 3;
        if (left < 0 || left > n || lst[left].empty()) return false;
        ans.push_back(*lst[left].rbegin());
        lst[left].pop_back();
        left++;
    }
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    vector <int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vector <int> ans;
    if (solve(v, ans))
    {
        cout << "Possible\n";
        for (int i = 0; i < ans.size(); i++)
            cout << (i ? " " : "") << ans[i];
    }
    else
        cout << "Impossible";
    cout << endl;
    return 0;
}