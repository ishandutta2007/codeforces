#include <string>
#include <iostream>
#include <string>
#include <iostream>
using namespace std;
const int N = 300;
int n, m;
long long k;
int Next[N];
int A1[N][2], A2[N][N];
long long A3[N][N];
int hashA3[N][N];
long long add(long long x, long long y) {
    return min(x+ y, k + 1);
}
const int mod = 1e9 + 7;
int add1(int x, int y) {
    x += y;
    return x >= mod ? x - mod :x;
}
long long get(string s) {
    int len = s.length();
    Next[0] = 0;
    for (int i=1, j = 0 ;i< len;i++){
        while (j && s[i] != s[j]) j = Next[j - 1];
        if (s[i] == s[j]) j ++;
        Next[i] = j;
    }
    for (int i = 0; i <= len; i ++)
        for (int j = 0; j < 2;j ++)
            if (i < len && s[i] == '0' + j) {
                A1[i][j] = i + 1;
            } else
                if (i == 0)
                    A1[i][j] = 0;
                else {
                    A1[i][j] = A1[Next[i - 1]][j];
                }
    for (int i = 0; i <= len; i ++)
        for (int j = 0; j < 2; j ++) {
            A2[i][j] = A1[i][j];
            hashA3[i][j] = A3[i][j] = (A1[i][j] == len);
        }
    for (int i = 2; i <= n; i ++)
        for (int j = 0; j <= len ; j++) {
            A2[j][i] = A2[A2[j][i-2]][i-1];
            A3[j][i] = add(A3[j][i-2], A3[A2[j][i-2]][i-1]);
            hashA3[j][i] = add1(hashA3[j][i-2], hashA3[A2[j][i-2]][i-1]);
        }
    return A3[0][n];
}
int main() {
    scanf("%d %lld %d", &n, &k, &m);
    if (n == 1) {
        printf("1");
        return 0;
    }
    string s = "";
    for (int i = 0; i < m; i ++) {
        string tmp = s + "0";
        bool orig = 0;
        if (i > 0) {
            int x = 0, y = 0;
            get(s + "0");
            x = add1(x, hashA3[0][n]);
            get(s + "1");
            x = add1(x, hashA3[0][n]);
            get(s);
            y = add1(y, hashA3[0][n]);
            orig = (x != y);
        }
        if (k == 1 && orig) {
            cout<<s<<endl;
            return 0;
        }
        long long v = get(tmp);
        if (v + orig>= k) {
            s = tmp;
            k -= orig;
        } else{
            k -= v + orig;
            s = s + "1";
        }
    }
    cout<< s<<endl;
    return 0;
}