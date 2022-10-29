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
int n;
vii v;
void solve(){
    v.clear();
    cin>>n;
    rep(i,0,n){
        int x;
        cin>>x;
        if(sz(v)==0 or v.back().x!=x) v.pb({x,1});
        else v.back().y++;
    }
    if(sz(v)<4){
        cout<<"0 0 0"<<endl;
        return;
    }
    int g=v[0].y,b=0,s=0,pos=-1;
    rep(i,1,sz(v)){
        b+=v[i].y;
        if(b>g){
            rep(j,i+1,sz(v)){
                s+=v[j].y;
                if(s>g){
                    pos=j;
                    break;
                }
            }
            break;
        }
    }
    if(g and b and s and g<b and g<s and b+g+s<=n/2){
        rep(i,pos+1,sz(v)){
            if(b+g+s+v[i].y<=n/2) s+=v[i].y;
            else break;
        }
        cout<<g<<" "<<b<<" "<<s<<endl;
    }
    else cout<<"0 0 0"<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}