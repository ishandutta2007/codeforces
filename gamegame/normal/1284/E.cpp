#include<iostream>
#include<iomanip>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pt;
#define x first
#define y second
pt operator-(pt u,pt v){return {u.x-v.x,u.y-v.y};};
ll operator^(pt u,pt v){return u.x*v.y-u.y*v.x;}
int q(pt u){return (u.y<0)*2+((u.x<0)^(u.y<0));}
bool cmp(pt u,pt v){
	if(q(u)!=q(v)) return q(u)<q(v);
	return (u^v)>=0;
}
bool leqpi(pt u,pt v){
	return (u^v)>=0;
}
const pt one={1,0};
ll n;
pt a[2501];
pt b[5001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i].x >> a[i].y;
		//a[i].x+=1e9;a[i].y+=1e9;
	}
	ll cnt=0;
	ll cnt2=0;
	for(int i=1; i<=n ;i++){
		for(int j=1; j<=n ;j++) if(j!=i) b[j-(j>i)]=a[j]-a[i];
		sort(b+1,b+n,cmp);
		int ptr=1;
		while(ptr<=n-1 && (one^b[ptr])>=0){
			b[n-1+ptr]=b[ptr];ptr++;
		}
		int pl=1;
		ll tot=0;
		ll tot2=0;
		for(int j=ptr; j<ptr+n-1 ;j++){
			while(pl<=j-n+1) pl++;
			while(pl<j && !leqpi(b[pl],b[j])) pl++;
			tot+=1LL*(j-pl)*(j-pl-1)/2;
			tot2+=1LL*(j-pl)*(j-pl-1)*(j-pl-2)/6;
		}
		cnt+=tot;
		cnt2+=tot2;
	}
	for(int i=1; i<=n ;i++){
		for(int j=i+1; j<=n ;j++){
			for(int k=j+1; k<=n ;k++){
				for(int l=1; l<=n ;l++){
					if(l==i || l==j || l==k) continue;
				}
			}
		}
	}
	//cout << cnt << endl;
	ll c40=cnt-1LL*3*n*(n-1)*(n-2)*(n-3)/24;
	ll c31=1LL*4*n*(n-1)*(n-2)*(n-3)/24-cnt;
	cout << c31*(n-4)/2 << '\n';
}