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
#define N           1000000LL
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int gcd(int a,int b,int &x,int &y){
    if(a==0){
        x=0,y=1;
        return b;
    }
    int x1,y1;
    int d=gcd(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return d;
}
bool find_any_solution(int a,int b,int c,int &x0,int &y0,int &g){
    g=gcd(abs(a),abs(b),x0,y0);
    if(c%g!=0)
        return false ;
    x0*=c/g;
    y0*=c/g;
    if(a<0) x0*=-1;
    if(b<0) y0*=-1;
    return true;
}
// x=x0+k*b/g and y=y0-k*a/g where k is any integer
int k,ans[2002];
void solve(){
    cin>>k;
    rep(n,1,2001){
        rep(m,1,2001-n){
            // s*m-x*(n+m)=k
            int a=m,b=-(n+m);
            int s,x,g;
            if(find_any_solution(a,b,k,s,x,g)){
                int w=min(s*g/(n+m),x*g/a);
                // s+w*b/g>0
                // x-w*a/g>0
                while(s+w*b/g<=0) w--;
                while(x-w*a/g<=0) w--;
                s+=w*b/g; 
                x-=w*a/g;
                assert(s>=0);
                assert(x>=0);
                if(s<=N*n and x<=N*m){
                    for(int i=m-1;i>=0;i--){
                        ans[i]=-min(x,N);
                        x-=min(x,N);
                    }
                    rep(i,m,n+m){
                        ans[i]=min(s,N);
                        s-=min(s,N);
                    }
                    cout<<n+m<<endl;
                    rep(i,0,n+m){
                        cout<<ans[i]<<" ";
                    }
                    cout<<endl;
                    return;
                } 
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