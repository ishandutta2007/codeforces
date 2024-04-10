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
int prime[10000007];
int ans[10000007][2];
int main(){
    for(int i = 0;i<10000007;i++){
        ans[i][0]=ans[i][1]=1;
    }
    fill(prime,prime+10000007,1);
    for(int i = 2;i<10000007;i++){
        if(prime[i]){
            for(int j = i;j<10000007;j+=i){
                prime[j]=0;
                if(ans[j][0]==1)ans[j][0]=i;
                else ans[j][1]*=i;
            }
        }
    }
    int n;
    scanf("%d",&n);
    int a[500005];
    for(int i=  0;i<n;i++)scanf("%d",&a[i]);
    for(int j = 0;j<2;j++,printf("\n"))
    for(int i = 0;i<n;i++){
        if(ans[a[i]][1]!=1)
        printf("%d ",ans[a[i]][j]);
        else
        printf("-1 ");
    }
}
/*
1000000000000000000
1000000000000000000 1 1 1 1000000000
*/