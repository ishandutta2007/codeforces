#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

int main(){

    int n;
    cin >> n;
    int t;
    cin >> t;
    vector<int> a(n);
    for (int i = 1; i <= n - 1; i++){
        cin >> a[i];
    }
    int i = 1;
    while (i < t)
        i += a[i];
    if (i == t){
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}