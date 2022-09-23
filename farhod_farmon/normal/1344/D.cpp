#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;

using namespace std;

long long F(long long b, long long a)
{
        return b * (a - b * b);
}

int n;
long long k;
long long a[N];
long long b[N];
long long inf = (long long)4e18;

long long sq(long long x)
{
        long long l = 1, r = 2e9;
        while(l < r){
                long long m = (l + r) / 2 + 1;
                if(m * m < x){
                        l = m;
                } else{
                        r = m - 1;
                }
        }
        return l;
}

long long d1(long long b, long long a)
{
        return 3 * b * b - 3 * b - a + 1;
}

long long d2(long long b, long long a)
{
        return -d1(b, a);
}

long long get1(long long M, bool shit)
{
        long long cnt = 0;
        for(int i = 1; i <= n; i++){
                long long l = b[i], r = a[i];
                while(l < r){
                        long long m = (l + r) / 2;
                        if(d1(m + 1, a[i]) <= M){
                                l = m + 1;
                        } else{
                                r = m;
                        }
                }
                cnt += l - b[i];
                if(shit){
                        b[i] = l;
                }
        }
        return cnt;
}

long long get2(long long M, bool shit)
{
        long long cnt = 0;
        for(int i = 1; i <= n; i++){
                long long l = 0, r = b[i];
                while(l < r){
                        long long m = (l + r) / 2;
                        if(d2(m, a[i]) <= M){
                                r = m;
                        } else{
                                l = m + 1;
                        }
                }
                cnt += b[i] - l;
                if(shit){
                        b[i] = l;
                }
        }
        return cnt;
}

void make1()
{
        long long l = 0, r = inf;
        while(l < r){
                long long m = (l + r) / 2;
                if(get1(m + 1, 0) < k){
                        l = m + 1;
                } else{
                        r = m;
                }
        }
        k -= get1(l, 1);
        set < pair < long long, int > > s;
        for(int i = 1; i <= n; i++){
                if(b[i] < a[i]){
                        s.insert({d1(b[i], a[i]), i});
                }
        }
        while(k > 0){
                k -= 1;
                int i = s.begin()->se;
                s.erase(s.begin());
                b[i] += 1;
                if(b[i] < a[i]){
                        s.insert({d1(b[i], a[i]), i});
                }
        }
}

void make2()
{
        k = -k;
        long long l = 0, r = inf / 2;
        while(l < r){
                long long m = (l + r) / 2;
                if(get2(m + 1, 0) < k){
                        l = m + 1;
                } else{
                        r = m;
                }
        }
        k -= get2(l, 1);
        set < pair < long long, int > > s;
        for(int i = 1; i <= n; i++){
                if(b[i] > 0){
                        s.insert({d2(b[i], a[i]), i});
                }
        }
        while(k > 0){
                k -= 1;
                int i = s.begin()->se;
                s.erase(s.begin());
                b[i] -= 1;
                if(b[i] > 0){
                        s.insert({d2(b[i], a[i]), i});
                }
        }
}

int main()
{
        ios_base::sync_with_stdio(false);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        cin >> n >> k;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                long long x = sq(a[i] / 3.0);
                long long best = - inf;
                for(int dx = -5; dx <= 5; dx++){
                        long long nx = x + dx;
                        if(nx < 0 || nx > a[i]){
                                continue;
                        }
                        if(F(nx, a[i]) > best){
                                best = F(nx, a[i]);
                                b[i] = nx;
                        }
                }
                k -= b[i];
        }
        if(k > 0){
                make1();
        }
        if(k < 0){
                make2();
        }
        for(int i = 1; i <= n; i++){
                cout << b[i] << " ";
        }
}