#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T;
void Solve(){
	int xA=read(),yA=read();
	int xB=read(),yB=read();
	int xF=read(),yF=read();
	printf("%d\n",abs(xA-xB)+abs(yA-yB)+2*(xA==xF&&xB==xF&&yF>=min(yA,yB)&&yF<=max(yA,yB))+2*(yA==yF&&yB==yF&&xF>=min(xA,xB)&&xF<=max(xA,xB)));
}
int main(){
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}