#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

int n;
char c[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        int s = 0, x = 0, y;
        for(int i = 1; i <= n; i++){
                cin >> c[i];
                if(c[i] == '('){
                        s += 1;
                } else if(c[i] == ')'){
                        s -= 1;
                } else{
                        x += 1;
                }
        }
        if(n % 2){
                cout << ":(" << "\n";
                return 0;
        }
        y = -1;
        for(int i = 0; i <= x; i++){
                if(i - (x - i) + s == 0){
                        y = x - i;
                        x = i;
                        break;
                }
        }
        if(y == -1){
                cout << ":(" << "\n";
                return 0;
        }
        s = 0;
        for(int i = 1; i <= n; i++){
                if(c[i] == '?'){
                        if(x){
                                c[i] = '(';
                                x--;
                        } else{
                                c[i] = ')';
                        }
                }
                s += (c[i] == '(' ? 1 : -1);
                if(s < 0 || i < n && s == 0){
                        cout << ":(" << "\n";
                        return 0;
                }
        }
        for(int i = 1; i <= n; i++){
                cout << c[i];
        }
}