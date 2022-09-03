#include<bits/stdc++.h>
#define mp make_pair
#define x first
#define y second
#define pll pair<LL,LL>
#define pii pair<int,int>
#define LL long long
#define pb push_back
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-7
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        int ans=n;
        for(int i = 1;i*i<=n;i++){
            if(n%i==0){
                if(i<=k)ans=min(ans,n/i);
                if(n/i<=k)ans=min(ans,i);
            }
        }
        printf("%d\n",ans);
    }
}
/*
2 11 14
9 3
0 1 2 3
0 1 2 3
0 1 2 3
0 1 2 3
0 1 2 3
3**5+3**5-2**5
000111222
001112220
*/