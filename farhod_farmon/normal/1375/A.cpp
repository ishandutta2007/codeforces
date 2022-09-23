#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int mod = 1e9 + 7;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                vector < int > a(n);
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                        if(i % 2){
                                a[i] = abs(a[i]);
                        } else{
                                a[i] = - abs(a[i]);
                        }
                }
                for(int x: a){
                        cout << x << " ";
                }
                cout << "\n";
        }
}