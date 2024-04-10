#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<__float128,__float128>
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
void solve(){
    int n,k;
    scanf("%d %d",&n,&k);
    LL sum=0;
    int a[200005];
    set<int> s;
    int ok=0;
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        if(s.find(k+a[i])!=s.end())ok=1;
        if(s.find(a[i]-k)!=s.end())ok=1;
        s.insert(a[i]);
    }
    if(ok)printf("yes\n");
    else printf("no\n");
}


int main(){
    int t=10000;
  scanf("%d",&t);
    while(t--){
        solve();
    }
}
/*

*/