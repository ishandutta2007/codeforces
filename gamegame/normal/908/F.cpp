#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
#include<iomanip>
using namespace std;
typedef long long ll;
int n;
int p[300001];
char c[300001];
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	char c;
	int p;
	int fb=-1,fr=-1,lb=0,lr=0;
	int ldb=0,ldr=0;
	int lg=-1;
	ll ans=0;
	for(int i=1; i<=n; i++){
		cin >> p >> c;
		if(c=='B'){
			if(fb==-1) fb=p;
			ldb=max(ldb,p-lb);
			lb=p;
		}
		else if(c=='R'){
			if(fr==-1) fr=p;
			ldr=max(ldr,p-lr);
			lr=p;
		}
		else{
			int cb,cr;
			if(lg==-1){
				if(fb==-1) cb=0;
				else cb=p-fb;
				if(fr==-1) cr=0;
				else cr=p-fr;
				ans+=cb+cr;
			}
			else{
				if(fb==-1) cb=0;
				else cb=p-lg-max(ldb,p-lb);
				if(fr==-1) cr=0;
				else cr=p-lg-max(ldr,p-lr);
				ans+=min(2*(p-lg),p-lg+cb+cr);
			}
			fb=-1,fr=-1,lb=p,lr=p;
			ldb=0,ldr=0;
			lg=p;
		}
	}
	if(lg==-1){
		int cb,cr;
		if(fb==-1) cb=0;
		else cb=lb-fb;
		if(fr==-1) cr=0;
		else cr=lr-fr;
		ans+=cb+cr;
	}
	else ans+=(lb-lg)+(lr-lg);
	cout << ans << endl;
}