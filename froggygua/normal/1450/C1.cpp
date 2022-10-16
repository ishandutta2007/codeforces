#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define N 321
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
int T,n,cnt[3];
char a[N][N];
void Solve(){
	cnt[0]=cnt[1]=cnt[2]=0;
	for(int i=1;i<=n;++i){
		scanf("%s",a[i]+1);
		for(int j=1;j<=n;++j){
			if(a[i][j]=='X'){
				++cnt[(i+j)%3];
			}
		}
	}
	int d=(cnt[0]<cnt[1]?(cnt[0]<cnt[2]?0:2):(cnt[1]<cnt[2]?1:2));
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			putchar(a[i][j]=='X'?((i+j)%3==d?'O':'X'):'.');
		}
		putchar('\n');
	}
}
int main(){
	T=read();
	while(T--){
		n=read();
		Solve();
	}
	return 0;
}