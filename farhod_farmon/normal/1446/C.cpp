#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 5050;
const int mod = 1e9 + 7;

using namespace std;

int solve(vector < int > a, int lev)
{
        if(a.empty()){
                return 0;
        } else if(lev == -1){
                return min((int)a.size(), 1);
        }
        vector < int > A, B;
        for(int x: a){
                if(x & (1 << lev)){
                        A.push_back(x);
                } else{
                        B.push_back(x);
                }
        }
        int res =  max(solve(A, lev - 1) + (B.empty() ? 0 : 1), solve(B, lev - 1) + (A.empty() ? 0 : 1));
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int n;
        cin >> n;
        vector < int > a(n);
        for(int i = 0; i < n; i++){
                cin >> a[i];
        }
        cout << n - solve(a, 29) << "\n";
}