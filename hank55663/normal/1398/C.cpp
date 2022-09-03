#include<bits/stdc++.h>
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
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    map<int,int> m;
    char c[100005];
    scanf("%s",c+1);
    m[0]=1;
    int sum=0;
    LL ans=0;
    for(int i = 1;c[i]!=0;i++){
        sum+=c[i]-'0';
        ans+=m[sum-i];
        m[sum-i]++;
       // printf("%d\n",sum-i);
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*
100
5
5 4
4 2
4 2 3
5 4 2 3 1
*/