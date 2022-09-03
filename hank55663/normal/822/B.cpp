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
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    char s[1005],t[1005];
    scanf("%s %s",s,t);
    int ans=1e9;
    vector<int> vvv;
    for(int i = 0;i<=m-n;i++){
        int res=0;
        vector<int> vv;
        for(int j =0;s[j]!=0;j++)
            if(s[j]!=t[i+j])res++,vv.pb(j+1);
        if(res<ans){
            ans=min(ans,res);
            vvv=vv;
        }
    }
    printf("%d\n",ans);
    for(auto it:vvv)
    printf("%d ",it);
    printf("\n");
}

/*
230
0.5 0.5
0.5 0.25
0.25 0.125
0.25
*/