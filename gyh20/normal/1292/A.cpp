#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#define re register
using namespace std;
int t,n,a[100002],b[100002],c,q,x,y;
signed main(){
scanf("%d%d",&n,&q);
for(re int i=1;i<=q;++i){
	scanf("%d%d",&x,&y);
	if(x==1){
		if(a[y]){
			if(b[y-1])--c;
			if(b[y])--c;
			if(b[y+1])--c;
			a[y]^=1;
		}
		else{
			if(b[y+1])++c;
			if(b[y-1])++c;
			if(b[y])++c;
			a[y]^=1;
		}
	}
	else{
		if(b[y]){
			if(a[y-1])--c;
			if(a[y+1])--c;
			if(a[y])--c;
			b[y]^=1;
		}
		else{
			if(a[y-1])++c;
			if(a[y+1])++c;
			if(a[y])++c;
			b[y]^=1;
		}
	}
	if(c)puts("No");
	else puts("Yes");
}
	}