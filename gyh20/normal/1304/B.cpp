#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0'){
	t=(t<<3)+(t<<1)+v-48;
	v=getchar();}
	return t;
}
map<string,int>mp;
int t,n,f[200002],k,cnt,tot;
char ans1[202][52],hw[202][52],ans[202][52];
char s[102][52];
int main(){
	n=read();
	k=read();
	for(re int i=1;i<=n;++i){
		scanf("%s",s[i]+1);
		mp[s[i]+1]=1;
	}
	for(re int i=1;i<=n;++i){
		bool ia=0;
		for(re int j=1;j<=k;++j){
			if(s[i][j]!=s[i][k-j+1]){
				ia=1;
				break;
			}
		}
		if(!ia){
			++tot;
			for(re int j=1;j<=k;++j)hw[tot][j]=s[i][j];
			continue;
		}
		if(mp[s[i]+1]){
			++cnt;
			--mp[s[i]+1];
			for(re int j=1;j<=k;++j)ans[cnt][j]=s[i][j];
			reverse(s[i]+1,s[i]+k+1);
			
			if(mp[s[i]+1]){
			--mp[s[i]+1];
			for(re int j=1;j<=k;++j)ans1[cnt][j]=s[i][j];
				}
			else --cnt;
		}
	}
	if(tot>1)tot=1;
	printf("%d\n",(tot+cnt+cnt)*k);
	for(re int i=1;i<=cnt;++i){printf("%s",ans[i]+1);
	}
	for(re int i=1;i<=tot;++i){printf("%s",hw[i]+1);
	}
	for(re int i=1;i<=cnt;++i){printf("%s",ans1[cnt-i+1]+1);
	}
}