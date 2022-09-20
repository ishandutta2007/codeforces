#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;

using namespace std;

vector < int > make(vector < int > a, int bad)
{
        int n = a.size();
        vector < int > b(n, 0);
        for(int i = 0; i < n; i++){
                int l = (i - 1 + n) % n;
                int r = (i + 1) % n;
                if(i == bad - 1){
                        b[r] += a[i];
                } else{
                        b[l] += a[i] / 2;
                        b[r] += a[i] - a[i] / 2;
                }
        }
        return b;
}

bool off = false;
int n = 100000, k = 322, bad = 1;
vector < int > a(n, k);

int ask(int x)
{
        if(off){
                a = make(a, bad);
                return a[x - 1];
        }

        cout << "? " << x << endl;
        int res;
        cin >> res;
        return res;
}

int bigger(int x, int y)
{
        if(x == y){
                return x;
        }
        int cx = 0, cy = 0, X = ask(x), Y = ask(y);
        cx += (X >= Y);
        cy += (Y >= X);

        for(int i = 0; i < 6; i++){
                if(i % 2 == 0){
                        X = ask(x);
                } else{
                        Y = ask(y);
                }
                cx += (X >= Y);
                cy += (Y >= X);
        }
        if(cx >= cy){
                return x;
        }
        return y;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        if(!off){
                cin >> n >> k;
        }

        int res = 1;

        for(int it = 0; it < 1000; it++){
                int x = rng() % n;
                x = (x + n) % n + 1;
                if(ask(x) > k){
                        res = x;
                        break;
                }
        }

        //cout << res << " " << ask(res) << "\n";

        int g = 1;
        while(g * 4 <= n){
                g *= 2;
        }
        while(g > 0){
                int x = res - g;
                if(x <= 0){
                        x += n;
                }
                if(ask(x) > k){
                        res = x;
                }
                g /= 2;
        }

        res -= 1;
        if(res <= 0){
                res += n;
        }

        cout << "! " << res << "\n";

}