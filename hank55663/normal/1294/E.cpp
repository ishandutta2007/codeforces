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
#define ld long double
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<vector<int> > a(n,vector<int>(m));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            scanf("%d",&a[i][j]);
            a[i][j]--;
        }
    }
    int cnt[200005];
    
    int ans=0;
    for(int i = 0;i<m;i++){
        fill(cnt,cnt+n+1,0);
        for(int j=0;j<n;j++){
            if(a[j][i]%m==i&&a[j][i]<n*m){
                cnt[(j-a[j][i]/m+n)%n]++;
            }
        }
        int add=1e9;
        for(int j=0;j<n;j++){
            //printf("%d ",cnt[j]);
            add=min(add,j+n-cnt[j]);
        }
        ans+=add;
     //   printf("%d\n",add);
    }
    printf("%d\n",ans);
}