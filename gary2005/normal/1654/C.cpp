/**
 *    author:  gary
 *    created: 20.03.2022 19:28:45
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
void solve(){
    multiset<LL> se;
    int n;
    LL sum=0;
    cin>>n;
    rb(i,1,n){
        int ai;
        cin>>ai;
        se.insert(ai);
        sum+=ai;
    }
    queue<LL> q;
    q.push(sum);
    int cnt=1;
    while (!se.empty()){
        LL now=q.front();
        q.pop();
        // cout<<now<<" "<<cnt<<" "<<se.size()<<endl;
        if(se.find(now)!=se.end()){
            se.erase(se.find(now));
            continue;
        }
        if(now==1){
            cout<<"NO\n";
            return ;
        }
        cnt++;
        if(cnt>n) break;
        q.push(now/2);
        q.push((now+1)/2);
    }
    if(cnt==n) cout<<"YES\n";
    else cout<<"NO\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t=1;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}