#include<bits/stdc++.h>
#pragma optimize(Ofast)
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
#define MXN 500005
vector<string> v;
int val[1000005];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<n;i++){
        char c[1000005];
        scanf("%s",c);
        v.pb(string(c));
    }
    for(int i=0;i<n-1;i++){
        for(int j = 0;j<m-1;j++){
            if(v[i+1][j]=='X'&&v[i][j+1]=='X'){
                val[j+1]++;
                //printf("%d %\n",i);
            }
        }
    }
    for(int i = 1;i<=m;i++)val[i]+=val[i-1];
    int q;
    scanf("%d",&q);
    while(q--){
        int l,r;
        scanf("%d %d",&l,&r);
        if(val[r-1]-val[l-1])printf("NO\n");
        else printf("YES\n");
    }
}
int main(){
    int t=1;0000;
 //   scanf("%d",&t);
    for(int i = 1;i<=t;i++){
       // cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
[[([(([([([
1 8
3 4
1 8
2 7
5 6
*/