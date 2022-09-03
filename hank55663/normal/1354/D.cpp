#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
#define N 262144
int cnt[1<<20];
void add(int x,int k){
    for(int i = x;i<(1<<20);i+=i&-i){
        cnt[i]+=k;
    }
}
int query(int x){
    int sum=0,res=0;
    for(int i = 19;i>=0;i--){
        if(sum+cnt[res+(1<<i)]<x){
            sum+=cnt[res+(1<<i)];
            res+=(1<<i);
        }
    }
    return res;
}
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        add(x,1);
    }
    int tot=n;
    while(q--){
        int x;
        scanf("%d",&x);
        if(x>0){
            add(x,1);
            tot++;
        }
        else{
            add(query(-x)+1,-1);
            tot--;
        }
    }
    if(tot)
    printf("%d\n",query(1)+1);
    else
    printf("0\n");
}

/*
C[i][j]=C[i>>1][j]
1000

1001
0000
0001
1000
1001
*/