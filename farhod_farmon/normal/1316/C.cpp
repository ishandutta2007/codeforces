#include <bits/stdc++.h>
//#pragma GCC optimize("Ofast")

#define fi first
#define se second

const int N = 2000100;

using namespace std;

int n, m, p;
int a[N], b[N], c[N];

void add(int &x, int y)
{
        x += y;
        if(x >= p) x -= p;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        scanf("%d%d%d", &n, &m, &p);
        vector < int > A, B;
        for(int i = 0; i < n; i++){
                scanf("%d", a + i);
                if(a[i] % p) A.push_back(i);
        }
        for(int j = 0; j < m; j++){
                scanf("%d", b + j);
                if(b[j] % p) B.push_back(j);
        }
        while(A.size() > 2000) A.pop_back();
        while(B.size() > 2000) B.pop_back();

        for(int i: A) for(int j: B){
                add(c[i + j], 1ll * a[i] * b[j] % p);
        }
        int MX = min(A.back(), B.back());
        for(int i = 0; i < N; i++){
                if(c[i] != 0){
                        printf("%d", i);
                        return 0;
                }
        }
        assert(0);
}