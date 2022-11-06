#include<bits/stdc++.h>
using namespace std;
char s[]="xabcdefghi";
int x=1,y=1,n;
int vi[222][222],tot;
void ou(){vi[x][y]=1;printf("%c%d ",s[x],y);++tot;}
void ido(){
	if(y&1){
		if(x==8)++y;
		else ++x;
	}
	else{
		if(x==1)++y;
		else --x;
	}
	ou();
}
void ido2(){
	if(x&1){
		if(y<8)++y;
		else ++x;
	}
	else{
		if(y==7)++x;
		else --y;
	}
	ou();
}
void gao(){
	if(n==1)x=8,y=8,ou();
	else{
		if(x==8){
			y=7;
			ou();
			y=8;
			ou();
		}else if(y==8){
			x=7;
			ou();
			x=8;
			ou();
		}else if(vi[8][y]){
			y=8;
			ou();
			x=8;
			ou();
		}else{
			x=8;
			ou();
			y=8;
			ou();
		}
	}
}
int main(){
#ifdef flukehn
	freopen("E.txt","r",stdin);
#endif
	ou();
	cin>>n;
	int i;
	if(n==63){
		for(i=1;i<=48;++i)ido();
		ido2();
		x=7,y=8;
		ou();
		while(x!=2)--x,ou();
		--y,ou();
		while(x!=8)++x,ou();
		y=8,ou();
		//cerr<<tot<<endl;
		return 0;
	}
	
	if(n>49){
		for(i=1;i<=48;++i)ido();
		n-=48;
		while(n>2)ido2(),--n;
		gao();
		return 0;
	}
	while(n>2)ido(),--n;
	gao();
}