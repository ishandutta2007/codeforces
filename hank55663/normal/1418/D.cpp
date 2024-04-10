#include<bits/stdc++.h>
#define LL long long
#define pb push_back
#define pll pair<LL,LL>
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
using namespace std;
int mod=1e9+7;
void solve(){
    int n,q;
    scanf("%d %d",&n,&q);
    set<LL> s;
    s.insert(-2e9);
    s.insert(2e9+7);
    for(int i = 0;i<n;i++){
        int x;
        scanf("%d",&x);
        s.insert(x);
    }
    multiset<LL> ans;
    int last=*s.begin();
    for(auto it:s){
        ans.insert(it-last);
        last=it;
    }
    ans.erase(0);
    //for(auto it:ans)printf("%d ",it);
    //printf("\n");
      if(s.size()<=4){
            printf("0\n");
        }
        else
    printf("%lld\n",*prev(prev(s.end()))-*next(s.begin())-*prev(prev(prev(ans.end()))));
    while(q--){
        int t,x;
        scanf("%d %d",&t,&x);
        if(t==1){
            auto it=s.lower_bound(x);
            auto it2=prev(it);
           // printf("%d %d\n",*it2,*it);
            ans.erase(ans.find(*it-*it2));
            ans.insert(*it-x);
            ans.insert(x-*it2);
            s.insert(x);
        }
        else{
            s.erase(x);
            auto it=s.lower_bound(x);
            auto it2=prev(it);
            ans.insert(*it-*it2);
            ans.erase(ans.find(*it-x));
            ans.erase(ans.find(x-*it2));
        }
        if(s.size()<=4){
            printf("0\n");
        }
        else
       printf("%lld\n",*prev(prev(s.end()))-*next(s.begin())-*prev(prev(prev(ans.end()))));
    }
}
int main(){
    int t=1;
    //scanf("%d",&t);
    while(t--){
       // printf("Case #%d: ",T++);
        solve();
    }
}