#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int M = 1111;

int n, m, h, s[M];

int main(){
    scanf("%d%d%d", &n, &m, &h);
    for(int i = 1; i <= m; ++ i){
        scanf("%d", s + i);
    }
    swap(s[h], s[m]);  
    n -= 1;
    int sum[2] = {0, 0};
    for(int i = 1; i < m; ++ i){
        sum[0] += s[i];
    }
    sum[1] = sum[0] + s[m] - 1;
    if(sum[1] < n){
        printf("-1.0\n");
    }else{
        double result = 1.0;
        for(int i = 0; i < n; ++ i){
            result = result * (sum[0] - i) / (sum[1] - i);
        }
        printf("%.8f\n", 1 - result);
    }
    return 0;
}