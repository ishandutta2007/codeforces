#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
typedef long long ll;
int n,m,q;
ll p[3]={998244353,1000000007,1000003};
ll bit[3][2501][2501];
unordered_map<ll,int>um;
void update(int x,int y,int t,ll v){
	for(int i=x; i<=n ;i+=i&-i){
		for(int j=y; j<=m ;j+=j&-j){
			bit[t][i][j]+=v;
			bit[t][i][j]%=p[t];
		}
	}
}
ll query(int x,int y,int t){
	ll ans=0;
	for(int i=x; i>=1 ;i-=i&-i){
		for(int j=y; j>=1 ;j-=j&-j){
			ans+=bit[t][i][j];
			ans%=p[t];
		}
	}
	ans=(ans%p[t]+p[t])%p[t];
	return ans;
}
ll p7[100001][3];
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> m >> q;
	p7[0][0]=p7[0][1]=p7[0][2]=1;
	for(int i=1; i<=q ;i++){
		for(int j=0; j<3 ;j++){
			p7[i][j]=p7[i-1][j]*7%p[j];
		}
	}
	for(int i=1; i<=q ;i++){
		int t,x1,x2,y1,y2;
		cin >> t >> x1 >> y1 >> x2 >> y2;
		if(t==1){
			for(int j=0; j<3 ;j++){
				update(x1,y1,j,p7[i][j]);
				update(x1,y2+1,j,-p7[i][j]);
				update(x2+1,y1,j,-p7[i][j]);
				update(x2+1,y2+1,j,p7[i][j]);
			}
			ll num=(x1*1LL<<48)|(x2*1LL<<32)|(y1*1LL<<16)|(y2*1LL);
			um[num]=i;
		}
		else if(t==2){
			ll num=(x1*1LL<<48)|(x2*1LL<<32)|(y1*1LL<<16)|(y2*1LL);
			int tmp=um[num];
			for(int j=0; j<3 ;j++){
				update(x1,y1,j,-p7[tmp][j]);
				update(x1,y2+1,j,p7[tmp][j]);
				update(x2+1,y1,j,p7[tmp][j]);
				update(x2+1,y2+1,j,-p7[tmp][j]);
			}
		}
		else{
			bool ok=true;
			for(int j=0; j<3 ;j++){
				if(query(x1,y1,j)!=query(x2,y2,j)) ok=false;
			}
			if(ok) cout << "Yes\n";
			else cout << "No\n";
		}
	}
}