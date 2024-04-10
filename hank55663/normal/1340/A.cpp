#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
#define N 65536
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int a[100005];
        int n;
        scanf("%d",&n);
        for(int i = 0;i<n;i++){
            scanf("%d",&a[i]);
        }
        reverse(a,a+n);
        vector<int> stk;
        int now=1;
        int ok=1;
        for(int i = 0;i<n;i++){
            if(now<=a[i]){
                if(stk.size()){
                    ok=0;
                    break;
                }
                while(now<=a[i]){
                    stk.pb(now);
                    now++;
                }
            }
            if(stk.back()==a[i])stk.pop_back();
            else{
                ok=0;
                break;
            }
        }
        if(ok)printf("Yes\n");
        else printf("No\n");
    }
}

/*

3 2 +2
3 1 +1
2 1 +1
3 1 +1
2 1 +1

*/
/*
5 5
1 1 1 2 2
1 2 100
2 3 100
3 4 1
4 5 1
5 1 100
3
1 3 1 0
1 3 2 0
1 3 1 1

200
102
102
*/