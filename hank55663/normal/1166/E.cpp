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
    int m,n;
    scanf("%d %d",&m,&n);
    vector<int> v[55];
    for(int i = 0;i<m;i++){
        int k;
        scanf("%d",&k);
        while(k--){
            int x;
            scanf("%d",&x);
            v[i].pb(x);
        }
    }
    int cnt[10005];
    for(int i = 0;i<m;i++){
        fill(cnt,cnt+n,0);
        for(auto it:v[i]){
            cnt[it]=1;
        }
        for(int j = i+1;j<m;j++){
            int ok=0;
            for(auto it:v[j]){
                if(cnt[it]){
                    ok=1;
                    break;
                }
            }
            if(!ok){
                printf("impossible\n");
                return 0;
            }
        }
    }
    printf("possible\n");
    
}