#include <iostream>
#include <vector>
#define int long long

using namespace std;

main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n; cin >> n;
    vector <int> v(n+1);
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int i = 0; i < n; i++) cout << v[i] + v[i+1] << " ";
    cout << endl;
}