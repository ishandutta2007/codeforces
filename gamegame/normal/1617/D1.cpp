#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
ll n,m;
vector<int>v[2];
int ans[N];
int ask(int x,int y,int z){
	x++;y++;z++;
	cout << "? " << x << ' ' << y << ' ' << z << endl;
	int res;cin >> res;return res;
}
void solve(){
	cin >> n;m=n/3;
	v[0].clear();v[1].clear();
	for(int i=0; i<m ;i++){
		int res=ask(3*i,3*i+1,3*i+2);
		v[res].push_back(i);
	}
	int x=v[0].back();v[0].pop_back();
	int y=v[1].back();v[1].pop_back();
	int q1=ask(3*x,3*x+1,3*y);
	int q2=ask(3*x,3*x+1,3*y+1);
	if(q1==0 && q2==0){
		ans[3*x]=0;ans[3*x+1]=0;
		int r1=ask(3*x,3*y,3*y+1);
		if(r1==0){
			ans[3*y+2]=1;
			int r3=ask(3*x+2,3*y,3*y+1);
			ans[3*x+2]=r3;
			ans[3*y]=ask(3*y+2,3*x,3*y);
			ans[3*y+1]=1-ans[3*y];
		}
		else{
			ans[3*y]=1;ans[3*y+1]=1;
			ans[3*x+2]=ask(3*x,3*y,3*x+2);
			ans[3*y+2]=ask(3*x,3*y,3*y+2);
		}
	}
	else{
		ans[3*x+2]=0;
		ans[3*y]=q1;ans[3*y+1]=q2;
		if(q1==1 && q2==1){
			int q3=ask(3*x,3*x+1,3*y+2);
			ans[3*y+2]=q3;
		}
		else ans[3*y+2]=1;
		if(q1==1){
			ans[3*x]=ask(3*x+2,3*y,3*x);
			ans[3*x+1]=1-ans[3*x];
		}
		else{
			ans[3*x]=ask(3*x+2,3*y+1,3*x);
			ans[3*x+1]=1-ans[3*x];
		}
	}
	int k[2];
	for(int i=0; i<3 ;i++){
		k[ans[3*x+i]]=3*x+i;
		k[ans[3*y+i]]=3*y+i;
	}
	for(auto c:v[0]){
		for(int j=0; j<3 ;j++){
			ans[3*c+j]=ask(k[0],k[1],3*c+j);
		}
	}for(auto c:v[1]){
		for(int j=0; j<3 ;j++){
			ans[3*c+j]=ask(k[0],k[1],3*c+j);
		}
	}
	int sum=0;
	for(int i=0; i<n ;i++) sum+=ans[i];
	cout << "! " << n-sum << ' ';
	for(int i=0; i<n ;i++){
		if(!ans[i]) cout << i+1 << ' ';
	}
	cout << endl;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	int t;cin >> t;
	while(t--){
		solve();
	}
}