#include<bits/stdc++.h>
using namespace std;
int N,n,a[10],p[10],j,cnt,x,y,z;

int main(){
    cin >> n; N=n;
    j=2; cnt=0;
    while (j*j<=n){
        if (n%j==0){
            p[++cnt]=j;
            while (n%j==0) a[cnt]++,n/=j;
        }
        ++j;
    }
    if (n>1) ++cnt,p[cnt]=n,a[cnt]=1;
    if (cnt<2) {puts("NO");return 0;}
    z=N-1;
    while (z%p[1]) z-=p[2],y++;
    x=z/p[1];
    puts("YES");
    printf("2\n");
    printf("%d %d\n",x,N/p[1]);
    printf("%d %d\n",y,N/p[2]);
    return 0;
}