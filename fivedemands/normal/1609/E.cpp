#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=1e9+7;
const int N=2e6+1;
ll n,q;

int c[262144][3];
int ans[262144][3];
void upd(int id,int l,int r,int p,char d){
	if(l==r){
		c[id][0]=c[id][1]=c[id][2]=0;
		c[id][d-'a']=1;
		return;
	}
	int mid=(l+r)/2;
	if(p<=mid) upd(id*2,l,mid,p,d);
	else upd(id*2+1,mid+1,r,p,d);
	c[id][0]=c[id*2][0]+c[id*2+1][0];
	c[id][1]=c[id*2][1]+c[id*2+1][1];
	c[id][2]=c[id*2][2]+c[id*2+1][2];
	ans[id][2]=min(ans[id*2][2]+c[id*2+1][2],c[id*2][1]+ans[id*2+1][2]);
	ans[id][1]=min(ans[id*2][1]+c[id*2+1][1],c[id*2][0]+ans[id*2+1][1]);
	ans[id][0]=min(min(ans[id*2][0]+c[id*2+1][2],c[id*2][0]+ans[id*2+1][0]),ans[id*2][1]+ans[id*2+1][2]);
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> q;
	for(int i=1; i<=n ;i++){
		char c;cin >> c;
		upd(1,1,n,i,c);
	}
	for(int i=1; i<=q ;i++){
		int p;char d;cin >> p >> d;
		upd(1,1,n,p,d);
		cout << ans[1][0] << '\n';
	}
}