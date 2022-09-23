#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                        if((i + j) % 2){
                                cout << "W";
                        } else{
                                cout << "B";
                        }
                }
                cout << "\n";
        }
}