#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
vector<ll>ax,ay;
vector<char>az;
void ad(ll x,ll y){
	ax.push_back(x);
	ay.push_back(y);
	az.push_back('+');
	//cout << x << " + " << y << '\n';
}
void xo(ll x,ll y){
	ax.push_back(x);
	ay.push_back(y);
	az.push_back('^');
	//cout << x << " ^ " << y << '\n';
}
ll iu=1048576;
void make(ll z,ll x){
	if(z==1) return;
	if(z%2){
		make(z-1,x);
		ad((z-1)*x,x);
		return;
	}
	make(z/2,x);
	ad((z/2)*x,(z/2)*x);
}
void solve(ll x){
	//cout << "solve " << x << endl;
	//system("Pause");
	ll y=(x+1)&(-(x+1));
	if(y>x){
		ad(x,x);//62
		xo(2*x,x);//33
		ad(x+2,x);//64
		ad(x+2,x+2);//66
		xo(2*x+2,2*x+4);//2
		for(ll z=4; z<x ;z*=2){
			ad(z/2,z/2);
		}
		for(ll z=(x+1)/2; z>=2 ;z/=2){
			xo(x,z);
			x^=z;
		}
		return;
	}
	y/=2;
	for(ll z=1; z<=iu ;z++){
		if(z*x%iu==y){
			make(z,x);
			ad(z*x,x);
			xo((z+1)*x,z*x);
			ll tmp=((z+1)*x)^(z*x);
			//cout << "funny " << tmp << endl;
			solve(x+2*y);
			return;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	ll x;cin >> x;solve(x);
	cout << ax.size() << '\n';
	for(int i=0; i<ax.size() ;i++){
		cout << ax[i] << ' ' << az[i] << ' ' << ay[i] << '\n';
	}
}