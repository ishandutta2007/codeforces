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
int n;
inline bool Ask(int x,int y){
	static char s[233];
	printf("1 %d %d\n",x,y);
	fflush(stdout);
	scanf("%s",s+1);
	return s[1]=='T';
}
void Report(int x,int y){
	printf("2 %d %d\n",x,y);
	fflush(stdout);
}
int Solve(int l,int r){
	if(l>r)return -1;
	int ans=r;
	while(l<r){
		int mid=(l+r)>>1;
		if(Ask(mid,mid+1)){
			ans=r=mid;	
		}	
		else{
			l=mid+1;
		}
	}
	return ans;
}
int main(){
	n=read();read();
	int p=Solve(1,n);
	int x=Solve(1,p-1),y=Solve(p+1,n);
	if(~x&&Ask(x,x+1))Report(x,p);
	else Report(p,y);
	return 0;
}