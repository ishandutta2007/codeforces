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
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    char c[200005];
    scanf("%s",c);
    int cnt[26];
    MEM(cnt);
    for(int i = 0;c[i]!=0;i++){
        cnt[c[i]-'a']++;
    }
    int a=0,b=0;
    for(int i = 0;i<26;i++){
        if(cnt[i]%2)b++;
        a+=cnt[i]/2;
    }
    int ans=a/k*2+(b>=k);
    while(b<k){
        b+=2;
        a--;
    }
    ans=max(ans,a/k*2+1);
    printf("%d\n",ans);
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}