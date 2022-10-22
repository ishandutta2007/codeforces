#include <iostream>
#include <vector>
#include <set>
typedef long long ll;
using namespace std;

const int maxa = 512;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> x(maxa, maxa);
    x[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < maxa; j++) if (x[j] < a[i] && a[i] < x[j ^ a[i]])
        {
            x[j ^ a[i]] = a[i];
        }
    }
    vector<int> b;
    for (int i = 0; i < maxa; i++) if (x[i] < maxa) b.push_back(i);
    cout << b.size() << "\n";
    for (int i : b) cout << i << " ";
    cout << "\n";
    return 0;
}