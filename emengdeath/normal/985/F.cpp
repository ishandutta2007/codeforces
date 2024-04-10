#include <algorithm>
#include <cstdio>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 2e5 + 10;
long long f[26][N][2], ff[26][N][2];
long long a[N][2];
pair<long long, long long>d[26], dd[26];
int n, m;
pair<long long, long long> get(int sig, int l, int r) {
    return make_pair((f[sig][r][0] - (f[sig][l - 1][0] * a[r -l + 1][0]) % mod  + mod) % mod, f[sig][r][1] - f[sig][l - 1][1] * a[r -l + 1][1]);
}
int main(){
    scanf("%d %d", &n, &m);
    a[0][0]= 1;
    a[0][1]= 1;
    for (int i= 1 ;i <= n; i++){
        a[i][0] = a[i - 1][0] * 3 % mod;
        a[i][1] = a[i - 1][1] * 233;
        char c;
        scanf(" %c", &c);
        for (int j = 0; j < 26; j ++) {
            f[j][i][0] = f[j][i - 1][0] * 3 % mod;
            f[j][i][1] = f[j][i - 1][1] * 233;
        }
        f[c - 'a'][i][0]  = (f[c-'a'][i][0] + 1) % mod;
        f[c - 'a'][i][1] += 121;
    }
    while (m--) {
        int l, ll, len;
        scanf("%d %d %d", &l, &ll, &len);
        for (int i =0; i < 26; i ++)
        {
            d[i] = get(i, l, l + len - 1);
            dd[i] = get(i, ll, ll + len - 1);
        }
        sort(d, d + 26);
        sort(dd, dd + 26);
        bool sig = 1;
        for (int i = 0; i < 26;  i++)
            sig &= (d[i] == dd[i]);
        sig ?puts("YES"):puts("NO");
    }
    return 0;
}