#include<bits/stdc++.h>
using namespace std;
const int N=3e5+11,M=5e5+11,oo=~0u>>2;
char s[M];
int n,a[N],b[N];
int ansx,ansy;
int chk(int w){
	int x=0,y=0;
	int X=oo,Y=oo;
	int u=-oo,v=oo;
	int i;
	for(i=1;i<=n;++i){
		x=max(x,a[i]-w);
		y=max(y,b[i]-w);
		X=min(X,a[i]+w);
		Y=min(Y,b[i]+w);
		u=max(u,b[i]-a[i]-w);
		v=min(v,b[i]-a[i]+w);
	}
	//cerr << w << " " << x << " " << X << " " << y << " " << Y << " " << u << " " << v << endl;
	if(x>X||y>Y||u>v)return 0;
	for(ansx=x;ansx<=X;++ansx){
		int yy=u+ansx;
		int YY=v+ansx;
		int _y=max(yy,y);
		int _Y=min(YY,Y);
		if(_y<=_Y&&(_Y||ansx)){
			ansy=_Y;
			return 1;
		}
	}
	return 0;
}
int main(){
#ifdef flukehn
	freopen("a.in","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin>>n;
	int i,j,mx=0;
	for(i=1;i<=n;++i){
		cin>>s;
		int l=strlen(s),t=0;
		mx=max(mx,l);
		for(j=0;j<l;++j){
			t+=s[j]=='B';
		}
		a[i]=t;
		b[i]=l-t;
	}
	int l=0,r=mx+1;
	while(l<r){
		int m=l+r>>1;
		if(chk(m))r=m;
		else l=m+1;
	}
	//cout<<l<<"\n";
	printf("%d\n",l);
	chk(l);
	for(i=1;i<=ansx;++i)putchar('B');
	for(i=1;i<=ansy;++i)putchar('N');
	puts("");
}