#include<bits/stdc++.h>
#define get(x) scanf("%d",&(x))
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
int n,m,a,b,p[211],c[211];
bool ok[211];
int F(int x){return x==p[x]?x:p[x]=F(p[x]);}
int main()
{
    rep(i,200)p[i]=i;
    get(n);get(m);int x;
    rep(i,n)rep(j,m)p[F(i)]=F(n+(j*n+i)%m);
    get(a);rep(i,a)get(x),ok[F(x)]=1;
    get(b);rep(i,b)get(x),ok[F(x+n)]=1;
    rep(i,n+m)if(!ok[F(i)]){puts("No");return 0;}
    puts("Yes");
    return 0;
}