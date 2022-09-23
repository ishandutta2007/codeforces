#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int mod = 1e9 + 7;

using namespace std;

int n;
int a[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n;
        int res = -1;
        vector < int > b(31, 0);
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                for(int j = 0; j < 31; j++){
                        if(a[i] & (1 << j)){
                                if(b[j] == 0){
                                        b[j] = i;
                                } else{
                                        b[j] = -1;
                                }
                        }
                }
        }
        for(int i = 30; i >= 0; i--){
                if(b[i] > 0){
                        res = b[i];
                        break;
                }
        }
        if(res != -1){
                cout << a[res] << " ";
        }
        for(int i = 1; i <= n; i++){
                if(i != res){
                        cout << a[i] << " ";
                }
        }
}