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
int main(){
    int t;
    scanf("%d",&t);
    int col[50005],row[50005];
    while(t--){
        int n,m;
        scanf("%d %d",&n,&m);
        vector<vector<char> > c(n,vector<char>(m));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                scanf(" %c",&c[i][j]);
            }
        }
        fill(col,col+m,0);
        fill(row,row+n,0);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(c[i][j]=='.'){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int ans=1e9;
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(c[i][j]=='.'){
                    ans=min(row[i]+col[j]-1,ans);
                }
                else{
                    ans=min(row[i]+col[j],ans);
                }
            }
        }
        printf("%d\n",ans);
    }
}
/*
4
8
2 2 4
3 1 3 5
1 2
2 1 5
4 2 6 4 7
2 5 8
2 8 5
2 7 6
 */