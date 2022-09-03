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
#define rank Rank
#define index Index
struct matrix{
    int n;
    LL a[20][20];
    matrix(int _n){
        n=_n;
        MEM(a);
        for(int i = 0;i<n;i++)
            a[i][i]=1;
    }
};
int mod=1e9+7;
matrix operator*(const matrix &a,const matrix &b){
    matrix c(a.n);
    MEM(c.a);
    for(int i = 0;i<a.n;i++){
        for(int j = 0;j<a.n;j++){
            for(int k = 0;k<a.n;k++){
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
void print(matrix &m){
    for(int i = 0;i<m.n;i++){
        for(int j=0;j<m.n;j++){
            printf("%lld ",m.a[i][j]);
        }
        printf("\n");
    }
}
int main(){
    LL n,k;
    scanf("%lld %lld",&n,&k);
    pair<pll,LL> p[105];
    for(int i =0;i<n;i++){
        LL a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        p[i]=mp(mp(a,b),c);
    }
    p[n-1].x.y=k;
    LL now[16];
    MEM(now);
    now[0]=1;
    for(int i = 0;i<n;i++){
        LL len=p[i].x.y-p[i].x.x;
        LL c=p[i].y;
        matrix m(c+1);
        for(int i = 0;i<c;i++){
            m.a[i][i+1]=1;
            m.a[i+1][i]=1;
        }
       // print(m);
        matrix res=f_pow(m,len);
        //print(res);
        LL temp[16];
        MEM(temp);
        for(int j=0;j<=c;j++){
            for(int k = 0;k<=c;k++){
                temp[j]+=res.a[j][k]*now[k];
                temp[j]%=mod;
            }
        }
        MEM(now);
        for(int j =0;j<=c;j++)
        now[j]=temp[j];
    }
    printf("%lld\n",now[0]);
}

/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
11010101
*/