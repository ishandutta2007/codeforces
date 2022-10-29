#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1111;
const int INF = 1e9 + 7;

vector <int> v;

int c[N], ans[N];

int main(){
    int n, x, n1 = 0, n2 = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n + n; i++){
        scanf("%d", &x);
        if (!c[x]) c[x] = i;
        else if (c[x] == -1){
            v.push_back(i);
        }else{
            ans[c[x]] = 1;
            ans[i] = 2;
            n1++;
            n2++;
            c[x] = -1;
        }
    }
    int cnt = 0, num = 0;
    for (int i = 10; i < 100; i++)
    if (c[i] && c[i] != -1) cnt++;
    for (int i = 10; i < 100; i++)
    if (c[i] && c[i] != -1){
        num++;
        if (num > cnt / 2){
            ans[c[i]] = 2;
            n2++;
        }else{
            ans[c[i]] = 1;
            n1++;
        }
    }
    printf("%d\n", n1 * n2);
    for (int i = 0; i < v.size(); i++)
    if (n1 < n) ans[v[i]] = 1, n1++; else ans[v[i]] = 2, n2++;
    for (int i = 1; i <= n + n; i++) printf("%d ", ans[i]);
}