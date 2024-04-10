#include <bits/stdc++.h>

#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<int,pii>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define hell        1000007
#define endl        '\n'
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
double p[1000006];
string s;
set<char> vowels;
double f(int a,int b){
    if(a>b) return f(b,a);
    double cur=0;
    cur+=a;
    cur+=(a+1)*(p[b+1]-p[a]);
    cur+=(a+b+2)*(p[a+b+1]-p[b+1])-a;
    return cur;
}
void solve(){
    rep(i,1,1000005){
        p[i]=p[i-1]+1.0l/i;
    }
    cin>>s;
    double ans=0;
    rep(i,0,sz(s)){
        if(vowels.find(s[i])!=vowels.end()){
            ans=ans+f(i,sz(s)-i-1);
        }
    }
    cout<<fixed<<setprecision(10)<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vowels.insert({'A','E','I','O','U','Y'});
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}