#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
const int mod=1e9+7;
struct  matrix{
    LL a[10][10];
    matrix(){
        MEM(a);
    }
};
matrix operator*(const matrix &a,const matrix &b){
    matrix c;
    for(int i = 0;i<10;i++){
        for(int j = 1;j<10;j++){
            for(int k = j-1;k<j;k++){
                c.a[i][j]+=a.a[i][k]*b.a[k][j]%mod;;
            }
            c.a[i][i]%=mod;
        }
        c.a[i][0]+=a.a[i][9]*b.a[9][0];
        c.a[i][1]+=a.a[i][9]*b.a[9][1];
        c.a[i][0]%=mod;
        c.a[i][1]%=mod;
    }
    
    return c;
}
matrix f_pow(matrix a,int m){
    matrix res,tmp=a;
    for(int i = 0;i<10;i++)res.a[i][i]=1;
    while(m){
        if(m&1)res=res*tmp;
        tmp=tmp*tmp;
        m>>=1;
    }
    return res;
}
matrix res[200005];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    int cnt[10];
    fill(cnt,cnt+10,0);
    while(n){
        cnt[n%10]++;
        n/=10;
    }
    LL ans=0;
    for(int i = 0;i<10;i++){
        for(int j = 0;j<10;j++)ans+=res[m].a[i][j]*cnt[i];
    }
    printf("%lld\n",ans%mod);
    /*matrix a;
    for(int i = 0;i<9;i++)a.a[i][i+1]=1;
    a.a[9][0]=a.a[9][1]=1;
    a=f_pow(a,m);*/

}
int main(){
    matrix a; 
    for(int i = 0;i<9;i++)a.a[i][i+1]=1;
    a.a[9][0]=a.a[9][1]=1;
    for(int i = 0;i<10;i++)res[0].a[i][i]=1;
    for(int i = 1;i<=200000;i++){
       // for(int j = 0;j<10;j++){
            //for(int k = 0;k<10;k++){
            //    res[i].a[j][k]
           // }
            res[i]=res[i-1]*a;
        //}
    }
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}