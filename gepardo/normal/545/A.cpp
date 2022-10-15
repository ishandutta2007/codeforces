#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; cin >> n;
    vector <int> ans;
    for (int i = 0; i < n; i++)
    {
        bool crash = false;
        for (int j = 0; j < n; j++)
        {
            int a; cin >> a;
            if (a == 1 || a == 3) crash = true;
        }
        if (!crash) ans.push_back(i + 1);
    }
    cout << ans.size() << endl;
    for (auto it: ans) cout << it << " ";
}