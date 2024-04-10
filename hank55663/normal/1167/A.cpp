#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        char c[1005];
        scanf("%s",c);
        if(n<11){
            printf("NO\n");
        }
        else{
            int ok=0;
            for(int i = 0;i<=n-11;i++){
                if(c[i]=='8'){
                    printf("YES\n");
                    ok=1;
                    break;
                }
            }
            if(!ok){
                printf("NO\n");
            }
        }
    }
}