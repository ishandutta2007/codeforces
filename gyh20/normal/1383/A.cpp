#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,ans;
char a[100002],b[100002];
int main(){
	t=read();
	while(t--){
		n=read(),ans=0;
		scanf("%s%s",a+1,b+1);
		for(re int i='a';i<='z';++i){
			re int mn=1e9;
			for(re int j=1;j<=n;++j)if(a[j]==i&&b[j]!=i)mn=min(mn,(int)b[j]);
			if(mn>'z')continue;
			if(mn<i)ans=-1145141;
			++ans;
			for(re int j=1;j<=n;++j)if(a[j]==i&&b[j]!=i)a[j]=mn;
		}
		printf("%d\n",ans>=0?ans:-1);
	}
}