/**
 *    author:  gary
 *    created: 11.11.2021 17:38:36
**/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
int s[2][1<<14];
char c[1<<12|1];
int fa[1<<15];
int root(int x){
    return fa[x]=(fa[x]==x? x:root(fa[x]));
}
int main(){
    int n,m;
    cin>>n>>m;
    rep(i,m*2) fa[i]=i;
    int cnt=0;
    rep(j,m) s[0][j]=0;
    rb(i,1,n){
        scanf("%s",c);
        rep(j,m/4){
            int num=(c[j]<='9'&&c[j]>='0'? (c[j]^48):10+(c[j]-'A'));
            s[i&1][j<<2]=num>>3;
            s[i&1][j<<2|1]=(num>>2)&1;
            s[i&1][j<<2|2]=(num>>1)&1;
            s[i&1][j<<2|3]=num&1;
        }
        rep(j,m){
            fa[j*2+(i&1)]=j*2+(i&1);
        }
        rep(j,m){
            if(s[i&1][j]&&s[(i&1)^1][j]){
                fa[root(j*2+((i&1)^1))]=root(j*2+(i&1));
            }
            if(j&&s[i&1][j]&&s[i&1][j-1]){
                fa[root(j*2+(i&1))]=root(j*2-2+(i&1));
            }
        }
        rep(j,m) if(s[(i&1)^1][j]&&root(j*2+((i&1)^1))==j*2+((i&1)^1)) cnt++;
    }
    rep(j,m) if(s[(n&1)][j]&&root(j*2+((n&1)))==j*2+((n&1))) cnt++;
    cout<<cnt<<endl;
    return 0;
}