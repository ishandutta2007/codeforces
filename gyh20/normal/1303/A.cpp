#include<cstdio>
#include<cstring>
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
int n,t,fst,lst,ans;
char s[100002];
int main(){
	int t=read();
	while(t--){
	scanf("%s",s+1);
	n=strlen(s+1);
	fst=lst=ans=0;
	for(re int i=1;i<=n;++i){
		if(s[i]=='1'){
			if(!fst)fst=i;
			lst=i;
		}
	}
	for(re int i=fst;i<=lst;++i)if(s[i]=='0')++ans;
	printf("%d\n",ans);
		}
}