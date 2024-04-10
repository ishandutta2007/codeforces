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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 300000
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        char c[1005];
        scanf("%s",c);
        int ans=n;
        for(int i = 0;i<n;i++){
            if(c[i]=='1'){
                ans=max(ans,max(i+1,n-i)*2);
            }
        }
        printf("%d\n",ans);
    }
}
/*
3 5 12
..X..
R..?.
LX...
100 100 100 100 8
*/