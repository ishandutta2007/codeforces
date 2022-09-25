#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,q;
int arr[300005];
int memo[300005][23];
int succ[23]; //next num with same bit flip
void print(int i){
    for (int x=0;x<23;x++){
        printf("%d ",(memo[i][x]==2139062143)?-1:memo[i][x] );
    }
    printf("\n");
}
void transfer(int i,int j){
    for (int x=0;x<23;x++){
        memo[i][x]=min(memo[i][x],memo[j][x]);
    }
}
void init(int i){
    int k=arr[i];
    for (int bit=1;bit<300005;bit<<=1){
        if (k&bit){
            if (succ[__builtin_ctz(bit)]!=-1){
                transfer(i,succ[__builtin_ctz(bit)]);
                memo[i][__builtin_ctz(bit)]=min(succ[__builtin_ctz(bit)],memo[i][__builtin_ctz(bit)]);
            }
            succ[__builtin_ctz(bit)]=i;
        }
    }
    //print(i);
}
int main(){
    //freopen("input.txt","r",stdin);
    memset(memo,127,sizeof(memo));
    memset(succ,-1,sizeof(succ));
    scanf("%d%d",&n,&q);
    for (int x=1;x<=n;x++) scanf("%d",&arr[x]);
    for (int x=n;x>0;x--) init(x);
    int a,b; //interval a,b
    while (q--){
        scanf("%d%d",&a,&b);
        for (int bit=1;bit<300005;bit<<=1){
            if (arr[b]&bit){
                if (memo[a][__builtin_ctz(bit)]<=b){
                    printf("Shi\n");
                    goto _end;
                }
            }
        }
        printf("Fou\n");
        _end:;
    }
}