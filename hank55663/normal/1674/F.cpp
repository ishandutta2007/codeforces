#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define index Index
int S[1005][1005];
void add(int x,int y,int k){
    for(int i =x;i<1005;i+=i&-i){
        for(int j = y;j<1005;j+=j&-j){
            S[i][j]+=k;
        }
    }
}
int query(int x,int y){
    int res=0;
    for(int i = x;i>0;i-=i&-i){
        for(int j=y;j>0;j-=j&-j){
            res+=S[i][j];
        }
    }
    return res;
}
void solve(){
    int n,m,q;
    scanf("%d %d %d",&n,&m,&q);
    char c[1005][1005];
    int tot=0;
    for(int i = 1;i<=n;i++){
        scanf("%s",c[i]+1);
        for(int j = 1;j<=m;j++){
            if(c[i][j]=='*'){
                add(i,j,1);
                tot++;
            }
        }
    }
    while(q--){
        int x,y;
        scanf("%d %d",&x,&y);
        if(c[x][y]=='*'){
            add(x,y,-1);
            c[x][y]='.';
            tot--;
        }
        else{
            add(x,y,1);
            c[x][y]='*';
            tot++;
        }
        int a=tot/n,b=tot%n;
        int res=query(n,a)+query(b,a+1)-query(b,a);
     //   printf("%d %d %d %d\n",a,b,res,tot);
        printf("%d\n",tot-res);
    }
    
}  
int main(){
    srand(time(NULL));
    int t=1;0000;
   // scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
1101011?0 5 1
001101?00 3 1
101000110 4 0
001011010 4 0
0101?01?? 3 3
00?1000?0 1 2
223413320
  1 1 131
  40018/76270
*/