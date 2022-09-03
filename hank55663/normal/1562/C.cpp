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
#define MXN 3000000
int isprime[1005];
void solve(){
    int n;
    scanf("%d",&n);
    char c[20005];
    scanf("%s",c);
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='0'){
            if(n-i>=n/2&&n-i-1>=n/2){
                printf("%d %d %d %d\n",i+1,n,i+2,n);
            }
            else if(i+1>=n/2&&i>=n/2){
                printf("%d %d %d %d\n",1,i+1,1,i);
            }
            return;
        }
    }
    printf("%d %d %d %d\n",1,n/2,2,n/2+1);
}
int main(){
    fill(isprime,isprime+1005,1);
    isprime[1]=0;
    for(int i = 2;i<1005;i++){
        if(isprime[i])
        for(int j=i*2;j<1005;j+=i)isprime[j]=0;
    }
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}
/*
100
5 6
9 10 7 5
4 4 4 9
1 2
4 5
3 5
2 3
1 4
1 5

110111
*/