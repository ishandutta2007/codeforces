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
int factor[2000005];
bool solve(){
    int n;
    scanf("%d",&n);
    int a[300005];
    map<int,LL> m;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
        int now=a[i];
        map<int,int> mm;
        while(now!=1){
            mm[factor[now]]++;
            now/=factor[now];
        }
        LL tot=1;
        for(auto it:mm){
            if(it.y%2==1)tot*=it.x;
        }
        m[tot]++;
    }
    LL Max1=0;
    for(auto it:m){
        Max1=max(Max1,it.y);
    }
    LL sum2=0,Max2=0;
    for(auto it:m){
        if(it.y%2==0||it.x==1)sum2+=it.y;
        else Max2=max(Max2,it.y);
    }
    int q;
    scanf("%d",&q);
    while(q--){
        LL w;
        scanf("%lld",&w);
        if(w==0)printf("%lld\n",Max1);
        else printf("%lld\n",max(sum2,Max2));
    }
    return true;
}
int main(){
    for(int i = 2;i<=2000000;i++){
        for(int j = i;j<=2000000;j+=i){
            if(factor[j]==0)factor[j]=i;
        }
    }
    int t=1;00000;
    scanf("%d",&t);
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