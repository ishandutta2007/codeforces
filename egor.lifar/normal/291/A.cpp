
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
// int b[MAXN];
// int s = 0;
// void dfs(int i){
//     b[i] = 2;
//     for(int j = 0; j < (int)v[i].size(); j++){
//         if(b[v[i][j]] == 0){
//             b[v[i][j]]= 1;
//             dfs(v[i][j]);
//             v2.push_back(v[i][j]);
//         }else{
//             if(b[v[i][j]] == 2){
//                 printf("NO\n");
//                 s = 1;
//                 exit(0);
//                 return;
//             }
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
    //     b[i] = 0;
    // }
    // for(int i = 0; i < n; i++){
    //     if(b[i] == 0){
    //         dfs(i);
    //         v2.push_back(i);
    //     }
    // }
    // if(s == 0){

    //     printf("YES\n");
    //     for(int i = n - 1; i >= 0; i--){
    //         printf("%d ", v2[i] + 1);
    //     }
    //     printf("\n");
   
    // }
    int n, a[1000];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    for(int i = 1; i <n - 1; i++){
        if(a[i] == a[i - 1] && a[i] == a[i + 1] && a[i] != 0){
            printf("-1\n");
            return 0;
        }
    }
    int k = 0;
    for(int i = 1; i < n; i++){
        if(a[i] == a[i - 1] && a[i] != 0){
            k++;
        }
    }
    printf("%d\n", k);
    return 0;
}