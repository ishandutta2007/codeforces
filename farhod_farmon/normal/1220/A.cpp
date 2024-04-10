#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 15500;

using namespace std;


int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        int n;
        int a = 0, b = 0;
        cin >> n;
        for(int i = 1; i <= n; i++){
                char c;
                cin >> c;
                if(c == 'n'){
                        a += 1;
                } else if(c == 'z'){
                        b += 1;
                }
        }
        while(a--){
                cout << 1 << " ";
        }
        while(b--){
                cout << 0 << " ";
        }
}