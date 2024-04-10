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
char ans[1000][1000];
pair<int,int>p[1000][1000];
void fun(int i, int j, int x, int y){
	if(x>0)if(ans[x-1][y]=='A')if(p[x-1][y]==mp(i+1,j+1)){ans[x-1][y]='D'; fun(i,j,x-1,y);}
	if(y>0)if(ans[x][y-1]=='A')if(p[x][y-1]==mp(i+1,j+1)){ans[x][y-1]='R'; fun(i,j,x,y-1);}
	if(x<n-1)if(ans[x+1][y]=='A')if(p[x+1][y]==mp(i+1,j+1)){ans[x+1][y]='U'; fun(i,j,x+1,y);}
	if(y<n-1)if(ans[x][y+1]=='A')if(p[x][y+1]==mp(i+1,j+1)){ans[x][y+1]='L'; fun(i,j,x,y+1);}
}
void fun2(int i,int j){
	//cout<<i<<j;
	if(i>0)if(ans[i-1][j]=='S'){ans[i-1][j]='D'; fun2(i-1,j) ;}
    if(i<n-1)if(ans[i+1][j]=='S'){ans[i+1][j]='U'; fun2(i+1,j) ;}
    if(j<n-1)if(ans[i][j+1]=='S'){ans[i][j+1]='L'; fun2(i,j+1) ;}
    if(j>0)if(ans[i][j-1]=='S'){ans[i][j-1]='R'; fun2(i,j-1) ;}
}
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
    	cin>>n;
    	
    	
    	fo(i,n){
    		fo(j,n)ans[i][j]='A';
    	}
    	fo(i,n)fo(j,n){
    		ll a,b;
    		cin>>a>>b;
    		p[i][j]=mp(a,b);
    	}
    	fo(i,n)fo(j,n){
    		if(ans[i][j]=='A' && p[i][j]==mp(i+1,j+1)){
    			ans[i][j]='X';
    			fun( i, j, i ,j );
    		}
    		if(ans[i][j]=='A' && p[i][j]==mp(-1,-1)){
    			ans[i][j]='S';
    			if(i>0)if(p[i-1][j]==mp(-1,-1))continue;
    			if(i<n-1)if(p[i+1][j]==mp(-1,-1))continue;
    			if(j<n-1)if(p[i][j+1]==mp(-1,-1))continue;
    			if(j>0)if(p[i][j-1]==mp(-1,-1))continue;
    			cout<<"INVALID"; return 0;
    		}
    	}
    	
    	fo(i,n)fo(j,n){
    		if(ans[i][j]=='S' ){
    			if(i>0)if(ans[i-1][j]=='S'){ans[i][j]='U'; fun2(i,j) ;}
    			if(i<n-1)if(ans[i+1][j]=='S'){ans[i][j]='D'; fun2(i,j) ;}
    			if(j<n-1)if(ans[i][j+1]=='S'){ans[i][j]='R'; fun2(i,j);}
    			if(j>0)if(ans[i][j-1]=='S'){ans[i][j]='L'; fun2(i,j) ;}
    		}
    	}
    	fo(i,n)fo(j,n)if(ans[i][j]=='A'|| ans[i][j]=='S'){cout<<"INVALID"; return 0;}
    	cout<<"VALID"<<endl;
    	fo(i,n){
    		fo(j,n)cout<<ans[i][j];
    		cout<<endl;
       	}

    	
    }

    return 0;
}