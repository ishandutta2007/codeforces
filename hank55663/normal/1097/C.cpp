
#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
int main(){
    int n;
    scanf("%d",&n);
    char c[500005];
    map<int,int> l,r;
    int zero=0;
    for(int i=0;i<n;i++){
        scanf("%s",c);
        int cnt=0;
        int ok=1;
        for(int j=0;c[j]!=0;j++){
            if(c[j]==')'){
                cnt--;
            }
            else{
                cnt++;
            }
            if(cnt<0){
                ok=0;
                break;
            }
        }
        if(cnt==0){
            zero++;
            continue;
        }
        if(ok)
        l[cnt]++;
        cnt=0;
        int len=strlen(c);
        ok=1;
        for(int j=len-1;j>=0;j--){
            if(c[j]=='('){
                cnt--;
            }
            else{
                cnt++;
            }
            if(cnt<0){
                ok=0;
                break;
            }
        }
        if(ok)
        r[cnt]++;
    }
    int ans=zero/2;
    for(auto it:l){
        ans+=min(it.y,r[it.x]);
    }
    printf("%d\n",ans);
}