#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int m;
int k;
set < int > a[N], b[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m >> k;
        long long rem = 1ll * n * m - k - 1;
        for(int i = 1; i <= k; i++){
                int x, y;
                cin >> x >> y;

                a[x].insert(y);
                b[y].insert(x);
        }

        int A = 1, B = n, C = 1, D = m, tp = 0;
        int x = 1, y = 1;
        if(m == 1 || a[1].find(2) != a[1].end()){
                tp = 1;
        }
        while(A <= B && C <= D){
                int nx = x, ny = y;
                if(tp == 0){
                        auto p = a[x].lower_bound(y);
                        if(p != a[x].end()){
                                ny = *p - 1;
                        } else{
                                ny = m;
                        }
                } else if(tp == 1){
                        auto p = b[y].lower_bound(x);
                        if(p != b[y].end()){
                                nx = *p - 1;
                        } else{
                                nx = n;
                        }
                } else if(tp == 2){
                        auto p = a[x].lower_bound(y);
                        if(p != a[x].begin()){
                                p--;
                                ny = *p + 1;
                        } else{
                                ny = 1;
                        }
                } else{
                        auto p = b[y].lower_bound(x);
                        if(p != b[y].begin()){
                                p--;
                                nx = *p + 1;
                        } else{
                                nx = 1;
                        }
                }
                if(x == nx && y == ny){
                        break;
                }
                //cout << x << " " << y << " " << nx << " " << ny << endl;
                nx = min(nx, B);
                nx = max(nx, A);
                ny = min(ny, D);
                ny = max(ny, C);

                rem -= abs(x - nx) + abs(y - ny);

                x = nx;
                y = ny;

                if(tp == 0){
                        A += 1;
                        D = y;
                } else if(tp == 1){
                        D -= 1;
                        B = x;
                } else if(tp == 2){
                        B -= 1;
                        C = y;
                } else{
                        C += 1;
                        A = x;
                }

                tp = (tp + 1) % 4;
        }

        cout << (rem == 0 ? "Yes" : "No") << "\n";
}