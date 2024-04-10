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
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        vector<pair<int, int>> A, B;
        for(int i = 0; i < n; i++){
            char c;
            cin >> c;
            if(c == '0'){
                A.push_back({a[i], i});
            } else{
                B.push_back({a[i], i});
            }
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        vector<int> res(n);
        for(int i = 0; i < A.size(); i++){
            res[A[i].se] = i + 1;
        }
        for(int i = 0; i < B.size(); i++){
            res[B[i].se] = i + A.size() + 1;
        }
        for(int x : res){
            cout << x << " ";
        }
        cout << "\n";
    }
}