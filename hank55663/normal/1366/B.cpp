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
//#define N 262144
#define ULL unsigned long long
#define ll long long

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,x,m;
        scanf("%d %d %d",&n,&x,&m);
        int nowl=x,nowr=x;
        for(int i = 0;i<m;i++){
            int l,r;
            scanf("%d %d",&l,&r);
            if(r<nowl||nowr<l);
            else{
                nowl=min(l,nowl);
                nowr=max(r,nowr);
            }
        }
        printf("%d\n",nowr-nowl+1);
    }
}
/*
1000000000000000000
1000000000000000000 1 1 1 1000000000
*/