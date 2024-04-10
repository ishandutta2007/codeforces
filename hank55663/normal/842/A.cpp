#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
int main(){
    int l,r,x,y,k;
    scanf("%d %d %d %d %d",&l,&r,&x,&y,&k);
    for(LL i = x;i<=y;i++){
        if(i*k>=l&&i*k<=r){
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
}

/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/