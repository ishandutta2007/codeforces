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
        int odd=0,even=0;
        int n,x;
        scanf("%d %d",&n,&x);
        for(int i = 0;i<n;i++){
            int a;
            scanf("%d",&a);
            if(a&1)odd++;
            else even++;
        }
        if(odd&&even){
            if(n==x){
                if(odd&1){
                    printf("Yes\n");
                }
                else{
                    printf("No\n");
                }
            }
            else
            printf("Yes\n");
        }
        else{
            if(x%2==1&&odd){
                printf("Yes\n");
            }
            else{
                printf("No\n");
            }
        }
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