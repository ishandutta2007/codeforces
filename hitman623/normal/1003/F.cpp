#include <bits/stdc++.h>

#define int         long long
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
#define hell2       1000000009
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,p[303];
pii hsh[303][303];
int s,ans;
string w[303];
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>w[i];
        p[i]=sz(w[i]);
        if(i){
            p[i]+=p[i-1];
        }
    }
    s=p[n-1]+n-1;
    ans=s;
    rep(i,0,n){
        int cur=0,cur2=0;
        rep(j,i,n){
            for(auto r:w[j]){
                cur=(cur*31+r-'a'+1)%hell;
                cur2=(cur2*67+r-'a'+1)%hell2;
            }
            hsh[i][j]={cur,cur2};
            cur=(cur*31+'#'-'a'+1)%hell;
            cur2=(cur2*67+'#'-'a'+1)%hell2;
        }
    }
    rep(i,0,n){
        rep(j,i,n){
            int l=j-i,cnt=1;
            rep(k,j+1,n){
                if(k+l>=n) break;
                if(hsh[k][k+l]==hsh[i][j]){
                    cnt++;
                    k=k+l;
                }
            }
            if(cnt<2) continue;
            int d=p[j]-(i?p[i-1]:0);
            ans=min(ans,s-cnt*(d-1));
        }
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}