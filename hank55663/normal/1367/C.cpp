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
    int cnt=k;
    char c[200005];
    scanf("%s",c);
    int ans=0;
    for(int i = 0;i<n;i++){
        if(c[i]=='0'){
            cnt++;
        }
        else{
            ans+=(cnt-k)/(k+1);
            cnt=0;
        }
    }
    cnt+=k;
    ans+=(cnt-k)/(k+1);
    printf("%d\n",ans);
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