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
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 300005
#define next Next
#define index Index
int main(){
    int n;
    scanf("%d",&n);
    vector<int> ans;
    char c[105];
    int cnt=0;
    scanf("%s",c);
    for(int i =0;c[i]!=0;i++){
        if(c[i]=='B'){
            cnt++;
        }
        else{
            if(cnt)ans.pb(cnt);
            cnt=0;
        }
    }
    if(cnt)
        ans.pb(cnt);
    printf("%d\n",ans.size());
    for(auto it:ans)
        printf("%d ",it);
    printf("\n");
}
/*

100
2 3
0 500000000 1000000000
1000000000 1000000000 1000000000
 */