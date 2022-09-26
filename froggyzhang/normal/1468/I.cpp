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
int n;
ll dx1,dy1,dx2,dy2;
ll Abs(ll x){
	return x>=0?x:-x;
}
int main(){
	n=read();
	dx1=read(),dy1=read();
	dx2=read(),dy2=read();
	if(dx1*dy2==dx2*dy1)return !printf("NO\n");
	ll g=Abs(__gcd(dy1,dy2));
	dy1/=g,dy2/=g;
	ll h=Abs(dx1*dy2-dx2*dy1);
	if(g*h==n){
		printf("YES\n");
		for(int i=0;i<h;++i){
			for(int j=0;j<g;++j){
				printf("%d %d\n",i,j);
			}
		}
	}
	else{
		printf("NO\n");
	}
	return 0;
}

/*qwq*/