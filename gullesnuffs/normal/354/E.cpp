#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <list>
#include <string>
#include <queue>
#include <complex>
#include <stack>
#include <cassert>
#include <map>
#define MOD 1000000007LL
#define INF 999999999
#define PI 3.14159265358

using namespace std;

bool possible[100000];
int ans[100000][8];
int res[18];
long long out[6];

int main() {
    for(int i=0; i <= 6; ++i)
        for(int j=0; i+j <= 6; ++j)
            for(int k=0; k <= 6; ++k)
                for(int m=0; k+m <= 6; ++m)
                    for(int n=0; n <= 6; ++n)
                        for(int o=0; o+n <= 6; ++o)
                            for(int p=0; p <= 6; ++p)
                                for(int q=0; q+p <= 6; ++q){
                                possible[4*i+7*j+40*k+70*m+400*n+700*o+4000*p+7000*q]=1;
                                ans[4*i+7*j+40*k+70*m+400*n+700*o+4000*p+7000*q][0]=i;
                                ans[4*i+7*j+40*k+70*m+400*n+700*o+4000*p+7000*q][1]=j;
                                ans[4*i+7*j+40*k+70*m+400*n+700*o+4000*p+7000*q][2]=k;
                                ans[4*i+7*j+40*k+70*m+400*n+700*o+4000*p+7000*q][3]=m;
                                ans[4*i+7*j+40*k+70*m+400*n+700*o+4000*p+7000*q][4]=n;
                                ans[4*i+7*j+40*k+70*m+400*n+700*o+4000*p+7000*q][5]=o;
                                ans[4*i+7*j+40*k+70*m+400*n+700*o+4000*p+7000*q][6]=p;
                                ans[4*i+7*j+40*k+70*m+400*n+700*o+4000*p+7000*q][7]=q;
                            }
    /*for(int i=0; i < 10000; ++i)
        if(!possible[i])
            printf("%d\n", i);*/
    int t;
    scanf("%d", &t);
    while(t--){
        long long n;
        scanf("%I64d", &n);
        if(n < 600 && !possible[n]){
            printf("-1\n");
            continue;
        }
        for(int i=0; i < 6; ++i)
            out[i]=0;
        long long ten=1;
        for(int i=0; i < 17; ++i)ten *= 10;
        for(int i=17; i >= 4; --i){
            long long m=n-600;
            m/=ten;
            int times;
            for(times=m; !possible[times]; --times);
            for(int j=0; j < ans[times][0]; ++j)
                out[j] += 4*ten;
            for(int j=0; j < ans[times][1]; ++j)
                out[j+ans[times][0]] += 7*ten;
            n -= times*(ten);
            ten/=10;
        }
        for(int j=0; j < ans[n][0]; ++j)
            out[j] += 4;
        for(int j=0; j < ans[n][1]; ++j)
            out[j+ans[n][0]] += 7;
        for(int j=0; j < ans[n][2]; ++j)
            out[j] += 40;
        for(int j=0; j < ans[n][3]; ++j)
            out[j+ans[n][2]] += 70;
        for(int j=0; j < ans[n][4]; ++j)
            out[j] += 400;
        for(int j=0; j < ans[n][5]; ++j)
            out[j+ans[n][4]] += 700;
        for(int j=0; j < ans[n][6]; ++j)
            out[j] += 4000;
        for(int j=0; j < ans[n][7]; ++j)
            out[j+ans[n][6]] += 7000;
        for(int j=0; j < 6; ++j)
            printf("%I64d ", out[j]);
        printf("\n");
    }
    return 0;
}