#include<bits/stdc++.h>
using namespace std;
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
int T,A,B;
const int p[10]={0,1,5,-1,-1,2,-1,-1,8,-1};
bool check(int i,int j){
	int a=i/10,b=i%10,c=j/10,d=j%10;
	if(p[a]==-1||p[b]==-1||p[c]==-1||p[d]==-1)return false;
	i=p[d]*10+p[c],j=p[b]*10+p[a];
	if(i<=A&&j<=B)return true;
	return false;
}
void Solve(){
	int x,y;
	scanf("%02d:%02d",&x,&y);
	for(int i=x;i<=A;++i){
		for(int j=(i==x?y:0);j<=B;++j){
			if(check(i,j)){
				printf("%02d:%02d\n",i,j);
				return;
			}
		}
	}
	printf("00:00\n");
}
int main(){
	T=read();
	while(T--){
		A=read(),B=read();
		--A,--B;
		Solve();
	}
	return 0;
}