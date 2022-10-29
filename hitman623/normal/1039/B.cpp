#include <bits/stdc++.h>

#define int         long long
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
int n,k;
string s;
bool query(int l,int r){
    cout<<l<<" "<<r<<endl;
    cin>>s;
    if(s=="Yes"){
        if(l==r) exit(0);
        return true;
    }
    return false;
}
void solve(){
    cin>>n>>k;
    int lo=1,hi=n;
    while(1){
        if(hi-lo+1<50){
            int d=lo+rand()%(hi-lo+1);
            query(d,d);
        }
        else{
            int mid=(lo+hi)/2;
            if(query(lo,mid)) hi=mid;
            else lo=mid;
        }
        lo=max(1LL,lo-k);
        hi=min(n,hi+k);
    }
}

signed main(){
    unsigned long seed = mix(clock(), time(NULL), getpid());
    srand(seed);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}