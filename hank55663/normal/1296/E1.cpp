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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
vector<int> v[205];
int color[205];
int dfs(int x,int col){
    color[x]=col;
    for(auto it:v[x]){
        if(color[it]==-1){
            if(!dfs(it,col^1))
                return false; 
        }
        else{
            if(color[it]!=(col^1))return false;
        }
    }
    return true;
}
int main() {
    int n;
    scanf("%d",&n);
    char c[205];
    scanf("%s",c);
    for(int i = 0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(c[j]<c[i]){
                v[j].pb(i);
                v[i].pb(j);
            }
        }
    }
    MEMS(color);
    for(int i = 0;i<n;i++){
        if(color[i]==-1){
            if(!dfs(i,0)){
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
    for(int i = 0;i<n;i++)
        printf("%d",color[i]);
    printf("\n");
}
/*
int main(){

"RGGGGRRRRG", "RG"
}*/