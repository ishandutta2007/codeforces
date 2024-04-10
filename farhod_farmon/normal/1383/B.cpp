#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 150;

using namespace std;

int a[N][N];

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
                int S = 0;
                for(int i = 0; i < n; i++){
                        cin >> a[i];
                        S ^= a[i];
                }
                if(S == 0){
                        cout << "DRAW" << "\n";
                        continue;
                }
                int h = 30;
                while(!(S & (1 << h))) h--;
                int A = 0, B = 0;
                for(int i = 0; i < n; i++){
                        if(!(a[i] & (1 << h))){
                                B += 1;
                        } else{
                                A += 1;
                        }
                }
                //cout << A << " " << B << "\n";
                if((A / 2) % 2 == 0 || ((A / 2) % 2) == 1 && B % 2) cout << "WIN" << "\n";
                else cout << "LOSE" << "\n";
        }
}