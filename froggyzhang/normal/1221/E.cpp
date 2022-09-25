#include<bits/stdc++.h>
using namespace std;
#define N 300020
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
int T,A,B,n,m,a[N];
char s[N];
bool Solve(){
	A=read(),B=read();
	scanf("%s",s+1);
	m=strlen(s+1);
	n=0;
	int cnt1=0,cnt2=0;
	int ok[2]={0,1};
	for(int i=1,now=0;i<=m+1;++i){
		if(s[i]=='X'||i==m+1){
			if(now>=B&&now<A){
				return false;
			}
			if(now>=2*B){
				++cnt2;
				ok[0]=ok[1]=0;
				for(int i=1;i<=now-A+1;++i){
					int x=i-1,y=now-(i+A-1);
					if((x>=B&&x<A)||x>=2*B)continue;
					if((y>=B&&y<A)||y>=2*B)continue;
					ok[(x>=A)^(y>=A)]=1;
				}
			}
			else if(now>=A){
				++cnt1;	
			}
			now=0;
		}
		else ++now;
	}
	if(cnt2>=2)return false;
	return ok[cnt1&1];
}
int main(){
	T=read();
	while(T--)printf(Solve()?"YES\n":"NO\n");
	return 0;
}