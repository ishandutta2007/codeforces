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
#define N 262144
LL b[105][105];
LL inf=3e18;
LL cal(int n,int m){
    for(int i = 1;i<m;i++){
        if(b[0][i]<0)b[0][i]=inf;
        b[0][i]+=b[0][i-1];
        b[0][i]=min(b[0][i],inf);
    }
    for(int i=1;i<n;i++){
        if(b[i][0]<0)b[i][0]=inf;
        b[i][0]+=b[i-1][0];
        b[i][0]=min(b[i][0],inf);
    }
    for(int i = 1;i<n;i++){
        for(int j=1;j<m;j++){
            if(b[i][j]<0)b[i][j]=inf;
            b[i][j]+=min(b[i-1][j],b[i][j-1]);
            
            b[i][j]=min(b[i][j],inf);
        }
    }
    return b[n-1][m-1];
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        LL a[105][105];
        int n,m;
        scanf("%d %d",&n,&m);
        vector<LL> v;
        for(int i = 0;i<n;i++){
            for(int j =0;j<m;j++){
                scanf("%lld",&a[i][j]);
                a[i][j]-=i+j;
                if(i!=0||j!=0)a[i][j]-=a[0][0];
                if(a[i][j]<0)v.pb(a[i][j]);
            }
        }
        a[0][0]=0;
        sort(v.begin(),v.end());
        v.resize(unique(v.begin(),v.end())-v.begin());
        //a[0][0]=0;
        LL ans=inf;
        v.pb(0);
        for(auto it:v){
            for(int i = 0;i<n;i++){
                for(int j=0;j<m;j++){
                    b[i][j]=a[i][j]-it;
                }
            }
            ans=min(cal(n,m),ans);
        }
        printf("%lld\n",ans);
    }

}

/*
C[i][j]=C[i>>1][j]
1000

1001
0000
0001
1000
1001
*/