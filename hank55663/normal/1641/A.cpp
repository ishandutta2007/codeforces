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
void solve(){
    int n,x;
    scanf("%d %d",&n,&x);
    LL a[200005];
    for(int i = 0;i<n;i++)scanf("%lld",&a[i]);
    sort(a,a+n);
    multiset<int> s;
    for(int i = 0;i<n;i++){
        if(a[i]%x==0){
            if(s.find(a[i]/x)!=s.end())s.erase(s.find(a[i]/x));
            else s.insert(a[i]);
        }
        else{
            s.insert(a[i]);
        }
    }
    printf("%d\n",s.size());
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}