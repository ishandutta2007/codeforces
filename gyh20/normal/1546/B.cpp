#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
int t,n,m,a[100002][26],b[100002][26];
string s[100002],T;
int main(){
	t=read();
	while(t--){
		n=read(),m=read();
		for(re int i=1;i<=m;++i)memset(a[i],0,sizeof(a[i])),memset(b[i],0,sizeof(b[i]));
		for(re int i=1;i<=n;++i){
			cin>>s[i];
			for(re int j=1;j<=m;++j)++a[j][s[i][j-1]-'a']; 
		}
		for(re int i=1;i<n;++i){
			cin>>T;
			for(re int j=1;j<=m;++j)++b[j][T[j-1]-'a']; 
		}
		for(re int i=1;i<=n;++i){
			re bool ia=0;
			for(re int j=1;j<=m;++j)ia|=(a[j][s[i][j-1]-'a']==b[j][s[i][j-1]-'a']);
			if(!ia){
				cout<<s[i]<<'\n';
				break;
			}
		}
	}
}