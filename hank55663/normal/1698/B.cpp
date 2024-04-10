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
#define double long double
using namespace std;
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    int a[200005];
    vector<int> v;
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i = 1;i<n-1;i++){
        v.pb(((a[i+1]+a[i-1])-a[i]));
    }
    sort(v.begin(),v.end());
    int ans=0;
    for(auto it:v){
        if(it<0)ans++;
    }
    if(k==1){
        printf("%d\n",((n-1)/2));
    }
    else
    printf("%d\n",ans);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
p*t = a^2+b^2
q*t = ab
(p+2*q)*t=(a+b)^2
*/