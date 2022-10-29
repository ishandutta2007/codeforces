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
int n;
string s[100005];
int p[1000006],pw[1000006],prime;
int get(int l,int r){
	return (p[r]-1LL*(l?p[l-1]:0)*pw[r-l+1]%hell+hell)%hell;
}
void solve(){
	unsigned long seed = mix(clock(), time(NULL), getpid());
	srand(seed);
	prime=rand()%10000+217;
	pw[0]=1;
	rep(i,1,1000006) pw[i]=1LL*prime*pw[i-1]%hell;
    cin>>n;
    rep(i,0,n) cin>>s[i];
    string ans=s[0];
    p[0]=s[0][0];
    rep(i,1,sz(s[0])) p[i]=(1LL*p[i-1]*prime+s[0][i])%hell;
    rep(i,1,n){
    	int hsh=0;
    	int mx=0;
    	rep(j,0,min(sz(ans),sz(s[i]))){
    		hsh=(1LL*hsh*prime+s[i][j])%hell;
    		if(hsh==get(sz(ans)-j-1,sz(ans)-1)){
    			mx=j+1;
    		}
    	}
    	rep(j,mx,sz(s[i])){
    		ans+=s[i][j];
    		p[sz(ans)-1]=(1LL*p[sz(ans)-2]*prime+ans.back())%hell;
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