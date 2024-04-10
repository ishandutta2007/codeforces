#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define re register
#define in inline
using namespace std;
in int read(){
	re int t=0;
	re char v=getchar();
	while(v<'0'||v>'9')v=getchar();
	while(v>='0'&&v<='9'){
		t=(t<<3)+(t<<1)+(v^48);
		v=getchar();
	}
	return t;
}
int n,f[100002][8],ans;
char s[100002];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",s+1),n=strlen(s+1);ans=0;re int la=-1;s[n+1]=0;
		for(re int i=2;i<=n;++i){
			if(s[i]==s[i-1])++ans,la=i,s[i]=0;
			else if(i>2&&s[i]==s[i-2])++ans,la=i,s[i]=0;
		}
		printf("%d\n",ans);
	}
}