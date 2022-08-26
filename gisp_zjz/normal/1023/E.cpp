#include<bits/stdc++.h>
#define maxn 2304

using namespace std;
bool f[maxn][maxn];
int n,s,t;
char z[10];
bool qry(int a,int b,int c,int d){
    printf("? %d %d %d %d\n",a,b,c,d);
    fflush(stdout);
    scanf("%s",z);
    return z[0]=='Y';
}

int main(){
    cin >> n;
    s=1; t=1;
    for (int i=1;i<n;i++){
        f[s][t]=true;
        if (qry(s+1,t,n,n)) s++; else t++;
    }
    s=n; t=n;
    for (int i=1;i<n;i++){
        f[s][t]=true;
        if (qry(1,1,s,t-1)) t--; else s--;
    }
    f[s][t]=true;
    s=1; t=1;
    printf("! ");
    for (int i=1;i<=2*(n-1);i++) {
        if (f[s+1][t]){
            printf("D"); s++;
        }
        else {
            printf("R"); t++;
        }
    }
    printf("\n");
}