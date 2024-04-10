#include <bits/stdc++.h>
 
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
vi q;
vi solve2(int a,int b){
    if(a<0 or b<0) return q;
    if(a==0) return q;
    if(b==0){
        vi res;
        if(a==1) res.pb(0);
        else res.pb(-1);
        return res;
    }
    vi v;
    if(a==b or a==b+1){
        rep(i,0,b){
            v.pb(0);
            v.pb(1);
        }
        if(a!=b) v.pb(0);
    }
    else v.pb(-1);
    return v;
}
vi solve3(int a,int b,int c){
    if(a<=0 or b<0 or c<0) return q;
    if(c==0) return solve2(a,b);
    if(a==b-c or a==b-c+1){
        vi v;
        rep(i,0,a){
            v.pb(0);
            v.pb(1);
        }
        v.pop_back();
        vi vv=solve2(b-a+1,c);
        if(vv[0]==-1) return q;
        for(auto i:vv) v.pb(i+1);
            return v; 
    }
    return q;
}
vi solve4(int a,int b,int c,int d){
    vi v1=solve3(b-a+1,c,d);
    if(v1[0]!=-1){
        vi res;
        rep(i,0,a){
            res.pb(0);
            res.pb(1);
        }
        res.pop_back();
        for(auto i:v1) res.pb(i+1);
            return res;
    }
    v1=solve3(b-a,c,d);
    if(v1[0]!=-1){
        vi res;
        res.pb(1);
        rep(i,0,a){
            res.pb(0);
            res.pb(1);
        }
        res.pop_back();
        for(auto i:v1) res.pb(i+1);
            return res;
    }
    return v1;
}
int a,b,c,d,n;
vi res;
void solve(){
    q.pb(-1);
    cin>>a>>b>>c>>d;
    n=a+b+c+d;
    if(a and b and c and d){
        res=solve4(a,b,c,d);
        if(res[0]==-1){
            res.clear();
            goto e;
        }
    }
    else if(a and b and c){
        res=solve3(a,b,c);
        if(res[0]==-1){
            res=solve3(a,b-1,c);
            if(res[0]==-1) goto e;
            reverse(all(res));
            res.pb(1);
            reverse(all(res));
        }
        if(res[0]==-1) goto e;
    }
    else if(b and c and d){
        res=solve3(b,c,d);
        if(res[0]==-1){
            res=solve3(b,c-1,d);
            if(res[0]==-1) goto e;
            reverse(all(res));
            res.pb(1);
            reverse(all(res));
        }
        if(res[0]==-1) goto e;
        for(auto &i:res) i++;
    }
    else if(a and b and !d){
        if(abs(a-b)>1) goto e;
        rep(i,0,min(a,b)){
            res.pb(0);
            res.pb(1);
        }
        if(a>b) res.pb(0);
        else if(b>a){
            reverse(all(res));
            res.pb(1);
        }
    }
    else if(b and c){
        if(abs(b-c)>1) goto e;
        rep(i,0,min(b,c)){
            res.pb(1);
            res.pb(2);
        }
        if(b>c) res.pb(1);
        else if(c>b){
            reverse(all(res));
            res.pb(2);
        }
    }
    else if(c and d and !a){
        if(abs(c-d)>1) goto e;
        rep(i,0,min(c,d)){
            res.pb(2);
            res.pb(3);
        }
        if(c>d) res.pb(2);
        else if(d>c){
            reverse(all(res));
            res.pb(3);
        }
    }
    else if(n==a){
        if(n!=1) goto e;
        res.pb(0);
    }
    else if(n==b){
        if(n!=1) goto e;
        res.pb(1);
    }
    else if(n==c){
        if(n!=1) goto e;
        res.pb(2);
    }
    else if(n==d){
        if(n!=1) goto e;
        res.pb(3);
    }
    if(sz(res)){
        cout<<"YES"<<endl;
        for(auto i:res) cout<<i<<" ";
            cout<<endl;
        return;
    }
    e:
    cout<<"NO"<<endl;
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}