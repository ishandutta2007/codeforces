#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <vector>
#define INF 999999999
using namespace std;

int peopleN, gondolaN;
int u[4005][4005];
int gondola[4005];
int sum[4005][4005];
int dp[1005][4005];
int allSum[4005][4005];
int tree[2050];
int getPos[2050];

void resetTree(){
    for(int i=0; i < 2050; ++i)
        tree[i]=0;
}

void updateTree(int pos, int val){
    while(pos >= 1){
        if(pos%2 == 0)tree[pos+1]=val;
        pos /= 2;
    }
}

int treeQuery(int pos){
    int res=0;
    while(pos >= 1){
        res=max(res, tree[pos]);
        pos/=2;
    }
    return res;
}

int main()
{
    for(int i=1; i < 2050; ++i){
        int j=i;
        while(j < 1024)
            j *= 2;
        getPos[i]=j-1024;
    }
    scanf("%d%d", &peopleN, &gondolaN);
    for(int i=0; i < peopleN; ++i)
        for(int j=0; j < peopleN; ++j){
            u[i][j]=0;
            char c=getchar();
            while(c < '0' || c > '9')
                c=getchar();
            u[i][j]=c-'0';
        }
    for(int i=0; i <= peopleN; ++i){
        sum[i][i]=0;
        for(int j=i+1; j < peopleN; ++j){
            sum[i][j]=sum[i][j-1]+u[i][j];
        }
        for(int j=i-1; j >= 0; --j){
            sum[i][j]=sum[i][j+1]+u[i][j];
        }
    }
    for(int i=0; i < peopleN; ++i){
        allSum[i][i]=0;
        for(int j=i+1; j < peopleN; ++j)
            allSum[i][j]=allSum[i][j-1]+sum[j][i];
    }
    int pos;
    for(int i=1; i <= peopleN; ++i)
        dp[0][i]=INF;
    for(int i=1; i <= gondolaN; ++i)
        dp[i][0]=0;
    dp[0][0]=0;
    for(int i=0; i < peopleN; ++i){
        resetTree();
        for(int j=0; j <= i; ++j){
            int p;
            int q=tree[1];
            for(p=1; p < 1024;){
                int r=getPos[p*2+1];
                int qpre=q;
                if(tree[p*2+1] > q)
                    q=tree[p*2+1];
                if(dp[r][j]+allSum[j][i] <= dp[r][q]+allSum[q][i]){
                    p=2*p;
                    q=qpre;}
                else{
                    p=2*p+1;
                }
            }
            updateTree(p, j);
        }
        for(int j=1; j <= gondolaN; ++j){
            int x=treeQuery(j+1023);
            dp[j][i+1]=dp[j-1][x]+allSum[x][i];
        }
    }
    printf("%d\n", dp[gondolaN][peopleN]);
    return 0;
}