#include<bits/stdc++.h>
#include<windows.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0'){
		t=(t<<3)+(t<<1)+v-48;
		v=getchar();
	}
	return t;
}
int t,a,b,c,ans;
inline void solve(re int x,re int y,re int z,re int A,re int B,re int C,re int cnt){
	if(x>1||y>1||z>1)return;
//	cout<<x<<" "<<y<<" "<<z<<" "<<A<<" "<<B<<" "<<C<<" "<<cnt<<endl; 
	if(A>a||B>b||C>c)return;
	ans=max(ans,cnt);
	solve(x,y,z+1,A+x,B+y,C+z+1,cnt+1);
	solve(x,y+1,0,A+x,B+y+1,C,cnt+1);
	solve(x+1,0,0,A+x+1,B,C,cnt+1);
}
int main(){
	t=read();
	while(t--){
		a=read();
		b=read();
		c=read();
		if(a+b+c==0){
			puts("0");
		}
		else{
			ans=0;
			solve(0,0,0,0,0,0,0);
			printf("%d\n",ans);
		}
	}
}