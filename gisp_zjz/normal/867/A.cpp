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
    scanf("%d",&n);scanf("%s",s);
    if (s[0]=='S'&&s[n-1]=='F') printf("YES\n"); else printf("NO\n");
    return 0;
}