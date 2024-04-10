#include <bits/stdc++.h>
#define LL long long
#define pb push_back
#define x first
#define y second
#define mp make_pair
#define pii pair<int,int>
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
int main(){
    vector<pii> v[200005];
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i = 0;i<n;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        v[l].pb(mp(r,i+1));
    }
    vector<int> res;
    set<pii> s;
    for(int i = 0;i<=200000;i++){
        for(auto it:v[i])
            s.insert(it);
        while(!s.empty()&&s.begin()->x<i){
            s.erase(s.begin());
        }
        while(s.size()>k){
            res.pb(s.rbegin()->y);
            s.erase(*s.rbegin());
        }
    }
    printf("%d\n",res.size());
    for(auto it:res)
    printf("%d ",it);
    printf("\n");
}