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
    int n,x;
    scanf("%d %d",&n,&x);
    if(n<=2){
        printf("1\n");
    }
    else{
        int now=2;
        n-=2;
        while(true){
            if(n<=x)break;
            n-=x;
            now++;
        }
        printf("%d\n",now);
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