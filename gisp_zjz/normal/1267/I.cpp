#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
int f[205][205];
typedef pair <int,int> pi;
pi a[205];
int n,T;
int ask(int x,int y){
    if (!f[x][y]){
        printf("? %d %d\n",x,y);
        fflush(stdout);
        char s[2]; scanf("%s",s);
        if (s[0]=='>') f[x][y]=1; else f[x][y]=-1;
    }
    return f[x][y];
}
bool cmp(pi u,pi v){return ask(u.S,v.S)==1;}

int main(){
    cin >> T;
    while (T--){
        scanf("%d",&n);
        memset(f,0,sizeof(f));
        for (int i=1;i<=n;i++){
            if (ask(i*2-1,i*2)==1) a[i]=(pi){i*2-1,i*2};
            else a[i]=(pi){i*2,i*2-1};
        }
        sort(a+1,a+n+1,cmp);
        int m=n;
        for (int t=1;t<=n;t++){
            if (t%2==1) continue;
            int tmp=ask(a[m-1].S,a[m].F);
            if (t==n) continue;
            m--;
            if (tmp==-1){
                int x=a[m].F,y=a[m+1].F;
                if (ask(x,y)==1) a[m]=(pi){x,y}; else a[m]=(pi){y,x};
                sort(a+1,a+m+1,cmp);
            }
        }
        puts("!"); fflush(stdout);
    }
    return 0;
}