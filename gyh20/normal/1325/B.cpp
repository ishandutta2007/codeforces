#include<bits/stdc++.h>
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
int n,m,t;
unordered_map<int,int>v;
int a[100002];
int main(){
	t=read();
	while(t--){
		n=read();
		re int ans=0;
		for(re int i=1;i<=n;++i){
			a[i]=read();
			if(!v[a[i]]){
				++ans;
			
			}	++v[a[i]];
		}
		for(re int i=1;i<=n;++i)--v[a[i]];
		printf("%d\n",ans);
	}
}