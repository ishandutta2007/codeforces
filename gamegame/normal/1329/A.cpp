#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
#define fi first
#define se second
const int N=1e6+1;
int n,m;
ll a[N],b[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n >> m;
	for(int i=1; i<=m ;i++){
		cin >> a[i];
	}
	int x=0;
	for(int i=m; i>=1 ;i--){
		if(a[i]<=x){
			b[i]=x-a[i]+2;
			x++;
		}
		else{
			b[i]=1;
			x=a[i];
		}
	}
	if(x>n) return cout << "-1\n",0;
	int y=n-x;
	x=0;
	int c=0;
	for(int i=m; i>=1 ;i--){
		int z=x;
		b[i]+=c;
		x=b[i]+a[i]-1;
		int w=z+a[i]-x;
		if(y>0){
			int cur=min(w,y);
			y-=cur;
			b[i]+=cur;
			x+=cur;
			c+=cur;
		}
	}
	if(y>0) return cout << "-1\n",0;
	for(int i=1; i<=m ;i++){
		cout << b[i] << ' ';
	}
}