#include <iostream>
#include <vector>

using namespace std;

int n;

int main()
{
    cin >> n;
    vector <int> ans;
    for (int i = 2; i <= n; i++)
    {
        bool p = true;
        int k = i;
        for (int j = 2; j * j <= k; j++)
            if (k % j == 0)
            {
                while (k % j == 0) k /= j;
                if (k != 1) p = false;
                break;
            }
        if (p) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
}