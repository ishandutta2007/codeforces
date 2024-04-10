#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    char c[200005];
    scanf("%s",c);
    vector<int> v;
    for(int i = 0;c[i]!=0;i++){
        if(c[i]=='A'){
            v.pb(1);
        }
        else if(c[i]=='B'){
            if(v.size()&&v.back()==1)v.pop_back();
            else v.pb(0);
        }
    }
    int cnt=0;
    for(auto it:v)if(it==0)cnt++;
    printf("%d\n",v.size()-cnt/2*2);
}



int main(){
    int t=1;
    scanf("%d",&t);
   
    while(t--){
        solve();
    }
}
/*
5 0 5
10 0
-10 0
-20 10
0 30
20 10
*/