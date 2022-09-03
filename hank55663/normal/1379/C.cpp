#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > q[100005];
#define mp make_pair
#define x first
#define pb push_back
#define y second
#define LL long long
#define pii pair<int,int>
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    LL ans=0;
    vector<pii> v;
    multiset<int> s1,s2;
    for(int i = 0;i<m;i++){
        int a,b;
        scanf("%d %d",&a,&b);
       // a=rand();
       // b=rand();
        v.pb(mp(b,a));
        s1.insert(a);
    }
    s1.insert(-1);
    sort(v.begin(),v.end());
    LL sum=0;
    for(int i = 0;i<m;i++){
        if(s1.find(v[i].y)!=s1.end()){
            s1.erase(s1.find(v[i].y));
        }
        else{
            sum-=v[i].y;
            s2.erase(s2.find(v[i].y));
        }
        while(s2.size()&&(*s2.begin()<=v[i].x||*s1.rbegin()>*s2.begin()||s2.size()>=n)){
            sum-=*s2.begin();
            s1.insert(*s2.begin());
            s2.erase(s2.begin());
        }
        while(s2.size()<n-1&&*s1.rbegin()>v[i].x){
            sum+=*s1.rbegin();
            s2.insert(*s1.rbegin());
            s1.erase(s1.find(*s1.rbegin()));
        }
       // printf("%d %d %d\n",v[i].x,sum,s2.size());
        ans=max(ans,sum+v[i].y+(n-1-(int)s2.size())*1ll*v[i].x);
        s2.insert(v[i].y);
        sum+=v[i].y;
    }
    printf("%lld\n",ans);
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        solve();
    }
}