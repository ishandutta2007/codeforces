
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>

using namespace std;
 
// #define MAXN  100
// vector<int> v[MAXN];
// vector<int> v2;
// bool b[MAXN];

// void dfs(int i){
//     b[i] = true;
//     for(int j = 0; j < (int)v[i].size(); j++){
//         if(!b[v[i][j]]){
//             dfs(v[i][j]);
//             v2.push_back(v[i][j]);
//         }
//     }
// }
int main()
{
    // int n, m;
    // scanf("%d %d", &n, &m);
    // for(int i = 0; i < m; i++){
    //     int a, b;
    //     scanf("%d %d", &a, &b);
    //     v[a - 1].push_back(b - 1);
    // }
    // for(int i = 0; i < n; i++){
    //     if(!b[i]){
    //         dfs(i);
    //         v2.push_back(i);
    //     }
    // }
    // if((int)v2.size() < n){
    //     printf("NO\n");
    // } else {
    //     printf("YES\n");
    //     for(int i = n - 1; i >= 0; i--){
    //         printf("%d ", v2[i] + 1);
    //     }
    //     printf("\n");
    // }
    int n, m, f[100];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &f[i]);
    }
    sort(f, f + m);
    int a = 1000000000;
    for(int i = 0; i <= m - n; i++){
        a = min(a, f[i + n - 1] - f[i]);
    }
    printf("%d\n", a);

    return 0;
}