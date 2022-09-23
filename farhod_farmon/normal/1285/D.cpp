#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n;

int solve(int lev, vector < int > v)
{
        if(lev == -1){
                return 0;
        }
        vector < int > A, B;
        for(int x: v){
                if(x & (1 << lev)){
                        A.push_back(x);
                } else{
                        B.push_back(x);
                }
        }
        if(A.empty()){
                return solve(lev - 1, B);
        } else if(B.empty()){
                return solve(lev - 1, A);
        } else{
                return min(solve(lev - 1, A), solve(lev - 1, B)) + (1 << lev);
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n;
        vector < int > A(n);
        for(int i = 0; i < n; i++){
                cin >> A[i];
        }
        cout << solve(29, A) << "\n";
}