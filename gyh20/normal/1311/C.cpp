#include<bits/stdc++.h>
using namespace std;
#define re register
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
int t,n,m,a[200005][26],ans[26],k;
char s[200005];
int main(){
	t=read();
	while(t--){
		n=read();
		m=read();
		memset(ans,0,sizeof(ans));
		scanf("%s",s+1);
		for(re int i=1;i<=n;++i){
			for(re int j=0;j<26;++j)a[i][j]=a[i-1][j];
			++a[i][s[i]-'a'];
		}
		for(re int i=1;i<=m+1;++i){
			if(i<=m)
			k=read();
			else k=n;
			for(re int j=0;j<26;++j)ans[j]+=a[k][j];
		}
		for(re int i=0;i<26;++i)printf("%d ",ans[i]);
		putchar('\n');
	}
}