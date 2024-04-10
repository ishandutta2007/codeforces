#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

#define itn int
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second

using namespace std;

char a[5000][5000][4];
bool b[5000][5000];
int d[5000][5010], S[5000][5010];
int cn[5000][5010];

char get(int x, int y, int z){
    return ((a[x][y][z / 4] >> (2 * (z % 4))) & 3);
}

void set(int x, int y, int z, char c){
    a[x][y][z / 4] ^= (c << (2 * (z % 4)));
}

int toint(string t){
    int res = 0;
    for (int i = 0; i < t.length(); i++){
        res = res * 2 + (t[i] - '0');
    }
    return res;
}

int main(){

    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (s[i] < s[j]) set(i, j, 0, 1); else
            if (s[i] == s[j]) set(i, j, 0, 0); else
            set(i, j, 0, 2);
        }
    }
    int C = 2;
    for (int _ = 1; C < n; _++, C *= 2){
        for (int i = 0; i < n; i++){
            for (int j = i + C; j < n; j++){
                if (get(i, j, _ - 1) == 1 || (get(i, j, _ - 1) == 0 && get(i + C / 2, j + C / 2, _ - 1) == 1)) set(i, j, _, 1); else
                if (get(i, j, _ - 1) == 0 && get(i + C / 2, j + C / 2, _ - 1) == 0) set(i, j, _, 0); else
                set(i, j, _, 2);
            }
        }
    }
    
    
    int deg[14];
    for (int i = 0; i < 14; i++) deg[i] = (1 << i);
    for (int i = 0; i < n; i++){
        for (int j = 1; i + j + j <= n; j++){
            b[i][i + j] = true;
            int c = 0;
            bool flag = false;
            for (int ij = 13; ij >= 0 && !flag; ij--){
                if (j & deg[ij]){
                    if (get(i + c, i + j + c, ij) == 1){
                        flag = true;
                        break;
                    } else
                    if (get(i + c, i + j + c, ij) == 2){
                        b[i][i + j] = false;
                        flag = true;
                        break;
                    } else {
                        c += deg[ij];
                    }
                }
            }
        }
    }
    
    int base = 1000000007;
    for (int i = 0; i < n; i++){
        cn[i][0] = n;
        for (int j = 1; j <= i + 1; j++){
            if (j < i + 1){
                if (s[i - j + 1] == '0'){
                    d[i][j] = 0;
                    if (j > 0){
                        cn[i][j] = cn[i][j - 1];
                    } else {
                        cn[i][j] = n;
                    }
                } else {
                    if (i - j + 1 >= j && b[i - j + 1 - j][i - j + 1]){
                        if (j > 0)
                            cn[i][j] = min(cn[i][j - 1], cn[i - j][j] + 1);
                        else
                            cn[i][j] = cn[i - j][j] + 1;
                        d[i][j] = S[i - j][j];
                    } else {
                        if (j > 0)
                            cn[i][j] = min(cn[i][j - 1], cn[i - j][min(j - 1, i - j + 1)] + 1);
                        else
                            cn[i][j] = cn[i - j][min(j - 1, i - j + 1)] + 1;
                        d[i][j] = S[i - j][min(j - 1, i - j + 1)];
                    }
                }
            } else {
                d[i][j] = 1;
                cn[i][j] = 1;
            }
            if (j > 0) S[i][j] = (S[i][j - 1] + d[i][j]) % base; else
            S[i][j] = d[i][j];
        }
    }
    cout << S[n - 1][n] << "\n";
    int cnt = base;
    for (int j = 0; j < min(15, n + 1); j++){
        if (d[n - 1][j] > 0){
            int res = 0;
            for (int ij = n - j; ij < n; ij++){
                res = res * 2 + s[ij] - '0';
            }
            if (res + cn[n - 1][j] < cnt) cnt = res + cn[n - 1][j];
        }
    }
    /*
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= n; j++){
            cerr << cn[i][j] << " ";
        }
        cerr << "\n";
    }
    */
    int j = 10;
    if (j > n){
        cout << cnt << "\n";
        return 0;
    }
    while (j <= n && d[n - 1][j] == 0) j++;
    int res = 0;
    for (int ij = n - j; ij < n; ij++){
        res = (res * 2 + (s[ij] - '0')) % base;
    }
    if (cnt == base) cnt = (res + cn[n - 1][j]) % base;
    cout << cnt << "\n";

    return 0;
}