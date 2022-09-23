#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const int mod = 1e9 + 7;

using namespace std;


int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n;
        cin >> n;
        if(n % 2 == 0){
                cout << "NO" << "\n";
        } else{
                cout << "YES" << "\n";
                for(int i = 1; i <= n + n; i++){
                        int j = i;
                        if(i <= n){
                                if(i % 2){
                                        cout << i * 2 - 1 << " ";
                                } else{
                                        cout << i * 2 << " ";
                                }
                        } else{
                                j -= n;
                                if(j % 2){
                                        cout << j * 2 << " ";
                                } else{
                                        cout << j * 2 - 1 << " ";
                                }
                        }
                }
        }
}