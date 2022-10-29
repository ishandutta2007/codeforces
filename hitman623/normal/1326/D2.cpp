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
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
#include <unistd.h> // not included in bits/stdc++.h
#define int long
unsigned int mix(unsigned int a, unsigned int b, unsigned int c)
#undef int
{
    a=a-b;  a=a-c;  a=a^(c >> 13);
    b=b-c;  b=b-a;  b=b^(a << 8);
    c=c-a;  c=c-b;  c=c^(b >> 13);
    a=a-b;  a=a-c;  a=a^(c >> 12);
    b=b-c;  b=b-a;  b=b^(a << 16);
    c=c-a;  c=c-b;  c=c^(b >> 5);
    a=a-b;  a=a-c;  a=a^(c >> 3);
    b=b-c;  b=b-a;  b=b^(a << 10);
    c=c-a;  c=c-b;  c=c^(b >> 15);
    return c;
}
string s;
ll pw1[1000006],pw2[1000006],p1,p2,hell1,hell2;
void solve(){
    cin>>s;
    int l=0,r=sz(s)-1;
    while(l<r){
        if(s[l]==s[r]) l++,r--;
        else break;
    }
    string t;
    rep(i,l,sz(s)-l) t+=s[i];
    string revt=t;
    reverse(all(revt));
    ll ht1=0,ht2=0,hr1=0,hr2=0;
    int ans1=0;
    rep(i,0,sz(t)){
        ht1=(ht1*p1+t[i])%hell1;
        ht2=(ht2*p2+t[i])%hell2;
        hr1=(hr1+pw1[i]*revt[sz(t)-i-1])%hell1;
        hr2=(hr2+pw2[i]*revt[sz(t)-i-1])%hell2;
        if(ht1==hr1 and ht2==hr2) ans1=max(ans1,i+1);
    }
    ht1=0,ht2=0;
    hr1=0,hr2=0;
    int ans2=0;
    rep(i,0,sz(t)){
        ht1=(ht1*p1+revt[i])%hell1;
        ht2=(ht2*p2+revt[i])%hell2;
        hr1=(hr1+pw1[i]*t[sz(t)-i-1])%hell1;
        hr2=(hr2+pw2[i]*t[sz(t)-i-1])%hell2;
        if(ht1==hr1 and ht2==hr2) ans2=max(ans2,i+1);
    }
    if(ans1>ans2){
        rep(i,0,l+ans1) cout<<s[i];
        rep(i,0,l) cout<<s[sz(s)-l+i];
        cout<<endl;
    }
    else{
        rep(i,0,l) cout<<s[i];
        rep(i,0,l+ans2) cout<<s[sz(s)-l-ans2+i];
        cout<<endl; 
    }
}

signed main(){
    unsigned long seed = mix(clock(), time(NULL), getpid());
    srand(seed);
    p1=rand()%2000+29;
    p2=rand()%2000+31;
    hell1=rand()*rand()%800000000+200000007;
    hell2=rand()*rand()%800000000+200000009;
    pw1[0]=pw2[0]=1;
    rep(i,1,1000006) pw1[i]=pw1[i-1]*p1%hell1;
    rep(i,1,1000006) pw2[i]=pw2[i-1]*p2%hell2;
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