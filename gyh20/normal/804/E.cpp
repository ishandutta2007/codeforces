#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
inline void solve4(re int x){
	cout<<x+1<<" "<<x+2<<endl;
	cout<<x+1<<" "<<x+3<<endl;
	cout<<x+2<<" "<<x+4<<endl;
	cout<<x+1<<" "<<x+4<<endl;
	cout<<x+2<<" "<<x+3<<endl;
	cout<<x+3<<" "<<x+4<<endl;
}
inline void solve5(re int x,re int y){
	cout<<x+1<<" "<<x+2<<endl;
	cout<<x+1<<" "<<x+3<<endl;
	cout<<x+1<<" "<<x+4<<endl;
	cout<<x+2<<" "<<x+3<<endl;
	cout<<x+2<<" "<<y<<endl;
	cout<<x+3<<" "<<y<<endl;
	cout<<x+1<<" "<<y<<endl;
	cout<<x+3<<" "<<x+4<<endl;
	cout<<x+2<<" "<<x+4<<endl;
	cout<<x+4<<" "<<y<<endl;
}
inline void solve44(re int x,re int y){
	cout<<x+1<<" "<<y+1<<endl;
	cout<<x+1<<" "<<y+2<<endl;
	cout<<x+1<<" "<<y+3<<endl;
	cout<<x+2<<" "<<y+1<<endl;
	cout<<x+2<<" "<<y+4<<endl;
	cout<<x+1<<" "<<y+4<<endl;
	cout<<x+2<<" "<<y+3<<endl;
	cout<<x+3<<" "<<y+1<<endl;
	cout<<x+4<<" "<<y+2<<endl;
	cout<<x+3<<" "<<y+2<<endl;
	cout<<x+2<<" "<<y+2<<endl;
	cout<<x+3<<" "<<y+3<<endl;
	cout<<x+4<<" "<<y+1<<endl;
	cout<<x+4<<" "<<y+4<<endl;
	cout<<x+3<<" "<<y+4<<endl;
	cout<<x+4<<" "<<y+3<<endl;
}
int n,m;
int main(){
	n=read();
	if(n%4>1)return puts("NO"),0;
	puts("YES");
	if(n==1)return 0;
	if(n%4==0){
		for(re int i=0;i+1<n;i+=4)solve4(i);
		
	}
	else{
		for(re int i=0;i+1<n;i+=4)solve5(i,n);
	}
	for(re int i=0;i+1<n;i+=4)
		for(re int j=i+4;j+1<n;j+=4)
			solve44(i,j);
}