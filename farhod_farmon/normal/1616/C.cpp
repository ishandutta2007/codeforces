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
        int n;
        cin >> n;
        int res = max(0, n - 2);
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int cnt = 0;
                for(int h = 0; h < n; h++){
                    if((a[i] - a[j]) * (i - h) != (a[i] - a[h]) * (i - j)){
                        cnt += 1;
                    }
                }
                res = min(res, cnt);
            }
        }
        cout << res << "\n";
    }
}