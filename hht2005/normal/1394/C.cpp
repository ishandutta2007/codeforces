#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10;
int B[maxn],N[maxn],n;
char s[maxn];
int check(int L) {
	int U1,U2,U3,D1,D2,D3;
	U1=U2=U3=1e9;
	D1=D2=0;
	D3=-1e9;
	for(int i=1;i<=n;i++) {
		U1=min(U1,B[i]+L);
		D1=max(D1,B[i]-L);
		U2=min(U2,N[i]+L);
		D2=max(D2,N[i]-L);
		U3=min(U3,B[i]-N[i]+L);
		D3=max(D3,B[i]-N[i]-L);
	}
	if(U1<D1||U2<D2||U3<D3)return 0;
	if((U2+U3<D1||U2+D3>U1)&&(D2+U3<D1||D2+D3>U1)) {
		if(U2+D3>U1&&D2+U3<D1)return 1;
		return 0;
	}
	return 1;
}
int main() {
	int L=0,R=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%s",s+1);
		int m=strlen(s+1);
		R=max(2*m,R);
		for(int j=1;j<=m;j++)
			if(s[j]=='B')B[i]++;
			else N[i]++;
	}
	while(L<=R) {
		int mid=(L+R)>>1;
		if(check(mid))R=mid-1;
		else L=mid+1;
	}
	printf("%d\n",R+1);
	int U1,U2,U3,D1,D2,D3;
	U1=U2=U3=1e9;
	D1=D2=0;
	D3=-1e9;
	for(int i=1;i<=n;i++) {
		U1=min(U1,B[i]+R+1);
		D1=max(D1,B[i]-R-1);
		U2=min(U2,N[i]+R+1);
		D2=max(D2,N[i]-R-1);
		U3=min(U3,B[i]-N[i]+R+1);
		D3=max(D3,B[i]-N[i]-R-1);
	}
	int X=-1,Y=-1;
	if(U2+U3>=D1&&U2+D3<=U1) {
		X=U2;
		if(U2+D3>=D1)Y=U2+D3;
		else if(U2+U3<=U1)Y=U2+U3;
		else Y=U1;
	}
	else if(D2+U3>=D1&&D2+D3<=U1) {
		X=D2;
		if(D2+D3>=D1)Y=D2+D3;
		else if(D2+U3<=U1)Y=D2+U3;
		else Y=U1;
	} else {
		Y=U1;
		X=U1-U3;
	}
	for(int i=1;i<=Y;i++)putchar('B');
	for(int i=1;i<=X;i++)putchar('N');
	puts("");
	return 0;
}