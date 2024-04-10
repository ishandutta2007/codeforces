#include <bits/stdc++.h>

#define fi first
#define se second
#define ll long long

const int N = 200200;

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
                if(n == 1){
                        cout << "FastestFinger" << "\n";
                } else if(n == 2){
                        cout << "Ashishgup" << "\n";
                } else if(n % 2){
                        cout << "Ashishgup" << "\n";
                } else{
                        int x = n, cnt = 0, A = 0;
                        while(x % 2 == 0){
                                x /= 2;
                                A += 1;
                        }
                        for(int i = 2; 1ll * i * i <= 1ll * x; i++){
                                if(x % i == 0){
                                        while(x % i == 0){
                                                x /= i;
                                                cnt += 1;
                                        }
                                }
                        }
                        if(x > 1){
                                cnt += 1;
                        }
                        if(cnt == 0 || (cnt == 1 && A == 1)){
                                cout << "FastestFinger" << "\n";
                        } else{
                                cout << "Ashishgup" << "\n";
                        }
                }
        }
}