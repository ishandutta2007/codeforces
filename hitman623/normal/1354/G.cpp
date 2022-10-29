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
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,k;
int query(int x1,int l1,int x2,int l2){
    cout<<"? "<<l1<<" "<<l2<<endl;
    rep(i,0,l1) cout<<x1+i+1<<" ";
    cout<<endl;
    rep(i,0,l2) cout<<x2+i+1<<" ";
    cout<<endl;
    string s;
    cin>>s;
    if(s=="FIRST") return 1;
    if(s=="SECOND") return -1;
    if(s=="EQUAL") return 0;
    assert(false);
    return 1;
}
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
int vis[1001];
void solve(){
    memset(vis,0,sizeof vis);
    cin>>n>>k;
    int cur=0;
    rep(i,0,20){
        int pos=rand()%(n-1)+1;
        if(vis[pos]) continue;
        vis[pos]=1;
        if(query(cur,1,pos,1)<0){
            cout<<"! 1"<<endl;
            return;
        }
    }
    int l=-1,r=-1;
    rep(i,0,10){
        if((1<<(i+1))>n){
            l=1<<i;
            r=n-l;
            break;
        }
        int d=query(0,1<<i,1<<i,1<<i);
        if(d>0){
            l=1<<i;
            r=1<<i;
            break;
        }
    }
    int lo=0,hi=r;
    while(hi-lo>1){
        int mid=(lo+hi)/2;
        if(query(0,mid,l,mid)>0) hi=mid;
        else lo=mid;
    }
    cout<<"! "<<l+hi<<endl;
}

signed main(){
    unsigned long seed = mix(clock(), time(NULL), getpid());
    srand(seed);
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