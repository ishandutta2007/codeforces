#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;


#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int, int> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;



int main(){
    int n;
    scanf("%d", &n);
    if (n <= 3) puts("NO");
    else if (n == 4){
        puts("YES");
        puts("1 * 2 = 2");
        puts("2 * 3 = 6");
        puts("6 * 4 = 24");
    }else if (n == 5){
        puts("YES");
        puts("1 + 4 = 5");
        puts("5 - 2 = 3");
        puts("3 + 5 = 8");
        puts("8 * 3 = 24");
    }else{
        puts("YES");
        if (n & 1){
            int m = (n - 5) / 2;
            if (m & 1){
                puts("4 - 2 = 2");
                puts("2 + 3 = 5");
                puts("5 * 5 = 25");
                puts("25 * 1 = 25");
                int p = 0;
                for (int i = 6; i <= n; i += 2){
                    printf("%d - %d = -1\n", i, i + 1);
                    if (!p) puts("25 + -1 = 24"); else puts("24 - -1 = 25");
                    p ^= 1;
                }
            }else{
                puts("4 - 2 = 2");
                puts("2 + 3 = 5");
                puts("5 * 5 = 25");
                puts("25 - 1 = 24");
                int p = 0;
                for (int i = 6; i <= n; i += 2){
                    printf("%d - %d = -1\n", i, i + 1);
                    if (!p) puts("24 + -1 = 23"); else puts("23 - -1 = 24");
                    p ^= 1;
                }
            }
        }else{
            int m = (n - 4) / 2;
            if (m & 1){
                puts("2 * 3 = 6");
                puts("6 * 4 = 24");
                int p = 0;
                for (int i = 5; i <= n; i += 2){
                    printf("%d - %d = -1\n", i, i + 1);
                    if (p) puts("23 - -1 = 24"); else puts("24 + -1 = 23");
                    p ^= 1;
                }
                printf("23 + 1 = 24");
            }else{
                puts("1 * 2 = 2");
                puts("2 * 3 = 6");
                puts("6 * 4 = 24");
                int p = 0;
                for (int i = 5; i <= n; i += 2){
                    printf("%d - %d = -1\n", i, i + 1);
                    if (p) puts("23 - -1 = 24"); else puts("24 + -1 = 23");
                    p ^= 1;
                }
            }
        }
    }

}