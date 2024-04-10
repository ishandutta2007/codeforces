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
int val[2][100005];
int main(){
    int n,q;
    scanf("%d %d",&n,&q);
    int cnt=0;
    while(q--){
        int r,c;
        scanf("%d %d",&r,&c);
        r--;
        if(val[r][c]==1){
            val[r][c]=0;
            for(int i = c-1;i<=c+1;i++){
                if(val[r^1][i]){
                    cnt--;
                }
            }
        }
        else{
            val[r][c]=1;
            for(int i = c-1;i<=c+1;i++){
                if(val[r^1][i]){
                    cnt++;
                }
            }
        }
        if(cnt)printf("No\n");
        else printf("Yes\n");
    }
}
/*
2 6
5 7
7 5
4 3
6 4
7 3
6 5
5 7
3 6
4 7
*/
//a+a+1=10a+1
//3a+2=10a+2