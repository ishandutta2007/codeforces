#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 


const int mod = 1000000007;

char board[2100][2100];
int rocks_below[2100][2100];
int rocks_right[2100][2100];
int rows, cols;

int pd_from_left[2100][2100];
int sum_pd_left[2100][2100];
int pd_from_above[2100][2100];
int sum_pd_above[2100][2100];

int ok_left[2100][2100];
int ok_above[2100][2100];

void solve()
{
    scanf("%d %d", &rows, &cols);

    for (int i = 0; i < rows; i++) {
        scanf("%s", board[i]);
    }

    for (int i = rows-1; i >= 0; i--) {
        for (int j = cols-1; j >= 0; j--) {
            if (i+1 < rows) rocks_below[j][i] = rocks_below[j][i+1] + (board[i+1][j] == 'R');
            if (j+1 < cols) rocks_right[i][j] = rocks_right[i][j+1] + (board[i][j+1] == 'R');
        }
    }

    for (int i = 0; i < rows; i++) {
        int fr = 0;
        for (int j = 0; j < cols; j++) {
            while (fr < j && j + rocks_right[i][fr] >= cols ) fr++;
            ok_left[i][j] = fr;
        }
    }

    for (int j = 0; j < cols; j++) {
        int fr = 0;
        for (int i = 0; i < rows; i++) {
            while (fr < i && i + rocks_below[j][fr] >= rows ) fr++;
            ok_above[i][j] = fr;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (i > 0) {
                pd_from_above[i][j] = sum_pd_left[i-1][j];
                if (ok_above[i][j] > 0)  pd_from_above[i][j] -= sum_pd_left[ok_above[i][j] - 1][j];
                pd_from_above[i][j] = ((pd_from_above[i][j] % mod) + mod) % mod;
            }

            if (j > 0) {
                pd_from_left[i][j] = sum_pd_above[i][j-1];
                if (ok_left[i][j] > 0)  pd_from_left[i][j] -= sum_pd_above[i][ok_left[i][j] - 1];
                pd_from_left[i][j] = ((pd_from_left[i][j] % mod) + mod) % mod;
            }

            if (i == 0 && j == 0) pd_from_above[i][j] = pd_from_left[i][j] = 1;

            sum_pd_above[i][j] = pd_from_above[i][j];
            if (j >= 0) sum_pd_above[i][j] = (sum_pd_above[i][j-1] + sum_pd_above[i][j]) % mod;
            
            sum_pd_left[i][j] = pd_from_left[i][j];
            if (i >= 0) sum_pd_left[i][j] = (sum_pd_left[i-1][j] + sum_pd_left[i][j]) % mod;
        }
    }

    int ans = (pd_from_left[rows-1][cols-1] + pd_from_above[rows-1][cols-1]) % mod;
    if (rows == 1 && cols == 1) ans = 1;
    printf("%d\n", ans);
}


#include <fstream>


int main() {


    solve();
}