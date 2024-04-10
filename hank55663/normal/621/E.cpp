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
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
#define N 1000000
struct matrix{
    LL a[105][105];
    int n;
    matrix(){
        MEM(a);
    }
};
int mod=1e9+7;
matrix operator*(const matrix &a,const matrix &b){
    matrix c;
    c.n=a.n;
    for(int i = 0;i<a.n;i++){
        for(int j = 0;j<a.n;j++){
            for(int k =0;k<a.n;k++){
                c.a[i][j]+=a.a[i][k]*b.a[k][j];
                c.a[i][j]%=mod;
            }
        }
    }
    return c;
}
matrix f_pow(matrix a,int b){
    matrix res,tmp=a;
    res.n=a.n;
    for(int i = 0;i<a.n;i++)res.a[i][i]=1;
    while(b){
        if(b&1)res=res*tmp;
        tmp=tmp*tmp;
        b>>=1;
    }
    return res;
}
bool solve(){
    int n,b,k,x;
    scanf("%d %d %d %d",&n,&b,&k,&x);
    int cnt[10];
    MEM(cnt);
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        cnt[x]++;
    }
    matrix a;
    a.n=x;
    for(int i = 0;i<x;i++){
        for(int j=0;j<10;j++){
            a.a[i][(i*10+j)%x]+=cnt[j];
        }
    }
    matrix res=f_pow(a,b);
    printf("%lld\n",res.a[0][k]);
    return true;
}
int main(){
    int t=1;00000;
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/