#include<bits/stdc++.h>
#define re register
using namespace std;
inline int read(){
	re int t=0;re char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
bitset<27>ss;
int n,a[27];
char s[100002];
inline bool check(re int x){
	bitset<27>tmp;
	memset(a,0,sizeof(a));
	tmp.reset();ss.reset();
	for(re int i=1;i<=x;++i)tmp[s[i]-'a']=1,++a[s[i]-'a'];
	ss=tmp;
	for(re int i=x+1;i<=n;++a[s[i]-'a'],tmp[s[i]-'a']=1,ss&=tmp,++i)if(!(--a[s[i-x]-'a']))tmp[s[i-x]-'a']=0;
	return ss.any();
}
int main(){
	scanf("%s",s+1);n=strlen(s+1);
	re int l=1,r=n,ans=0;
	while(l<=r){
		re int mid=l+r>>1;
		if(check(mid))r=mid-1,ans=mid;
		else l=mid+1;
	}
	printf("%d",ans);
}