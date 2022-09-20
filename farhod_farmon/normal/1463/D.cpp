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
                vector < int > a(2 * n, 0), b(2 * n, 0);
                for(int i = 0; i < n; i++){
                        int x;
                        cin >> x;
                        a[x - 1] = 1;
                }
                int l = 0, r = n;
                while(l < r){
                        int m = (l + r) / 2 + 1;
                        int cnt = 0, x = m, y = m;
                        for(int i = 0; i < 2 * n; i++){
                                if(a[i] && y){
                                        b[i] = 1;
                                        y -= 1;
                                } else{
                                        b[i] = 0;
                                }
                        }
                        for(int i = 2 * n - 1; i >= 0; i--){
                                if(!a[i] && x){
                                        x -= 1;
                                        cnt += 1;
                                } else{
                                        cnt -= b[i];
                                }
                                if(cnt < 0){
                                        break;
                                }
                        }
                        if(cnt < 0){
                                r = m - 1;
                        } else{
                                l = m;
                        }
                }
                int A = l;
                l = 0, r = n;
                while(l < r){
                        int m = (l + r) / 2 + 1;
                        int cnt = 0, x = m, y = m;
                        for(int i = 2 * n - 1; i >= 0; i--){
                                if(a[i] && y){
                                        b[i] = 1;
                                        y -= 1;
                                } else{
                                        b[i] = 0;
                                }
                        }
                        for(int i = 0; i < 2 * n; i++){
                                if(!a[i] && x){
                                        x -= 1;
                                        cnt += 1;
                                }
                                cnt -= b[i];
                                if(cnt < 0){
                                        break;
                                }
                        }
                        if(cnt < 0){
                                r = m - 1;
                        } else{
                                l = m;
                        }
                }
                int B = l;

                int res = 0;
                for(int i = 0; i <= A; i++){
                        if(n - i <= B){
                                res += 1;
                        }
                }
                cout << res << "\n";
        }
}