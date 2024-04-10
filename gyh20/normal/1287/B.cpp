#include<bits/stdc++.h>
using namespace std;
#define re register
inline int read(){
	re int t=0,f=1;
	re char v=getchar();
	while(v<'0'||v>'9'){
		if(v=='-')f=-1;
	v=getchar();}
	while(v>='0'&&v<='9'){
		t=(t<<3)+(t<<1)+(v^48);
		v=getchar();
	}
	return t*f;
}
int n,k,ans;
char s[2002][32],t[32];
map <string,int> mp;
int main(){
n=read();
k=read();
for(re int i=1;i<=n;++i)scanf("%s",s[i]),mp[s[i]]=1;
 
for(re int i=1;i<=n;++i){
	for(re int j=i+1;j<=n;++j){
		for(re int kk=0;kk<k;++kk){
			if(s[i][kk]!=s[j][kk]){
				t[kk]='S'+'E'+'T'-s[i][kk]-s[j][kk];
			}
			else t[kk]=s[i][kk];
		}
		if(mp[t])++ans;
	}
}
printf("%d",ans/3);
}