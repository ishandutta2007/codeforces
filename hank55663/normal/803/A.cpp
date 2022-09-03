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
#define less Less
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    if(k>n*n){
        printf("-1\n");
    }
    else{
        int a[105][105];
        MEM(a);
        for(int i=0;i<n;i++){
            for(int j =i;j<n;j++){
                if(i==j){
                    if(k){
                        a[i][j]=1;k--;
                    }
                }
                else{
                    if(k>=2){
                        a[i][j]=a[j][i]=1;
                        k-=2;
                    }
                }
            }
        }
        for(int i = 0;i<n;i++){
            for(int j =0;j<n;j++){
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
    }
}