#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<__float128,__float128>
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
    char c[200005];
    scanf("%s",c);
    int n=strlen(c);
    vector<char> ans,tmp;
    int vis[26];
    MEM(vis);
    for(int i = n-1;i>=0;i--){
        tmp.pb(c[i]);
        if(!vis[c[i]-'a']){
            for(auto it:tmp)ans.pb(it);
            tmp.clear();
            vis[c[i]-'a']=1;
        }
    }
    reverse(ans.begin(),ans.end());
    for(auto it:ans)
    printf("%c",it);
    printf("\n");
}


int main(){
    int t=1;
  scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*

*/