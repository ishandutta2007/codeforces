/*qwq*/
#include<bits/stdc++.h>
using namespace std;
#define N 10010
const double P=0.7114514;
const int K=1e8;
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
mt19937 rnd(time(0));
int a[N],n,m;
char s[N];
int main(){
	n=read(),m=read();
	while(m--){
		scanf("%s",s+1);
		double t[2]={0,0};
		for(int i=1;i<=n;++i){
			t[s[i]-'0']+=pow(P,a[i]);
		}
		if(rnd()%K<=K*t[0]/(t[0]+t[1]))printf("0\n");
		else printf("1\n");
		fflush(stdout);
		int x=read();
		for(int i=1;i<=n;++i){
			if(s[i]-'0'!=x)++a[i];
		} 
	}
	return 0;
}