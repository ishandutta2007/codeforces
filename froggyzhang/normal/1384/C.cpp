#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 100010
inline int read(){
	int x=0,f=1;
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
int T,cnt[21][21],n;
char a[N],b[N];
int Solve(){
	scanf("%s",a+1);
	scanf("%s",b+1);
	memset(cnt,0,sizeof(cnt));
	int ans=0;
	for(int i=1;i<=n;++i){
		if(b[i]<a[i])return -1;
		if(a[i]==b[i])continue;
		++cnt[a[i]-'a'][b[i]-'a'];
	}
	for(int i=0;i<20;++i){
		for(int j=0;j<20;++j){
			if(cnt[i][j]){
				++ans;
				for(int k=j+1;k<20;++k){
					cnt[j][k]+=cnt[i][k];
				}
				break;
			}
		}
	}
	return ans;
}
int main(){
	T=read();
	while(T--){
		n=read();
		printf("%d\n",Solve());
	}
	return 0;
}