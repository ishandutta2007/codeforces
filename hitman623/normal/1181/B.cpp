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
string add(string a,string b){
    reverse(all(a));
    reverse(all(b));
    while(sz(a)<sz(b)) a+='0';
    while(sz(b)<sz(a)) b+='0';
    int carry=0;
    string c;
    rep(i,0,sz(a)){
        c+=(a[i]+b[i]+carry-'0'-'0')%10+'0';
        carry=(a[i]+b[i]+carry-'0'-'0')/10;
    }
    if(carry) c+=carry+'0';
    reverse(all(c));
    return c;
}
bool cmp(string a,string b){
    if(sz(a)<sz(b)) return 1;
    else if(sz(a)==sz(b)) return a<b;
    else return 0;
}
void solve(){
    string ans;
    int n;
    cin>>n;
    string s;
    cin>>s;
    ans=s;
    int f=0;
    for(int i=n/2-1;i>0;i--){
        if(s[i]!='0'){
            string w=add(s.substr(0,i),s.substr(i,n-i));
            if(cmp(w,ans)) ans=w;
            f++;
            if(f==2) break;
        }
    }
    f=0;
    for(int i=n/2;i<n;i++){
        if(s[i]!='0'){
            string w=add(s.substr(0,i),s.substr(i,n-i));
            if(cmp(w,ans)) ans=w;
            f++;
            if(f==2) break;
        }
    }
    cout<<ans<<endl;
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