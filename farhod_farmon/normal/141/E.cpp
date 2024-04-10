#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

int n;
int m;
int p[N];
int a[N];
int b[N];

int get(int x)
{
        return x == p[x] ? x : p[x] = get(p[x]);
}

bool make(int x, int y)
{
        x = get(x);
        y = get(y);
        if(x != y){
                p[x] = y;
                return true;
        }
        return false;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                p[i] = i;
        }
        vector < int > A, B;
        int cnt = 0;
        for(int i = 1; i <= m; i++){
                int x, y;
                char c;
                cin >> x >> y >> c;
                a[i] = x;
                b[i] = y;
                if(c == 'S'){
                        A.push_back(i);
                } else{
                        B.push_back(i);

                        cnt += make(x, y);
                }
        }

        vector < int > res;
        for(int i: A){
                if(make(a[i], b[i])){
                        res.push_back(i);
                        cnt += 1;
                }
        }
        if(cnt != n - 1 || n % 2 == 0 || res.size() > n / 2){
                cout << -1 << "\n";
                return 0;
        }
        for(int i = 1; i <= n; i++){
                p[i] = i;
        }
        for(int i: res){
                make(a[i], b[i]);
        }
        for(int i: A){
                if(res.size() < n / 2 && make(a[i], b[i])){
                        res.push_back(i);
                }
        }
        if(res.size() < n / 2){
                cout << -1 << "\n";
                return 0;
        }
        for(int i: B){
                if(make(a[i], b[i])){
                        res.push_back(i);
                }
        }
        cout << res.size() << "\n";
        for(int x: res){
                cout << x << " ";
        }
}