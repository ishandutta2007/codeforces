#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
const ll mod=998244353;
const int N=2e6+1;
ll n,m;
ll a[N],b[N];
int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
	}
	int l=0;
	int bl=1,br=0;
	bool multi=false;
	for(int i=1; i<=n ;i++){
		if(i==1 || a[i-1]>a[i]) l=i;
		else if(i-l>br-bl){
			bl=l,br=i,multi=false;
		}
		else if(i-l==br-bl){
			multi=true;
		}
	}
	l=0;
	int cl=bl,cr=br;
	bool nulti=multi;
	bl=1,br=0;
	multi=false;
	for(int i=1; i<=n ;i++){
		if(i==1 || a[i-1]<a[i]) l=i;
		else if(i-l>br-bl){
			bl=l,br=i,multi=false;
		}
		else if(i-l==br-bl){
			multi=true;
		}
	}
	if(multi || nulti) return cout << "0\n",0;
	if(cr-cl!=br-bl) return cout << "0\n",0;
	if(cr!=bl) return cout << "0\n",0;
	if((br-bl+1)%2==0) return cout << "0\n",0;
	cout << "1\n";
}