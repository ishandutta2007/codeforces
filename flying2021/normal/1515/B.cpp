#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define N 100010
using namespace std;
int n;
void clear(){}
bool check(int x)
{
    int d=sqrt(x);
    if(1ll*d*d==x || 1ll*(d+1)*(d+1)==x) return true;
    return false;
}
void solve()
{
    scanf("%d",&n);
    if(n%2==1){puts("NO");return;}
    if(n%2==0 && check(n/2)){puts("YES");return;}
    if(n%4==0 && check(n/4)){puts("YES");return;}
    puts("NO");
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t --> 0){solve();clear();}
    return 0;
}