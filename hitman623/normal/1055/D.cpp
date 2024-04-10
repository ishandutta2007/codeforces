#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).END()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define ENDl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,START[3003],END[3003];
string initial[3003],final[3003];
set<pair<string,string>> st;
string to,from;
int p[6003];
void prefix_function(string &s){
    memset(p,0,sizeof p);
    int m=sz(s);
    rep(i,1,m){
        int j=p[i-1];
        while(j>0 && s[i]!=s[j]) j=p[j-1];
        if(s[i]==s[j]) j++;
        p[i]=j;
    }
}
void replace(string &s){
    string cur=from+'#'+s;
    prefix_function(cur);
    rep(i,2*sz(from),sz(cur)){
        if(p[i]==sz(from)){
            rep(j,0,sz(from)){
                s[j+i-2*sz(from)]=to[j];
            }
            return;
        }
    }
}
void solve(){
    cin>>n;
    rep(i,1,n+1){
        cin>>initial[i];
    }
    rep(i,1,n+1){
        cin>>final[i];
    }
    memset(START,-1,sizeof START);
    rep(i,1,n+1){
        if(initial[i]==final[i]) continue;
        int s=sz(initial[i]);
        rep(j,0,s){
            if(initial[i][j]!=final[i][j]){
                START[i]=j;
                break;
            }
        }
        for(int j=s-1;j>=0;j--){
            if(initial[i][j]!=final[i][j]){
                END[i]=j;
                break;
            }
        }
        if(START[i]<=END[i]){
            st.insert({initial[i].substr(START[i],END[i]-START[i]+1),final[i].substr(START[i],END[i]-START[i]+1)});
        }
        if(sz(st)>1){
            cout<<"NO"<<endl;
            return;
        }
    }
    while(1){
        bool f=1;
        set<char> v;
        rep(i,1,n+1){
            if(START[i]==-1) continue;
            if(START[i]-1>=0){
                v.insert(initial[i][START[i]-1]);
            }
            else f=0;
        }
        if(sz(v)!=1 or !f) break;
        rep(i,1,n+1){
            if(START[i]==-1) continue;
            START[i]--;
        }
    }
    while(1){
        bool f=1;
        set<char> v;
        rep(i,1,n+1){
            if(START[i]==-1) continue;
            if(END[i]+1<sz(initial[i])){
                v.insert(initial[i][END[i]+1]);
            }
            else f=0;
        }
        if(sz(v)!=1 or !f) break;
        rep(i,1,n+1){
            if(START[i]==-1) continue;
            END[i]++;
        }
    }
    rep(i,1,n+1){
        if(START[i]!=-1){
            from=initial[i].substr(START[i],END[i]-START[i]+1);
            to=final[i].substr(START[i],END[i]-START[i]+1);
            break;
        }
    }
    rep(i,1,n+1){
        replace(initial[i]);
        if(initial[i]!=final[i]){
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl<<from<<endl<<to<<endl;
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