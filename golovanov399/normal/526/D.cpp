#include <bits/stdc++.h>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define all(x) (x).begin(), (x).end()

using namespace std;

int n;
int k;
char a[1111111];

string solve(){
    vector<int> z(n + 1);
    z[0] = n;
    int l = 0, r = 0;
    for (int i = 1; i < n; i++){
        if (i <= r)
            z[i] = min(z[i - l], r - i);
        while (i + z[i] < n && a[z[i]] == a[i + z[i]])
            z[i]++;
        if (i + z[i] > r){
            l = i;
            r = i + z[i];
        }
    }

    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; i++){
        if (z[i] >= 1ll * i * (k - 1)){
            // cerr << i << "\n";
            ans[i * k - 1]++;
            ans[min(i * (k + 1), min(i * k + z[i * k], i + z[i]))]--;
            // for (int j = i * k; j <= i * k + z[i * k] && j <= i + z[i]; j++)
            //  ans[j]++;
        }
    }
    int qw = 0;
    string res = "";
    for (int i = 0; i < n; i++){
        qw += ans[i];
        res += (char)('0' + (qw > 0));
    }
    return res;
}

string stupid(){
    vector<char> ok(n);
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= n; j++){
            if (i + j == 0)
                continue;
            bool qw = true;
            int m = i * (k + 1) + j * k;
            if (m > n)
                continue;
            for (int ij = i + j; ij < m; ij++)
                qw &= (a[ij] == a[ij - i - j]);
            if (qw)
                ok[m - 1] = 1;
        }
    }
    string ans = "";
    for (int i = 0; i < n; i++)
        ans += (char)('0' + (ok[i]));
    return ans;
}

int main(){

    scanf("%d", &n);
    scanf("%d", &k);
    scanf("%s", a);

    puts(solve().c_str());

    // while (true){
    //  n = rand() % 10 + 1;
    //  k = rand() % 10 + 1;
    //  for (int i = 0; i < n; i++){
    //      a[i] = 'a' + rand() % 3;
    //  }
    //  auto res = solve();
    //  auto ans = stupid();
    //  if (ans != res){
    //      cerr << n << " " << k << "\n";
    //      for (int i = 0; i < n; i++)
    //          cerr << a[i];
    //      cerr << "\n";
    //      cerr << ans << "\n" << res << "\n";
    //      return 0;
    //  }
    // }    

    return 0;
}