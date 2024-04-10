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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
#define N 65536
int val[10];
bool dp[2005][3005];
int main(){
    val[0]=127-8;
    val[1]=(1<<2)+(1<<5);
    val[2]=127-2-32;
    val[3]=127-2-16;
    val[4]=127-1-16-64;
    val[5]=127-4-16;
    val[6]=127-4;
    val[7]=1+4+32;
    val[8]=127;
    val[9]=127-16;
    int n,k;
    scanf("%d %d",&n,&k);
    dp[0][0]=1;
    int a[2005];
    for(int i = 1;i<=n;i++){
        char c[10];
        scanf("%s",c);
        reverse(c,c+7);
        a[i]=0;
        for(int j =0;c[j]!=0;j++){
            a[i]=a[i]*2+c[j]-'0';
        }
    }
    reverse(a+1,a+n+1);
    for(int i = 1;i<=n;i++){
        for(int j  =0;j<=k;j++){
            if(dp[i-1][j]){
                for(int l=0;l<10;l++){
                    if((a[i]&val[l])==a[i]){
                        int num=__builtin_popcount(val[l]-a[i]);
                        dp[i][j+num]=1;
                    }
                }
            }
        }
    }
    if(dp[n][k]){
        vector<int> v;
        int now=k;
        for(int i = n;i>=1;i--){
            for(int j=9;j>=0;j--){
                if((val[j]&a[i])==a[i]){
                    int num=__builtin_popcount(val[j]-a[i]);
                    if(dp[i-1][now-num]){
                        v.pb(j);
                        now=now-num;
                        break;
                    }
                }
            }
        }
        for(auto it:v)printf("%d",it);
        printf("\n");
    }
    else{
        printf("-1\n");
    }
}

/*

3 2 +2
3 1 +1
2 1 +1
3 1 +1
2 1 +1

*/
/*
5 5
1 1 1 2 2
1 2 100
2 3 100
3 4 1
4 5 1
5 1 100
3
1 3 1 0
1 3 2 0
1 3 1 1

200
102
102
*/