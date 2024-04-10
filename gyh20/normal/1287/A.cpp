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
int n,k;
char s[100002];
int main(){
n=read();
while(n--){
	k=read();
	int ans=0;
	scanf("%s",s+1);
	for(re int i=1;i<=k;++i){
		if(s[i]=='A'){
			int tmp=i+1,pp=0;
			while(tmp<=k&&s[tmp]=='P')++tmp,++pp;
			ans=max(ans,pp);
		}
	}
	printf("%d\n",ans);
}
}