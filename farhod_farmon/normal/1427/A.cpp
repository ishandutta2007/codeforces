#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 1000100;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                vector < int > A, B, C;
                int n;
                cin >> n;
                int s = 0;
                for(int i = 1; i <= n; i++){
                        int x;
                        cin >> x;
                        s += x;
                        if(x > 0){
                                A.push_back(x);
                        } else if(x < 0){
                                B.push_back(x);
                        } else{
                                C.push_back(0);
                        }
                }
                if(s == 0){
                        cout << "NO" << "\n";
                        continue;
                }
                cout << "YES" << "\n";
                if(s < 0){
                        swap(A, B);
                }
                for(int x: A) cout << x << " ";
                for(int x: B) cout << x << " ";
                for(int x: C) cout << x << " ";

                cout << "\n";
        }
}