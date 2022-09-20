#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                vector < int > a(n);
                long long A = 0, B = 0;
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                        if(i % 2){
                                A += a[i];
                        } else{
                                B += a[i];
                        }
                }
                int g = 0;
                if(A < B){
                        g = 1;
                }
                for(int i = 0; i < n; i++){
                        if(i % 2 == g){
                                a[i] = 1;
                        }
                        cout << a[i] << " ";
                }
                cout << "\n";
        }
}