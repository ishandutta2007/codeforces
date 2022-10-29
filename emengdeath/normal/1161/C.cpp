#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include <cstdio>
using namespace std;
int sum[51];
bool f[51][51];
int n, cnt;
bool sig;
int main(){
    scanf("%d", &n);
    for (int i = 1 ;i <= n ; i ++)
    {
        int x;
        scanf("%d", &x);
        sum[x] ++;
    }
    for (int i = 1;  i <= 50; i ++)
        if (sum[i]) {
            if (sum[i] <= n  / 2)
                printf("Alice");
            else
                printf("Bob");
            return 0;
        }
    return 0;
}