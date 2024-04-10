#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200200;
const long long mod = 998244353;

using namespace std;

int n;
int a[N];
int b[N];

int c[N];
long long t[N];

void upd(int x, int g)
{
        while(x < N){
                t[x] += g;
                x += x & -x;
        }
}

void upd_c(int x, int g)
{
        while(x < N){
                c[x] += g;
                x += x & -x;
        }
}

long long get(int x)
{
        long long res = 0;
        while(x > 0){
                res += t[x];
                x -= x & -x;
        }
        return res;
}

long long get_c(int x)
{
        long long res = 0;
        while(x > 0){
                res += c[x];
                x -= x & -x;
        }
        return res;
}

long long f(long long x)
{
        return x * (x + 1) / 2;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
                b[a[i]] = i;
        }

        set < int > A, B;
        long long res = 0, inv = 0;
        for(int i = 1; i <= n; i++){
                int h = b[i];

                inv += get_c(n) - get_c(h);
                upd_c(h, 1);
                upd(h, h);

                if(A.empty()){
                        B.insert(h);
                } else if(B.empty()){
                        A.insert(h);
                } else if(*(--A.end()) < h){
                        B.insert(h);
                } else{
                        A.insert(h);
                }

                while(B.size() > A.size()){
                        A.insert(*B.begin());
                        B.erase(B.begin());
                }
                while(A.size() > B.size()){
                        B.insert(*(--A.end()));
                        A.erase(--A.end());
                }

                int mid = *B.begin();
                res = get(n) - get(mid) - 1ll * (get_c(n) - get_c(mid)) * mid;
                res += 1ll * get_c(mid - 1) * mid - get(mid - 1);

                if(i & 1){
                        res -= 2ll * f(i / 2);
                } else{
                        res -= f(i / 2) + f(i / 2 - 1);
                }

                cout << res + inv << " ";
        }
}