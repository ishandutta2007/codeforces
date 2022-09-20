#include "bits/stdc++.h"

#define fi first
#define se second

const int N = 100100;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        vector<int> v = {a, b, c};
        sort(v.begin(), v.end());
        int res = (v[0] + v[1] == v[2]);
        do{
            if(v[0] % 2 == 0 && v[1] == v[2]){
                res = 1;
            }
        }while(next_permutation(v.begin(), v.end()));
        cout << (res ? "YES" : "NO") << "\n";
    }
}