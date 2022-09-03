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
#define MXN 10005
#define less Less
int tot[100005];
int main(){
    MEMS(tot);
    int n;
    scanf("%d",&n);
    char c[200005];
    int sum=0;
    scanf("%s",c);
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='1')sum++;
    }
    int ans=0;
    if(sum==0)ans++;
    for(int i = 1;i<n;i++){
        int x=__gcd(i,n);
        if(tot[x]==-1){
            vector<int> v(x);
            for(int j=0;c[j]!=0;j++){
                if(c[j]=='1')
                    v[j%x]++;
            }
            int ok=1;
            for(auto it:v){
                if(it&1)
                ok=0;
            }
            tot[x]=ok;
        }
        ans+=tot[x];
    }
    printf("%d\n",ans);
}