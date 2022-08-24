#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;;
const int N=2e6+1;
string s;
int n;
int p[N];
bool vis[N];
int c[5];
int run_1(int c1,int c2,int c3,bool y,int ans){
	bool ff=false;
	int c[4];c[1]=c1;c[2]=c2;c[3]=c3;
	if(n%3==1 && c[2]>=1){
		c[2]--;ff=true;
	}
	if(n%3==2 || ff){
		if(c[2]>0) c[2]--;
		else{
			ans++;c[1]-=2;
		}
	}
	if(n%3==1 && !ff){
		if(y){
			c[1]--;ans--;
		}
		else{
			if(c[1]==1){
				ans+=1;c[1]=0;
			}
			else{
				ans+=2;c[1]-=4;
			}
		}
	}
	while(c[2]>c[1]){
		c[2]--;c[1]+=2;ans++;
	}
	c[1]-=c[2];ans+=c[2];
	ans+=c[1]/3*2;
	return ans;
}
int run_2(int c1,int c2,int c3,bool y,int ans){
	bool ff=false;
	int c[4];c[1]=c1;c[2]=c2;c[3]=c3;
	if(n%3==1 && c[2]>=1 && !y){
		c[2]--;ff=true;
	}
	if(n%3==2 || ff){
		if(c[2]>0) c[2]--;
		else{
			ans++;c[1]-=2;
		}
	}
	if(n%3==1 && !ff){
		if(y){
			c[1]--;ans--;
		}
		else{
			if(c[1]==1){
				ans+=1;c[1]=0;
			}
			else{
				ans+=2;c[1]-=4;
			}
		}
	}
	while(c[2]>c[1]){
		c[2]--;c[1]+=2;ans++;
	}
	c[1]-=c[2];ans+=c[2];
	ans+=c[1]/3*2;
	return ans;
}
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> p[i];
		vis[i]=false;
	}
	c[1]=c[2]=c[3]=c[4]=0;
	int ans=0;
	for(int i=1; i<=n ;i++){
		if(vis[i]) continue;
		int cnt=0;
		int x=i;
		while(!vis[x]){
			vis[x]=true;
			x=p[x];
			cnt++;
		}
		if(cnt==1) c[1]++;
		else{
			int y=(cnt-2)%3+2;
			ans+=(cnt-y)/3;
			c[y]++;
		}
	}
	bool y=c[4]>0;
	c[1]+=c[4];
	ans+=c[4];
	bool ff=false;
	int tmp=run_1(c[1],c[2],c[3],y,ans);
	int tmp2=run_2(c[1],c[2],c[3],y,ans);
	ans=min(tmp,tmp2);
	
	ll f=1;
	while(n>=5 || n==3){
		f*=3; n-=3;f%=mod;
	}
	while(n>=1){
		f*=2;n-=2;f%=mod;
	}
	cout << f << ' ' << ans << endl;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;while(t--) solve();
}