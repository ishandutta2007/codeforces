#include<bits/stdc++.h>
using namespace std;
#define N 100010
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
int n,m;
char s[N];
inline void Report(int x){
	if(x==1)printf("tokitsukaze\n");
	else if(x==-1)printf("quailty\n");
	else printf("once again\n");
	exit(0);
}
int main(){
	n=read(),m=read();
	scanf("%s",s+1);
	if(m==n)Report(1);
	int l[2]={0,0},r[2]={n+1,n+1};
	for(int c=0;c<2;++c){
		while(s[l[c]+1]==(char)(c+'0'))++l[c];
		while(s[r[c]-1]==(char)(c+'0'))--r[c];
		if(r[c]-l[c]-1<=m)Report(1);
	}
	if(m*2<n)Report(0);
	for(int i=1;i<=n-m+1;++i){
		for(int c=0;c<2;++c){
			if(l[c]<i-1&&r[c]>i+m)Report(0);	
		}	
	}
	Report(-1);
	return 0;
}