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
        int n;
        scanf("%d",&n);
        int a[55];
        for(int i = 0;i<n;i++)scanf("%d",&a[i]);
        sort(a,a+n);
        int ans=1e9;
        for(int i = 0;i<n-1;i++){
            ans=min(ans,a[i+1]-a[i]);
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