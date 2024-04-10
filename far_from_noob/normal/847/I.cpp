#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define dd double
#define endl "\n"
#define pb push_back
#define all(v) v.begin(),v.end()
#define mp make_pair
#define fi first
#define se second
#define fo(i,n) for(int i=0;i<n;i++)
#define fo1(i,n) for(int i=1;i<=n;i++)
ll mod=1000000007;
ll n,k,t,m,q,flag=0;
ll po(ll k ,ll n,ll ans,ll temp,ll ans1){
    if(n==0)return ans;
    while(temp<=n){
        ans*=ans1;ans%=mod;ans1=ans1*ans1;ans1%=mod;n=n-temp;temp*=2;
    }
    return po(k,n,ans,1,k)%mod;
    //eg. po(2,78,1,1,2);
}
ll min(ll a,ll b){if(a>b)return b;else return a;}
ll max(ll a,ll b){if(a>b)return a;else return b;}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    //cin>>t;
    t=1;
    while(t--){
        cin>>n>>m>>q;
        ll p;
        cin>>p;
        char c[n][m];
        fo(i,n)fo(j,m)cin>>c[i][j];
        ll ans[n][m];
        fo(i,n)fo(j,m)ans[i][j]=0;
        ll visited[n][m];
        fo(i,n)fo(j,m)visited[i][j]=-1;
        ll power[50];
        fo(i,50)power[i]=(ll)pow(2,i);
        fo(i,n)fo(j,m){
            if(c[i][j]!='.' && c[i][j]!='*'){
                ll temp=(ll)(c[i][j]-'A'+1)*q;
                //cout<<temp<<" ";
                queue<pair<pair<ll,ll >,ll> >que;
                que.push(mp(mp(i,j),0));
                ll mark=i*m+ j;
                visited[i][j]=mark;
                while(que.size()>0){
                    ll x=que.front().fi.fi,y =que.front().fi.se,z=que.front().se;
                    que.pop();
                    ans[x][y]+=temp/power[z];
                    if(x>0)if(x>0 && abs(x-1-i)+abs(y-j) <=25 && c[x-1][y]!='*' && visited[x-1][y]!=mark && z<=25){
                        que.push(mp(mp(x-1,y),z+1));
                        visited[x-1][y]=mark;
                    }
                    if(y>0)if(y>0 && abs(x-i)+abs(y-1-j) <=25 && c[x][y-1]!='*' && visited[x][y-1]!=mark && z<25){
                        que.push(mp(mp(x,y-1) , z+1));
                        visited[x][y-1]=mark;
                    }
                    if(x<n-1)if(x<n-1 && abs(x+1-i)+abs(y-j) <=25 && c[x+1][y]!='*' && visited[x+1][y]!=mark && z<=25){
                        que.push(mp(mp(x+1,y),z+1));
                        visited[x+1][y]=mark;
                    }
                    if(y<m-1)if(y<m-1 && abs(x-i)+abs(y+1-j) <=25 && c[x][y+1]!='*' && visited[x][y+1]!=mark && z<=25){
                        que.push(mp(mp(x,y+1),z+1));
                        visited[x][y+1]=mark;
                    }
 
                }
 
            }
        }
        ll count=0;
        fo(i,n)fo(j,m){if(ans[i][j]>p)count++;}
        cout<<count;
        
    }
 
    return 0;
}