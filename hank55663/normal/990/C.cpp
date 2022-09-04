#include<bits/stdc++.h>
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
using namespace std;
typedef long long LL;
int main(){
    int n;
    scanf("%d",&n);
    map<int,int> m;
    vector<int> v;
    int other=0;
    char c[300005];
    for(int i=0;i<n;i++){
        int num=0;
        int cnt=0;
        scanf("%s",c);
        for(int j=0;c[j]!=0;j++){
            if(c[j]==')'){
                if(!cnt)
                num++;
                else
                cnt--;
            }
            else{
                cnt++;
            }
        }
        if(!num&&!cnt){
            other++;
        }
        if(!num&&cnt){
            v.pb(cnt);
        }
        if(num&&!cnt){
            m[num]++;
        }
    }
    LL ans=(LL)other*other;
    for(auto it:v)
    ans+=m[it];
    printf("%lld\n",ans);
}