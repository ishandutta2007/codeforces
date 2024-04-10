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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define index Index
const int mod=1e9+7;
int S[100005];
void add(int x,int k){
    for(int i = x;i<100005;i+=i&-i){
        S[i]+=k;
    }
}
int query(int x){
    int res=0;
    for(int i = x;i>0;i-=i&-i){
        res+=S[i];
    }
    return res;
}
queue<int> q[26];
void solve(){
    int n;
    scanf("%d",&n);
    char s[100005],t[100005];
    scanf("%s %s",s+1,t+1);
    for(int i = 1;s[i]!=0;i++)q[s[i]-'a'].push(i),add(i,1);
    LL ans=1e18;
    LL sum=0;
    for(int i = 1;t[i]!=0;i++){
        int Min=1e9;
        for(int j = 0;j<t[i]-'a';j++){
            if(q[j].size())Min=min(Min,q[j].front());
        }
        //printf("%lld\n",sum);
        if(Min!=1e9){
          //  printf("!%lld\n",sum+query(Min-1));
            ans=min(ans,sum+query(Min-1));
        }
        if(q[t[i]-'a'].size()){
            sum+=query(q[t[i]-'a'].front()-1);
            add(q[t[i]-'a'].front(),-1);
            q[t[i]-'a'].pop();
        }
        else{
            break;
        }

    }
    if(ans==1e18)printf("-1\n");
    else printf("%lld\n",ans);
    for(int i = 0;i<26;i++){
        while(q[i].size()){
            add(q[i].front(),-1);
            q[i].pop();
        }
    }
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/