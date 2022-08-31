#include<cmath>
#include<set>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define maxn 2020
#define inf 1000000020

using namespace std;

char s[maxn];int n;

int main()
{
    scanf("%d",&n);
    if (n==1){
        printf("1 1\n1\n");
    }
    else printf("%d 2\n1 2\n",(n-1)*2);
    return 0;
}