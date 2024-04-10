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
#define C           25
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
string t;
string query(string s){
    cout<<"? "<<s<<endl;
    cin>>s;
    return s;
}
string gen(int n){
    int w=(n+C-1)/C;
    char ch='a';
    string s;
    rep(i,1,n+1){
        s+=ch;
        if(i%w==0) ch++;
    }
    return s;
}
string go(int n,int x){
    if(x==0) return gen(n);
    else{
        int cur=0;
        string ans;
        while(cur<n){
            int d=min((n+C-1)/C,n-cur);
            ans+=go(d,x-1);
            cur+=d;
        }
        return ans;
    }
}
string s1,s2,s3;
string t1,t2,t3;
bitset<10001> pos[10004],f[26];
void solve(){
    cin>>t;
    s1=go(sz(t),0);
    s2=go(sz(t),1);
    s3=go(sz(t),2);
    t1=query(s1);
    t2=query(s2);
    t3=query(s3);

    rep(i,0,sz(s1)) f[s1[i]-'a'][i]=1;
    rep(i,0,sz(t1)) pos[i]=f[t1[i]-'a'];
    rep(i,0,26) f[i].reset();
    
    rep(i,0,sz(s2)) f[s2[i]-'a'][i]=1;
    rep(i,0,sz(t2)) pos[i]&=f[t2[i]-'a'];
    rep(i,0,26) f[i].reset();
    
    rep(i,0,sz(s3)) f[s3[i]-'a'][i]=1;
    rep(i,0,sz(t3)) pos[i]&=f[t3[i]-'a'];

    string res=t;
    rep(i,0,sz(t)) res[pos[i]._Find_first()]=t[i];
    cout<<"! "<<res<<endl;    
}

signed main(){
    solve();
    return 0;
}