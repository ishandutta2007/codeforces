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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
#define N 262144
vector<int> v[200005];
int main(){
    for(int i = 2;i<200005;i++){
        if(v[i].empty()){
            for(int j=i;j<200005;j+=i){
                v[j].pb(i);
            }
        }
    }
    int n;
    scanf("%d",&n);
    map<int,vector<int> > m;
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        int tmp=x;
        for(auto it:v[x]){
            int cnt=0;
            while(tmp%it==0){
                cnt++;
                tmp/=it;
            }
            m[it].pb(cnt);
        }
    }
    LL ans=1;
    for(auto &it:m){
        sort(it.y.begin(),it.y.end());
        if(it.y.size()==n){
            for(int i=0;i<it.y[1];i++)ans*=it.x;
        }
        else if(it.y.size()==n-1){
            for(int i = 0;i<it.y[0];i++)ans*=it.x;
        }
    }
    printf("%lld\n",ans);
}