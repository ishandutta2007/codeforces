// Compiled with: g++ -Wall -std=c++14 -pthread

// https://codeforces.com/contest/1513/problem/C

#include <bits/stdc++.h>

using namespace std;

int const MOD = 1e9 + 7;
int const JUMP = 1e5 * 2 + 1;

/*void add_self(long long& a, long long b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;   
    }
}*/

#define add_self(a, b) { a += b; if(a >= MOD) a -= MOD; }

int x[10][JUMP+1][11]; // 10 <- sum of all other digits

void solve(int t) { //, vector<vector<vector<int>>>& cache) {
    #define cache x
    int n, m;
    scanf("%d%d", &n, &m);
    vector<long long> digits_at(10, 0);
    // vector<long long> new_digits_at(10, 0); // why maintain this?
    long long answer = 0;
    while (n != 0) {
        int digit = n % 10;
        for (int n_d = 0; n_d <= 9; n_d++) {
            answer += cache[digit][m][n_d]; // answer grows up to 10^2 * MOD
        }
        n /= 10;
    }
    answer %= MOD;
    /*for (int d = 0; d <= 9; d++) {
        if (digits_at[d] > 0) {
            for (int n_d = 0; n_d <= 9; n_d++) {
                answer = (answer + (long long) digits_at[d] * cache[d][m][n_d]) % MOD; // extra MOD takes +100ms
                // add_self(new_digits_at[n_d], (digits_at[d] * cache[d][m][n_d]) % MOD);
                //new_digits_at[n_d] += ((digits_at[d] * cache[d][m][n_d]) % MOD);
                //new_digits_at[n_d] %= MOD;
            }
        }
    }*/
    
    /*digits_at = new_digits_at;
    long long answer = 0;
    for (int i = 0; i <= 9; i++) {
        answer += digits_at[i];
        answer %= MOD;
    }*/
    printf("%lld\n", answer);
}


int main() {
    // vector<vector<vector<int>>> x(10, vector<vector<int>>(JUMP + 1, vector<int>(10, 0))); // vector instead of an array takes +250ms
    // preprocessing takes 77ms
    for (int s_d = 0; s_d <= 9; s_d++) {
        vector<int> digits_at(10, 0);
        vector<int> new_digits_at(10, 0);
        digits_at[s_d]++;
        x[s_d][0][s_d]++;
        for (int i = 1; i <= JUMP; i++) {
            for (int d = 0; d <= 8; d++) {
                add_self(new_digits_at[d+1], digits_at[d]);
                // new_digits_at[d + 1] += digits_at[d];
                // new_digits_at[d + 1] %= MOD;
            }
            new_digits_at[0] += digits_at[9];
            new_digits_at[0] %= MOD;
            new_digits_at[1] += digits_at[9];
            new_digits_at[1] %= MOD;
            digits_at = new_digits_at;
            for (int d = 0; d <= 9; d++) {
                new_digits_at[d] = 0;
                x[s_d][i][d] = digits_at[d];
            }
        }
    }
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        solve(i);
    }
}