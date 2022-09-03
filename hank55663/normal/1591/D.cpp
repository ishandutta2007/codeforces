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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
int S[500005];
void add(int x,int k){
    for(int i = x;i<500005;i+=i&-i){
        S[i]+=k;
    }
}
int query(int x){
    int res=0;
    for(int i = x;i>0;i-=i&-i){
        res+=S[i];
    }
    return res;
}
void solve(){
    int n;
    scanf("%d",&n);
    int a[500005];
    set<int> s;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    int sum=0;
    for(int i = n;i>=1;i--){
        s.insert(a[i]);
        sum+=query(a[i]-1);
        add(a[i],1);
    }
    for(int i = 1;i<=n;i++)add(a[i],-1);
    if(sum%2&&s.size()==n)printf("NO\n");
    else printf("YES\n");
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/