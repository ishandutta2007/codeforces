#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define double long double
using namespace std;
int Max[5000005];
LL tot=0;
multiset<int> s[100005];
vector<int> q[5000005];
void go(int now,int sum,int st){
  //  m[sum][st]=min(m[sum][st],now);

    if(now<Max[sum]){
        if(st>100)
        for(auto it:q[sum])s[it].erase(s[it].find(Max[sum]));
        Max[sum]=now;
            tot++;
        if(st>100)
        for(auto it:q[sum])s[it].insert(Max[sum]);
    }
    //m[sum].pb(mp(st,now));
    for(LL i = now;i*sum<=5000000;i++){
        go(i,sum*i,st);
    }
}
void solve(){
}
int ans[100005];
vector<int> ggo[5000005];
vector<int> v[100005];
int isprime[5000005];
int main(){
    int t=1;00000;
    scanf("%d",&t);
    for(int i = 1;i<=5000000;i++){
        Max[i]=i;
    }
    for(int i = 2;i<=5000000;i++){
        if(!isprime[i]){
            for(int j = i;j<=5000000;j+=i){
                isprime[j]=i;
            }
        }
    }
    for(int i = 1;i<=t;i++){
        int n=10000,m=50000;
        scanf("%d %d",&n,&m);
        for(int j = 0;j<n;j++){
            int x;
            scanf("%d",&x);
           // x=rand()%m+1;
            v[i].pb(x);
        }
        sort(v[i].begin(),v[i].end());
        v[i].resize(unique(v[i].begin(),v[i].end())-v[i].begin());
        ggo[v[i][0]].pb(i);
        int MMax=1;
        for(auto it:v[i]){
            q[it].pb(i);
            s[i].insert(it);
            MMax=max(MMax,isprime[it]);
        }
        //printf("%d\n",MMax);
        ans[i]=MMax-min(v[i][0],2);
    }

    vector<int> aa;
    for(int i = 5000000;i>=3;i--){
        go(i,i,i);
        for(auto it:ggo[i])aa.pb(it);
        if(i>100){
        for(auto it:aa){
           // printf("%d %d %d\n",it,i,*s[it].rbegin());
            ans[it]=min(ans[it],*s[it].rbegin()-i);
        }
        }
        else{
            for(int j = 1;j<=t;j++){
                int MMax=0;
                for(auto it:v[j])MMax=max(MMax,Max[it]);
                if(v[j][0]>=i){
                    ans[j]=min(ans[j],MMax-i);
                }
            }
        }

    }
  
    for(int i = 1;i<=t;i++){
        ans[i]=min(ans[i],*s[i].rbegin()-1);
        printf("%d\n",ans[i]);
    }
    return 0;
}
/*
p*t = a^2+b^2
q*t = ab
(p+2*q)*t=(a+b)^2
*/