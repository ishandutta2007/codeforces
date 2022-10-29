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
int n,k,h;
bool query(int a,int b,int c){
    if(a==b or b==c) return 1;
    if(a==c) return 0;
    string x;
    cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
    fflush(stdout);
    cin>>x;
    return x=="Yes";
}
int f(int a,int b){
    int cnt=0;
    rep(i,1,n+1) cnt+=query(a,i,b);
    return cnt;
}
void solve(){
    unsigned long seed = mix(clock(), time(NULL), getpid());
    srand(seed);
    cin>>n>>k;
    int s=0,cur=1,a,b;
    while(s<n){
        s+=cur;
        cur*=k;
        h++;
    }
    rep(i,0,48){
        a=rand()%n+1,b=rand()%n+1;
        if(a==b){
            i--;
            continue;
        }
        if(f(a,b)==2*h-1) break;
    }
    rep(i,1,n+1){
        if(query(a,i,b) and f(a,i)==h){
            cout<<"! "<<i<<endl;
            return;
        }
    }
}

signed main(){
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}