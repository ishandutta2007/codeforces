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
const int N=101;
int mat[N][N],temp1[N][N],temp2[N][N],base[N][N];
void copy(int a[N][N],int b[N][N]){
    rep(i,0,N){
        rep(j,0,N){
            a[i][j]=b[i][j];
        }
    }
}
void add(int a[N][N],int b[N][N]){
    rep(i,0,N){
        rep(j,0,N){
            a[i][j]=(a[i][j]+b[i][j])%hell;
        }
    }
}
void mul(int a[N][N],int b[N][N]){
    memset(temp1,0,sizeof temp1);
    rep(i,0,N){
        rep(j,0,N){
            rep(k,0,N){
                temp1[i][j]=(temp1[i][j]+1LL*a[i][k]*b[k][j])%hell;
            }
        }
    }
    copy(a,temp1);
}
void matpow(int n){
    if(n==0){
        rep(i,0,N){
            rep(j,0,N){
                mat[i][j]=i==j;
            }
        }
        return;
    }
    matpow(n/2);
    copy(temp2,mat);
    mul(temp2,mat);
    if(n%2) mul(temp2,base);
    copy(mat,temp2);
}
// Usage:
// 1. copy(base,mat);
// 2. matpow(n);
// result is stored in mat
int n,x,a[101],dp[101],s[101];
void solve(){
    cin>>n>>x;
    rep(i,1,n+1){
        int w;
        cin>>w;
        a[w]++;
    }
    dp[0]=s[0]=1;
    rep(i,1,101){
        rep(j,1,i+1){
            dp[i]=(1LL*dp[i-j]*a[j]+dp[i])%hell;
        }
        s[i]=(s[i-1]+dp[i])%hell;
    }
    if(x<100) cout<<s[x]<<endl;
    else{
        mat[0][0]=a[1]+1;
        rep(i,2,101) mat[0][i-1]=(a[i]-a[i-1]+hell)%hell;
        mat[0][100]=(hell-a[100])%hell;
        rep(i,1,101) mat[i][i-1]=1;
        copy(base,mat);
        matpow(x-100);
        int ans=0;
        rep(i,0,101) ans=(ans+1LL*mat[0][i]*s[100-i])%hell;
        cout<<ans<<endl;
    }
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