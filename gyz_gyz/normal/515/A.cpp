#include<cstdio>
#include<cmath>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;
int n,m,k;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    k-=fabs(n)+fabs(m);if((k>=0)&&(k%2==0))printf("Yes");else printf("No");
}