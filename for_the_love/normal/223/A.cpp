#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
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
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

char s[N], z[N];

int g[N], f[N];
int main(){
    scanf("%s", s + 1);
    int l = 0, cnt = 0, top = 0, n = strlen(s + 1), L = 1, R = 0, ans = 0;
    for (int i = 1; i <= n; i++){
        if (s[i] == '('){
            z[++top] = '(';
            f[top] = l;
            g[top] = cnt;
            cnt = l = 0;
        }else if (s[i] == '['){
            z[++top] = '[';
            f[top] = l;
            g[top] = cnt;
            cnt = l = 0;
        }else if (s[i] == ')'){
            if (z[top] != '('){
                top = cnt = l = 0;
                continue;
            }else{
                cnt += g[top];
                l++;
                l += f[top];
                top--;
                if (cnt > ans){
                    ans = cnt;
                    L = i - l * 2 + 1;
                    R = i;
                }
            }
        }else{
            if (z[top] != '['){
                top = cnt = l = 0;
                continue;
            }else{
                cnt++;
                cnt += g[top];
                l++;
                l += f[top];
                top--;
                if (cnt > ans){
                    ans = cnt;
                    L = i - l * 2 + 1;
                    R = i;
                }
            }
        }
    }
    printf("%d\n", ans);
    for (int i = L; i <= R; i++) putchar(s[i]);
}