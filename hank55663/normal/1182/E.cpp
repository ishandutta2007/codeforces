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
struct matrix{
    LL a[5][5];
    LL n;
    matrix(int _n){
        n=_n;
        MEM(a);
        for(int i = 0;i<n;i++)  
            a[i][i]=1;
    }
    matrix(){
        MEM(a);
    }
};
int mod=1e9+6;
matrix operator*(const matrix &a,const matrix &b){
    matrix c(a.n);
    MEM(c.a);
    for(int i = 0;i<a.n;i++){
        for(int j=0;j<a.n;j++){
            for(int k=0;k<a.n;k++){
                c.a[i][j]+=a.a[i][k]*b.a[k][j]%mod;
                c.a[i][j]%=mod;
            }
        }
    }
    return c;
}
matrix f_pow(matrix a,LL b){
    matrix res(a.n),temp=a;
    while(b){
        if(b&1)res=res*temp;
        temp=temp*temp;
        b>>=1;
    }
    return res;
}
LL f_pow(LL a,LL b,LL Mod){
  //  printf("%lld %lld\n",a,b);
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%Mod;
        temp=temp*temp%Mod;
        b>>=1;
    }
    return res;
}
int main(){
    LL n,f1,f2,f3,c;
    scanf("%lld %lld %lld %lld %lld",&n,&f1,&f2,&f3,&c);
   // LL N=n;
   // for(int n = 4;n<=N;n++){
    matrix m;
    m.n=3;
    m.a[0][1]=1;
    m.a[1][2]=1;
    m.a[2][0]=m.a[2][1]=m.a[2][2]=1;
    //m=m*m;
   // for(int i = 0;i<3;i++,printf("\n"))
    //    for(int j = 0;j<3;j++)
      //      printf("%d ",m.a[i][j]);
    matrix res=f_pow(m,n-3);
    //for(int i = 0;i<3;i++,printf("\n"))
     //   for(int j = 0;j<3;j++)
       //     printf("%d ",res.a[i][j]);
    LL ans=f_pow(f1,res.a[2][0],mod+1)*f_pow(f2,res.a[2][1],mod+1)%(mod+1)*f_pow(f3,res.a[2][2],mod+1)%(mod+1);
    m.n=5;
    MEM(m.a);
    m.a[0][1]=1;
    m.a[1][2]=1;
    m.a[2][4]=2;
    m.a[2][3]=1;
    m.a[2][2]=1;
    m.a[2][1]=1;
    m.a[2][0]=1;
    m.a[3][3]=1;
    m.a[3][4]=2;
    m.a[4][4]=1;
    res=f_pow(m,n-3);
    //for(int i = 0;i<4;i++,printf("\n"))
    //    for(int j = 0;j<4;j++)
     //       printf("%d ",res.a[i][j]);
    // printf("%lld\n",ans);
    ans = ans*f_pow(c,res.a[2][4],mod+1)%(mod+1);
    printf("%lld\n",ans);
   // }
}
/*
vector<int> v[100005];
vector<int> dep[100005];
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    queue<int> q;
    vector<int> last;
    vector<int> v;
    for(int i = 1;i<=n;i++){
        if(v[i].size()==1){
            q.push(i);
        }
    }
    vector<int> child[100005];
    int vis[100005];
    MEM(vis);
    while(!q.empty()){
        while(!q.empty()){
            int x=q.front();
            for(auto it:v[x]){
                child.pb(it);
                if(!vis[it]){
                    v.pb(it);
                }
                vis[it]=1;
            }
        }    
    }
}*/

/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/