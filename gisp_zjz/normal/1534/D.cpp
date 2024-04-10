#include<bits/stdc++.h>
using namespace std;
const int maxn=2005;
int d[maxn][maxn],n,cnt,tot;
void ask(int x){
    printf("? %d\n",x);fflush(stdout);
    for (int i=1;i<=n;i++) scanf("%d",&d[x][i]);
}
void work(int o){
    for (int i=2;i<=n;i++) if (d[1][i]%2==o) ask(i);
    puts("!");
    for (int i=1;i<=n;i++) if (d[1][i]%2==o){
        for (int j=1;j<=n;j++) if (d[i][j]==1) printf("%d %d\n",i,j);
    }
}
int main(){
    cin >> n; tot=(n+1)/2;
    ask(1);
    for (int i=1;i<=n;i++) if (d[1][i]%2==0) cnt++;
    if (cnt<=tot) work(0); else work(1);
    return 0;
}