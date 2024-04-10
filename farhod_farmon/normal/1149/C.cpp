#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 131072;
const long long mod = 1e9 + 7;

using namespace std;

struct seg
{
        int res;
        int a, b;
        int sum;
        int left, right;
        seg(int x = 0)
        {
                sum = x;
                res = 0;
                a = x;
                b = - 2 * x;
                left = right = a + b;
        }
};

seg comb(seg x, seg y)
{
        seg f;
        f.sum = x.sum + y.sum;
        y.b -= 2 * x.sum;
        y.a += x.sum;
        y.left -= x.sum;
        y.right -= x.sum;
        f.res = max(x.res, y.res);
        f.a = max(x.a, y.a);
        f.b = max(x.b, y.b);
        f.right = max(x.right, y.right);
        f.right = max(f.right, x.b + y.a);
        f.left = max(x.left, y.left);
        f.left = max(f.left, x.a + y.b);
        f.res = max(f.res, x.left + y.a);
        f.res = max(f.res, y.right + x.a);
        return f;
}

int n;
int q;
int a[N];
char c[N];
seg f[4 * N];

void upd(int x)
{
        x += 2 * N;
        if(c[x - 2 * N] == '('){
                f[x] = seg(1);
        } else{
                f[x] = seg(-1);
        }
        for(int i = x / 2; i > 0; i /= 2){
                f[i] = comb(f[i * 2], f[i * 2 + 1]);
        }
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> q;
        n = n * 2 - 2;
        for(int i = 0; i < n; i++){
                cin >> c[i];
                upd(i);
        }

        cout << f[1].res << "\n";
        for(int i = 0; i < q; i++){
                int x, y;
                cin >> x >> y;
                swap(c[x - 1], c[y - 1]);

                upd(x - 1);
                upd(y - 1);

                cout << f[1].res << "\n";
        }
}