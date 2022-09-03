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
    int n,k;
    scanf("%d %d",&n,&k);
    int cnt[26];
    fill(cnt,cnt+26,0);
    char c[2005];
    scanf("%s",c);
    for(int i = 0;i<n;i++){
        cnt[c[i]-'a']++;
    }
    LL ans=0;
    for(int i = 1;i<=k;i++){
        if(k%i==0){
            vector<LL> v;
            for(int a = 0;a<26;a++){
                for(int j = 1;j<=i;j++){
                    if(cnt[a]/j)
                    v.pb(cnt[a]/j);
                }
            }
            sort(v.begin(),v.end());
            reverse(v.begin(),v.end());
            if(v.size()>=i)
            ans=max(ans,v[i-1]*i);
        }
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