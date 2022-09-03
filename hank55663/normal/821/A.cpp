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
#define N 200005
#define rank Rank
#define index Index
int main(){
    int n;
    scanf("%d",&n);
    int a[50][50];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int ok=1;
    for(int i =0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]!=1){
                int ook=0;
                for(int s=0;s<n;s++){
                    for(int t=0;t<n;t++){
                        if(a[i][s]+a[t][j]==a[i][j])
                            ook=1;
                    }
                }
                if(!ook)
                ok=0;
            }
        }
    }
    if(!ok)printf("No\n");
    else printf("Yes\n");
}

/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
11010101
*/