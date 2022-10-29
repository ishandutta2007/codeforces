#include <bits/stdc++.h>
#define int         long long 
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
#define hell        998244353
#define mod         1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
#include <unistd.h> // not included in bits/stdc++.h
unsigned int mix(unsigned int a, unsigned int b, unsigned int c)
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
bool isvalidforl[1000006],isvalidforr[1000006];
pii hsha[1000006],hshl[1000006],hshr[1000006],p[1000006];
int base1,base2;
long long prefixsum[1000006],dp[1000006];
pii hash_of_a(int l,int r){
    int h1=hsha[r].x-(l?hsha[l-1].x*p[r-l+1].x:0);
    int h2=(long long)(hsha[r].y-(l?hsha[l-1].y*p[r-l+1].y:0))%mod;
    h2=(h2+mod)%mod;
    return {h1,h2};
}
string a,l,r;
void pre(){
    hsha[0].x=hsha[0].y=a[0]-'0'+1;
    p[0].x=p[0].y=1;
    rep(i,1,sz(a)){
        hsha[i].x=hsha[i-1].x*base1+a[i]-'0'+1;
        hsha[i].y=(long long)(hsha[i-1].y*base2+a[i]-'0'+1)%mod;
        p[i].x=p[i-1].x*base1;
        p[i].y=(long long)(p[i-1].y*base2)%mod;
    }
    p[sz(a)].x=p[sz(a)-1].x*base1;
    p[sz(a)].y=(long long)(p[sz(a)-1].y*base2)%mod;
    hshl[0].x=hshl[0].y=l[0]-'0'+1;
    rep(i,1,sz(l)){
        hshl[i].x=hshl[i-1].x*base1+l[i]-'0'+1;
        hshl[i].y=(long long)(hshl[i-1].y*base2+l[i]-'0'+1)%mod;
    }
    hshr[0].x=hshr[0].y=r[0]-'0'+1;
    rep(i,1,sz(r)){
        hshr[i].x=hshr[i-1].x*base1+r[i]-'0'+1;
        hshr[i].y=(long long)(hshr[i-1].y*base2+r[i]-'0'+1)%mod;
    }
}
bool isPrime(int N){
    if(N<2)return false;
    if(N<4)return true;
    if((N&1)==0)return false;
    if(N%3==0)return false;
    int curr=5,s=sqrt(N);
    while(curr<=s){
        if(N%curr==0)return false;
        curr+=2;
        if(N%curr==0)return false;
        curr+=4;
    }
    return true;
}
void solve(){
    unsigned int seed = mix(clock(), time(NULL), getpid());
    srand(seed);
    base1=(1ULL*rand()*rand())%(100000)+31;
    base2=(1ULL*rand()*rand())%(100000)+41;
    while(isPrime(base1)==0) base1++;
    while(isPrime(base2)==0) base2++;
    cin>>a>>l>>r;
    pre();
    int n=sz(a);
    a+='1';
    a+='1';
    rep(i,0,n-sz(l)+1){
        int lo=i,hi=i+sz(l)-1;
        while(hi-lo>1){
            int mid=(lo+hi)/2;
            if(hash_of_a(i,mid)==hshl[mid-i]) lo=mid;
            else hi=mid;
        }
        if(hash_of_a(i,lo)!=hshl[lo-i]){
            isvalidforl[i]=a[lo]>l[lo-i];
        }
        else if(hash_of_a(i,hi)!=hshl[hi-i]){
            isvalidforl[i]=a[hi]>l[hi-i];
        }
        else isvalidforl[i]=1;
        if(a[i]=='0' and sz(l)>1) isvalidforl[i]=0;
    }
    rep(i,0,n-sz(r)+1){
        int lo=i,hi=i+sz(r)-1;
        while(hi-lo>1){
            int mid=(lo+hi)/2;
            if(hash_of_a(i,mid)==hshr[mid-i]) lo=mid;
            else hi=mid;
        }
        if(hash_of_a(i,lo)!=hshr[lo-i]){
            isvalidforr[i]=a[lo]<r[lo-i];
        }
        else if(hash_of_a(i,hi)!=hshr[hi-i]){
            isvalidforr[i]=a[hi]<r[hi-i];
        }
        else isvalidforr[i]=1;
        if(a[i]=='0' and sz(r)>1) isvalidforr[i]=0;
    }
    dp[0]=prefixsum[0]=1;
    rep(i,1,n+1){
        if(sz(l)==sz(r)){
            if(i>=sz(l) and isvalidforr[i-sz(r)] and isvalidforl[i-sz(l)]){
                dp[i]=dp[i-sz(l)];
            }
        }
        else{
            if(i>=sz(l) and isvalidforl[i-sz(l)]){
                dp[i]=(dp[i]+dp[i-sz(l)])%hell;
            }            
            if(i>=sz(r) and isvalidforr[i-sz(r)]){
                dp[i]=(dp[i]+dp[i-sz(r)])%hell;
            }
            dp[i]=(dp[i]+(i-sz(l)-1>=0?prefixsum[i-sz(l)-1]:0)-(i-sz(r)>=0?prefixsum[i-sz(r)]:0)+hell)%hell;
        }
        prefixsum[i]=prefixsum[i-1];
        if(a[i]!='0') prefixsum[i]=(prefixsum[i]+dp[i])%hell;
    }
    cout<<dp[n]<<endl;
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