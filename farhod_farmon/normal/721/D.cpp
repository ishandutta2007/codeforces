#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define mp make_pair
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const int N = 200200;

using namespace std;

long long n, k, x;
long long b[N];
pair < long long, long long > p[N];

int main()
{
    //fin("input.txt");
    //fout("output.txt");
    ios_base::sync_with_stdio(0);
    cin >> n >> k >> x;
    int cnt = 0;
    long long mn = 1e9 + 1, mx = -1e9 - 1;
    for(int i = 1; i <= n; i++){
        long long c;
        cin >> c;
        p[i] = {c, i};
        if(c < 0)
            cnt++;
    }
    for(int i = 1; i <= n; i++){
        if(p[i].fi == 0 && k){
            if(cnt % 2 == 0){
                p[i].fi -= x;
                cnt++;
                k--;
            }
            else{
                p[i].fi += x;
                k--;
            }
        }
        if(p[i].fi > 0)
            mn = min(mn, p[i].fi);
        else
            mx = max(mx, p[i].fi);
    }
    long long za = 1e18 + 1;
    if(cnt % 2 == 0){
        if(mn != 1e9 + 1 && mx != -1e9 - 1){
            if(abs(mn) < abs(mx))
                za = mn;
            else
                za = mx;
        }
        else if(mn != 1e9 + 1)
            za = mn;
        else
            za = mx;
    }
    for(int i = 1; i <= n; i++){
        if(p[i].fi == za){
            if(za < 0){
                while(k && p[i].fi <= 0){
                    k--;
                    p[i].fi += x;
                }
            }
            else{
                while(k && p[i].fi >= 0){
                    k--;
                    p[i].fi -= x;
                }
            }
            break;
        }
    }
    if(k){
        set < pair < long long, long long > > s;
        for(int i = 1; i <= n; i++)
            s.insert({abs(p[i].fi), i});
        while(k){
            pair < long long, long long > c = *s.begin();
            s.erase(s.begin());
            k--;
            if(p[c.se].fi < 0)
                p[c.se].fi -= x;
            else
                p[c.se].fi += x;
            s.insert({abs(p[c.se].fi), c.se});
        }
    }
    for(int i = 1; i <= n; i++)
        cout << p[i].fi << " ";
}