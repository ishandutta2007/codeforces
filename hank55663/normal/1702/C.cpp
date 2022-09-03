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
map<int,vector<int>> v;
void solve(){  
    int n,k;
    scanf("%d %d",&n,&k);
    v.clear();
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        v[x].pb(i);
    }
    while(k--){
        int a,b;
        scanf("%d %d",&a,&b);
        if(v.find(a)!=v.end()&&v.find(b)!=v.end()&&v[a][0]<v[b].back()){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    //printf("\"");
    while(t--){
        // cerr<<t<<endl;
        solve();
     //   cerr<<t<<endl;
    }
    
   // cerr<<cnt<<endl;
}
/*
*/