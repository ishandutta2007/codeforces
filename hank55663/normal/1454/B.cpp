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
#define next Next
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    set<int> s;
    map<int,int> m;
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        if(s.find(x)==s.end()){
            s.insert(x);
            m[x]=i;
        }
        else{
            if(m.find(x)!=m.end())m.erase(x);
        }
    }
    if(m.empty())printf("-1\n");
    else printf("%d\n",m.begin()->y);
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}