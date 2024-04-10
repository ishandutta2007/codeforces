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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 1500

int main(){
    int q;
    scanf("%d",&q);
    while(q--){
        int n,r;
        scanf("%d %d",&n,&r);
        int x[100005];
        for(int i=0;i<n;i++)scanf("%d",&x[i]);
        sort(x,x+n);
        vector<int> tmp;
        for(int i= 0;i<n;i++){
            if(i!=0&&x[i]==x[i-1])continue;
            tmp.pb(x[i]);
        }
        int ans=0;
        reverse(tmp.begin(),tmp.end());
        for(auto it:tmp){
            if(it<=r*ans)break;
            ans++;
        }
        printf("%d\n",ans);
    }
}