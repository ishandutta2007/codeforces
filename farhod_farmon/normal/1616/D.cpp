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
        int n, x;
        cin >> n;
        vector<long long> a(n + 1, 0);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        cin >> x;
        for(int i = 1; i <= n; i++){
            a[i] -= x;
            a[i] += a[i - 1];
        }
        vector<long long> d(n + 1, 0);
        multiset<long long> A, B;
        d[1] = 1;
        A.insert(-1);
        B.insert(a[0]);
        long long res = 1;
        for(int i = 2, j = 1; i <= n; i++){
            while(!B.empty() && a[i] - *(--B.end()) < 0){
                A.erase(A.find((j == 1 ? 0 : d[j - 2]) - j));
                B.erase(B.find(a[j - 1]));
                j += 1;
            }
            d[i] = max(d[i - 1], d[i - 2] + 1);
            if(!A.empty()){
                d[i] = max(d[i], *(--A.end()) + i + 1);
            }
            A.insert(d[i - 2] - i);
            B.insert(a[i - 1]);
            res = max(res, d[i]);
        }
        cout << res << "\n";
    }
}