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
using namespace std;
void solve(){
    int n,x;
    scanf("%d %d",&n,&x);
    int a[200005];
    for(int i = 0;i<n;i++){
        scanf("%d",&a[i]);
    }
 //   sort(a,a+n);
    int now=a[0];
    int ans=0;
    set<int> s;
    for(int i = 0;i<n;i++){
        s.insert(a[i]);
        if(*s.rbegin()-*s.begin()>2*x){
            ans++;
            s.clear();
            s.insert(a[i]);
        }
    }
    //reverse(a,a+n);
    printf("%d\n",ans);
}
int main(){
    int t=1;00000000;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    
}
/*
*/