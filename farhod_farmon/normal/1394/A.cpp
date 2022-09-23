#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int mod = 1e9 + 7;

using namespace std;

int n;
int k, m, a[N];

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> k >> m;
        vector < long long > A, B;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                if(a[i] > m){
                        A.push_back(a[i]);
                } else{
                        B.push_back(a[i]);
                }
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        reverse(A.begin(), A.end());
        reverse(B.begin(), B.end());
        for(int i = 1; i < A.size(); i++) A[i] += A[i - 1];
        for(int i = 1; i < B.size(); i++) B[i] += B[i - 1];
        long long res = 0;

        for(int i = 0; i <= A.size(); i++){
                long long cur = 0;
                long long rem = n;
                rem -= i;
                if(i > 0){
                        cur += A[i - 1];
                        rem -= 1ll * k * (i - 1);
                }
                rem = min(rem, (long long)B.size());
                if(rem > 0){
                        cur += B[rem - 1];
                }
                if(rem >= 0){
                        res = max(res, cur);
                }
        }
        cout << res << "\n";
}