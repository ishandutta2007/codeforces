#include<bits/stdc++.h>
using namespace std;
#define N 1000010
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
int n,s[N],a[N],k;
int main(){
	n=read(),k=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	sort(a+1,a+n+1,greater<int>());
	s[0]=1,s[1]=-1;
	for(int i=0,j=1;i<=1000000;++i){
		s[i+1]+=s[i];
		if(s[i]+s[i+1]>=k)return !printf("%d\n",i+1);
		while(s[i]&&j<=n){
			--s[i];
			s[i+2]+=2;
			s[i+(a[j]/2)+2]--;
			s[i+((a[j]-1)/2)+2]--;
			++j;
		}
		k-=s[i];
	}
	printf("-1\n");
	return 0;
}