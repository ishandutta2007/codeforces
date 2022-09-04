#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<assert.h>
#include<map>
#include<set>
#include<utility>
#include<iostream>
#include<cmath>
#include<sstream>
#include<queue>
#include<bitset>
#define LL unsigned long long
#define pll pair<LL,LL>
#define pii pair<int,int> 
#define pdd pair<double,double>
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define x first
#define y second
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int main(){
    int n;
    scanf("%d",&n);
    int x=0,y=0;
    char c[200005];
    scanf("%s",c);
    for(int i=0;c[i]!=0;i++){
        if(c[i]=='U'){
            y++;
        }
        if(c[i]=='D'){
            y--;
        }
        if(c[i]=='L'){
            x--;
        }
        if(c[i]=='R'){
            x++;
        }
    }
    int tx,ty;
    scanf("%d %d",&tx,&ty);
    if(tx==x&&ty==y){
        printf("0\n");
    }
    else if(abs(tx)+abs(ty)>n){
        printf("-1\n");
    }
    else if(((tx+ty)&1)!=((x+y)&1)){
        printf("-1\n");
    }
    else{
        int need[250];
        MEM(need);
        int l=0;
        int ans=1e9;
        for(int i=0;c[i]!=0;i++){
            if(c[i]=='U'){
                y--;
            }
            if(c[i]=='D'){
                y++;
            }
            if(c[i]=='L'){
                x++;
            }
            if(c[i]=='R'){
                x--;
            }
            //printf("%d\n",num);
            while(abs(x-tx)+abs(y-ty)<=i-l+1){
                ans=min(ans,i-l+1);
                if(c[l]=='U')
                    y++;
                if(c[l]=='D'){
                    y--;
                }
                if(c[l]=='L')
                    x--;
                if(c[l]=='R')
                    x++;
                l++;
            }
        }
        printf("%d\n",ans);
    }
}