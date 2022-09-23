#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1010;

using namespace std;

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int T;
        cin >> T;
        while(T--){
                vector < vector < char > > a(9, vector < char > (9));

                int n = 9;
                for(int i = 0; i < n; i++){
                        for(int j = 0; j < n; j++){
                                cin >> a[i][j];
                        }
                        int j = (i % 3) * 3 + i / 3;
                        if(a[i][j] == '1'){
                                a[i][j] = '2';
                        } else{
                                a[i][j] = '1';
                        }
                }
                for(int i = 0; i < n; i++){
                        for(int j = 0; j < n; j++){
                                cout << a[i][j];
                        }
                        cout << "\n";
                }
        }
}