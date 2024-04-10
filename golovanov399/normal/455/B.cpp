#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <iomanip>

#define x first
#define y second
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define LL long long

using namespace std;

int main()
{

    vector<int> cc(256, -1);
    vector<vector<int> > a(1, cc);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++){
        string s;
        cin >> s;
        int p = 0;
        for (int j = 0; j < s.length(); j++){
            if (a[p][s[j]] > -1) p = a[p][s[j]]; else {
                a[p][s[j]] = a.size();
                a.pb(cc);
                p = a.size() - 1;
            }
        }
    }
    for (int i = a.size() - 1; i >= 0; i--){
        bool flag = false;
        for (int j = 0; j < 254; j++){
            if (a[i][j] > -1 && a[a[i][j]][255] == 0) flag = true;
        }
        if (flag) a[i][255] = 1; else a[i][255] = 0;
        flag = false;
        int ff = 0;
        for (int j = 0; j < 254; j++){
            if (a[i][j] > -1){
                ff++;
                if (a[a[i][j]][254] == 0) flag = true;
            }
        }
        if (ff == 0 || flag) a[i][254] = 1; else a[i][254] = 0;
    }
    if (k == 1){
        if (a[0][255]) cout << "First\n"; else cout << "Second\n";
    } else
    if (a[0][255] == 0) cout << "Second\n"; else
        if (a[0][254] == 1) cout << "First\n"; else
            if (k % 2 == 1) cout << "First\n"; else
                cout << "Second\n";

    return 0;
}