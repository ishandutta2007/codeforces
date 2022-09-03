#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define N 700005
void solve(){
    int n,L;
    scanf("%d %d",&n,&L);
    int a[100005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    a[n+1]=L;
    a[0]=0;
    double Max=1e9,Min=0;
    for(int i = 0;i<100;i++){
        double mid=(Max+Min)/2;
        double l=0;
        double tmp=mid;
        int last=0;
        for(int j=1;j<=n+1;j++){
            double go=min(tmp,(a[j]-last)*1.0/j);
            tmp-=go;
            l+=go*j;
            last=a[j];

            if(abs(tmp)<=1e-8)break;
        }
        double r=0;
        tmp=mid;
        last=L;
        for(int j = n;j>=0;j--){
            double go=min(tmp,(last-a[j])*1.0/(n-j+1));
            tmp-=go;
            r+=go*(n-j+1);
            last=a[j];
            if(abs(tmp)<=1e-8)break;
        }
        //printf("%f %f %f\n",mid,l,r);
        if(l+r>=L)Max=mid;
        else Min=mid;
    }
    printf("%.12f\n",Max);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        //cout<<"Case "<<T++<<":\n";
        solve();
    }
}
/*
1 6 6
2 7 4
3 5 2
4 3 1
5 2 5
6 4 0
7 1 3
*/
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/