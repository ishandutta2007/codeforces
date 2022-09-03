#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define pll pair<LL,LL>
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
using namespace std;
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    pii p[205];
    int ok=0;
    for(int i = 0;i<n;i++){
        int x,y,x2,y2;
        scanf("%d %d %d %d",&x,&y,&x2,&y2);
        if(y==x2)ok=1;
    }
    if(m%2){
        printf("NO\n");
    }
    else{
        if(ok)printf("YES\n");
        else printf("NO\n");
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
       // printf("Case #%d: ",T++);
        solve();
    }
}