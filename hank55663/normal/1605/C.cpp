#include<bits/stdc++.h>
#pragma optimize(Ofast)
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<LL,LL>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
const int mod=998244353;
void solve(){
    int n;
    scanf("%d",&n);
    char c[1000005];
    scanf("%s",c);
    vector<int> v;
    for(int i=0;c[i]!=0;i++){
        if(c[i]=='a')v.pb(i);
    }
    int Max=1e9;
    for(int i = 0;i+1<v.size();i++){
        if(v[i+1]-v[i]==1)Max=2;
        else  if(v[i+1]-v[i]==2)Max=min(Max,3);
        else if(v[i+1]-v[i]==3){
            if(c[v[i]+1]!=c[v[i]+2])Max=min(Max,4);
            else if(i+2<v.size()&&v[i+2]-v[i+1]==3&&c[v[i+1]+1]!=c[v[i+1]-1])Max=min(Max,7);
        }
    }
    if(Max==1e9)Max=-1;
    printf("%d\n",Max);
    
}
int main(){

    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
       // cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/