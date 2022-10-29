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
int n,m;
string s[300005];
string q[300005];
string make(char a,char b){
    string res;
    res+=a;
    res+=b;
    return res;
}
int sol(bool f,int mx){
    int ans=hell;
    string w="ACGT";
    do{
        string a[2][2]={{make(w[0],w[1]),make(w[1],w[0])},{make(w[2],w[3]),make(w[3],w[2])}};
        int cur=0;
        rep(i,0,n){
            int cnt[2]={0,0};
            rep(j,0,m){
                rep(k,0,2){
                    cnt[k]+=s[i][j]!=a[i%2][k][j%2];
                }
            }
            cur+=min(cnt[0],cnt[1]);
        }
        ans=min(ans,cur);
        if(f and mx==ans){
            rep(i,0,n){
                int cnt[2]={0,0};
                rep(j,0,m){
                    rep(k,0,2){
                        cnt[k]+=s[i][j]!=a[i%2][k][j%2];
                    }
                }
                if(cnt[0]<cnt[1]){
                    rep(j,0,m){
                        s[i][j]=a[i%2][0][j%2];
                    }
                }
                else{
                    rep(j,0,m){
                        s[i][j]=a[i%2][1][j%2];
                    }
                }
            }
            return 1;
        }
        cur=0;
        rep(i,0,m){
            int cnt[2]={0,0};
            rep(j,0,n){
                rep(k,0,2){
                    cnt[k]+=s[j][i]!=a[i%2][k][j%2];
                }
            }
            cur+=min(cnt[0],cnt[1]);
        }
        ans=min(ans,cur);
        if(f and mx==ans){
            rep(i,0,m){
                int cnt[2]={0,0};
                rep(j,0,n){
                    rep(k,0,2){
                        cnt[k]+=s[j][i]!=a[i%2][k][j%2];
                    }
                }
                if(cnt[0]<cnt[1]){
                    rep(j,0,n){
                        s[j][i]=a[i%2][0][j%2];
                    }
                }
                else{
                    rep(j,0,n){
                        s[j][i]=a[i%2][1][j%2];
                    }
                }
            }
            return 1;
        }
    }while(next_permutation(all(w)));
    return ans;
}
void solve(){
    cin>>n>>m;
    rep(i,0,n) cin>>s[i],q[i]=s[i];
    int ans=sol(0,0);
    sol(1,ans);
    rep(i,0,n) rep(j,0,m) ans-=q[i][j]!=s[i][j];
    assert(ans==0);
    rep(i,0,n) cout<<s[i]<<endl;    
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