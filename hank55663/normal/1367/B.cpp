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
    int even=0,odd=0;
    for(int i = 0;i<n;i++){
        int a;
        scanf("%d",&a);
        if((a&1)!=(i&1)){
            if(a&1)odd++;
            else even++;
        }
    }
    if(odd!=even){
        printf("-1\n");
    }
    else{
        printf("%d\n",odd);
    }
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