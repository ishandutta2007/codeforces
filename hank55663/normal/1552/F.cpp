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
LL S[500005];
LL mod=998244353;
void add(int x,LL k){
    for(int i = x;i<500005;i+=i&-i){
        S[i]+=k;
        S[i]%mod;
    }
}
LL query(int x){
    LL res=0;
    for(int i = x;i>0;i-=i&-i){
        res+=S[i];
        res%=mod;
    }
    return res;
}
void solve(){
    int n;
    scanf("%d",&n);
    pii p[200005];
    int s[200005];
    map<int,int> m;
    for(int i = 0;i<n;i++){
        int x,y;
        scanf("%d %d %d",&x,&y,&s[i]);
        p[i]=mp(x,y);
        m[x];
        m[y];
    }
    int index=0;
    for(auto &it:m){
        it.y=++index;
    }
    LL ans=(p[n-1].x+1)%mod;
    for(int i = 0;i<n;i++){
        LL val=((query(m[p[i].x])-query(m[p[i].y])+p[i].x-p[i].y)%mod+mod)%mod;
       // printf("%lld\n",val);
        if(s[i])ans+=val,ans%=mod;
        add(m[p[i].x],val);
       // printf("%d %d\n",m[p[i].x],m[p[i].y]);
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;
//    scanf("%d",&t);
    while(t--){
        solve();
    }
    //printf("8192\n");
    //printf("%d\n",cnt);
    //printf("%.12f\n",sum/tt);
    return 0;
}
/*
0 1 1 1
3 3 3 4 4 4 5 5 5 6 6 6
3 3 7 3 25
x^2+y^2=kxy+k;
64+y^2=32y+4;
y^2-32y+60=0;

x^2-k*y*x-k+y*y=0;
a=1;
b=-k*y;
c=y*y-k
x=ky+-sqrt(k*k*y*y+4*k-4*y*y) 
*/