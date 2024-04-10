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
#define MXN 205
int S[400005];
void add(int x,int k){
    for(int i = x ; i < 400005 ; i+=i&-i){
        S[i]+=k;
    }
}
int query(int x){
    int res=0;
    for(int i = x ; i > 0 ;i-=i&-i){
        res+=S[i];
    }
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    int a[200005],b[200005];
    for(int i = 1;i<=n;i++)scanf("%d",&a[i]);
    for(int i = 1;i<=n;i++)scanf("%d",&b[i]);
    for(int i = 1;i<=n;i++){
        a[i]-=b[i];
     //   printf("%d ",a[i]);
    }
    //printf("\n");
    map<int,int> m;
    for(int i = 1;i<=n;i++){
        m[a[i]];
        m[-a[i]];
    }
    int index=0;
    for(auto &it:m){
        it.y=++index;
    }    
    LL res=0;
    for(int i =n;i>=1;i--){
        res+=query(m[a[i]]-1);
        add(m[-a[i]],1);
        
    }
    printf("%lld\n",res);
}
/*
4+3+3+4+3+2+2+1
*/