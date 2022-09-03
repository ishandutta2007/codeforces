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
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 1500005
char c[2005][2005];
int pre[2005][2005];
int main(){
    int n,k;
    scanf("%d %d",&n,&k);
    vector<int> v[2005];
    for(int i = 0;i<n;i++){
        scanf("%s",c[i]);
        int l=1e9,r=0;
        for(int j=0;c[i][j]!=0;j++){
            if(c[i][j]=='B'){
                l=min(l,j);
                r=max(r,j);
            }
        }
        if(l>r){
            pre[0][0]++;
        }
        else if(r-l+1<=k){
            pre[max(i-k+1,0)][max(r-k+1,0)]++;
            pre[max(i-k+1,0)][l+1]--;
            pre[i+1][max(r-k+1,0)]--;
            pre[i+1][l+1]++;
        }
    }
    for(int i=0;i<n;i++){
        int l=1e9,r=0;
        for(int j = 0;j<n;j++){
            if(c[j][i]=='B'){
                l=min(l,j);
                r=max(r,j);
            }
        }
        if(l>r){
            pre[0][0]++;
        }
        else if(r-l+1<=k){
            pre[max(r-k+1,0)][max(i-k+1,0)]++;
            pre[l+1][max(i-k+1,0)]--;
            pre[max(r-k+1,0)][i+1]--;
            pre[l+1][i+1]++;
        }
    }
    int ans=0;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            //printf("%d ",pre[i][j]);
            if(i!=0)pre[i][j]+=pre[i-1][j];
            if(j!=0)pre[i][j]+=pre[i][j-1];
            if(i!=0&&j!=0)pre[i][j]-=pre[i-1][j-1];
           // printf("%d ",pre[i][j]);
            ans=max(ans,pre[i][j]);
        }
       // printf("\n");
    }
    printf("%d\n",ans);
}