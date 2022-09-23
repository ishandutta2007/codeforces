#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 8080;

using namespace std;

int n;
int a[N];
int b[N];

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                cin >> n;
                vector < int > A, B;
                for(int i = 1; i <= n; i++){
                        if(i % 2){
                                A.push_back(i);
                        } else{
                                B.push_back(i);
                        }
                }
                if(n < 4){
                        cout << -1 << "\n";
                        continue;
                }
                swap(B[0], B[1]);
                reverse(A.begin(), A.end());
                for(int x: A) cout << x << " ";
                for(int x: B) cout << x << " ";
                cout << "\n";
        }
}