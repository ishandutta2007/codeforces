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
int n,k,node=1,trie[100006][26];
void add(string s){
    int cur=1;
    rep(i,0,sz(s)){
        if(!trie[cur][s[i]-'a']) trie[cur][s[i]-'a']=++node;
        cur=trie[cur][s[i]-'a']; 
    }
}
bool canwin(int nod){
    bool win=0;
    rep(i,0,26){
        if(trie[nod][i]){
            win|=!canwin(trie[nod][i]); 
        }
    }
    return win;
}
bool canlose(int nod){
    bool lose=0,leaf=1;
    rep(i,0,26){
        if(trie[nod][i]){
            leaf=0;
            lose|=!canlose(trie[nod][i]); 
        }
    }
    return lose|leaf;
}
void solve(){
    cin>>n>>k;
    rep(i,0,n){
        string s;
        cin>>s;
        add(s);
    }
    int lose=canlose(1);
    int win=canwin(1);
    if(!win) cout<<"Second"<<endl;
    else if(lose) cout<<"First"<<endl;
    else if(k%2) cout<<"First"<<endl;
    else cout<<"Second"<<endl;
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