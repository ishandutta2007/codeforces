#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 500500;
const int Q = 2 * N;

using namespace std;

bool good(vector<int> a)
{
        for(int i = 0; i < a.size() / 2; i++){
                if(a[i] != a[a.size() -i - 1]){
                        return false;
                }
        }
        return true;
}

int main()
{
        #ifdef zxc
                freopen("input.txt", "r", stdin);
                freopen("output.txt", "w", stdout);
        #endif
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
                vector<int> A, B;
                int i = 0, j = n - 1;
                while(i <= j && a[i] == a[j]){
                        i += 1;
                        j -= 1;
                }
                if(i > j){
                        cout << "YES" << "\n";
                        continue;
                }
                for(int x : a){
                        if(x != a[i]){
                                A.push_back(x);
                        }
                        if(x != a[j]){
                                B.push_back(x);
                        }
                }
                if(good(A) || good(B)){
                        cout << "YES" << "\n";
                } else {
                        cout << "NO" << "\n";
                }
        }
}