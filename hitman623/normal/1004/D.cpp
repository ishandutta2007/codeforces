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
int t,f[1000006],mx,d[1000006],z;
vi a[1000006];
bool check(int n,int m,int x,int y){
    if(x>=n || y>=m) return 0;
    rep(i,0,n){
        a[i].clear();
        a[i].resize(m);
    }
    rep(i,0,mx+1){
        d[i]=0;
    }
    a[x][y]=0;
    rep(i,0,n){
        rep(j,0,m){
            d[abs(i-x)+abs(j-y)]++;
        }
    }
    rep(i,0,mx+1){
        if(d[i]!=f[i]) return 0;
    }
    return 1;
}
int g=1,x,y,n,m;
void solve(){
    cin>>t;
    rep(i,0,t){
        int x;
        cin>>x;
        f[x]++;
        mx=max(mx,x);
    }
    if(f[0]!=1){
        cout<<-1<<endl;
        return ;
    }
    rep(i,1,mx+1){
        if(f[i]!=4*i){
            x=i-1;
            break;
        }
    }
    rep(i,x+1,mx+1){
        if(f[i]!=4*i-2*g+1){
            y=i-1;
            break;
        }
        g++;
    }
    for(int i=1;i*i<=t;++i){
        if(t%i==0){
            n=i;
            m=t/i;
            if(n+m==x+y+mx+2){
                if(check(n,m,x,y)){
                    cout<<n<<" "<<m<<endl;
                    cout<<x+1<<" "<<y+1<<endl;
                    return;
                }
                else if(check(m,n,x,y)){
                    cout<<m<<" "<<n<<endl;
                    cout<<x+1<<" "<<y+1<<endl;
                    return;
                }
            }
        }
    }
    int h=1;
    if(t%(x+y+1)==0){
        n=x+y+1;
        m=t/n;
        rep(i,y+1,mx+1){
            if(f[i]!=4*i-2*g-2*h+2){
                z=i-1;
                break;
            }
            g++;h++;
        }
        y=z;
        if(n+m==x+y+mx+2){
            if(check(n,m,x,y)){
                cout<<n<<" "<<m<<endl;
                cout<<x+1<<" "<<y+1<<endl;
                return;
            }
            else if(check(m,n,x,y)){
                cout<<m<<" "<<n<<endl;
                cout<<x+1<<" "<<y+1<<endl;
                return;
            }
        }
    }
    cout<<-1<<endl;
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