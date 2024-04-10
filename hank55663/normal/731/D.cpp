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
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-3
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
int pre[1000005];
int main() {
    int n,c;
    scanf("%d %d",&n,&c);
    vector<vector<int> > v;
    for(int i = 0;i<n;i++){
        vector<int> tmp;
        int k;
        scanf("%d",&k);
        while(k--){
            int x;
            scanf("%d",&x);
            tmp.pb(x);
        }
        v.pb(tmp);
    }
    int l=0,r=c-1;
    for(int i = 0;i<n-1;i++){
        int find=0;
        for(int j = 0;j<v[i].size();j++){
            if(v[i+1].size()<=j){
                printf("-1\n");
                return 0;
            }
            if(v[i][j]!=v[i+1][j]){
                int rr=c-v[i+1][j];
                int ll=c+1-v[i][j];
                find=1;
                if(ll<=rr){
                    pre[ll]++;
                    pre[rr+1]--;
                }
                else{
                    pre[1]++;
                    pre[rr+1]--;
                    pre[ll]++;
                    pre[c]--;
                }
                break;
            }
        }
       // printf("%d\n",find);
        if(!find){
            pre[0]++;
            pre[c]--;
        }
    }
    int sum=0;
    for(int i=0;i<c;i++){
        //printf("%d ",pre[i]);
        sum+=pre[i];
         if(sum==n-1){
            printf("%d\n",i);
            return 0;
        }
    }
    printf("-1\n");
    return 0;
}