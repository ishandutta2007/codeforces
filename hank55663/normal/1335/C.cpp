#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<long double,long double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acosl(-1)
//#define N 524288
#define ld long double
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        map<int,int> m;
        for(int i =0;i<n;i++){
            int x;
            scanf("%d",&x);
            m[x]++;
        }
        int Max=0;
        for(auto it:m){
            Max=max(Max,it.y);
        }
        int ans=max(min((int)m.size()-1,Max),min((int)m.size(),Max-1));
        printf("%d\n",ans);
    }

}
/*
00 00
01 10
10 11
11 01
2 1 3 0 2
3 1 3 0 2
3 2 3 0 2
3 2 4 0 2
3 2 4 1 2
3 2 4 1 3
*/