#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    char c[55][55];
    vector<int> dig,en,sym;
    for(int i = 0;i<n;i++){
        scanf("%s",c[i]);
        int d=1e8,e=1e8,s=1e8;
        for(int j = 0;j<m;j++){
            if(c[i][j]>='0'&&c[i][j]<='9'){
                d=min(d,min(j,m-j));
            }
            else if(c[i][j]>='a'&&c[i][j]<='z'){
                e=min(e,min(j,m-j));
            }
            else{
                s=min(s,min(j,m-j));
            }
        }
        dig.pb(d);
        en.pb(e);
        sym.pb(s);
    }
    int ans=1e8;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k = 0;k<n;k++){
                if(i!=j&&j!=k&&i!=k){
                    ans=min(ans,dig[i]+en[j]+sym[k]);
                }
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}