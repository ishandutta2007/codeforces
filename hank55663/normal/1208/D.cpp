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
#define pdd pair<double,double>
#define cpdd const pdd
LL S[1<<20];
void add(int x,int k){
    for(int i = x;i<(1<<20);i+=i&-i){
        S[i]+=k;
    }
}
int query(LL q){
    LL sum=0,now=0;
    for(int i = 19;i>=0;i--){
        if(sum+S[now+(1<<i)]<=q){
            now+=(1<<i);
            sum+=S[now];
        }
    }
    return now;
}
int main(){
    int n;
    scanf("%d",&n);
    LL s[200005];
    for(int i = 0;i<n;i++){
        scanf("%lld",&s[i]);
    }
    for(int i=1;i<=n;i++){
        add(i,i);
    }
    
    int ans[200005];
    for(int i = n-1;i>=0;i--){
        ans[i]=query(s[i])+1;
        add(ans[i],-ans[i]);
    }
    for(int i = 0;i<n;i++)
        printf("%d ",ans[i]);
    printf("\n");
}