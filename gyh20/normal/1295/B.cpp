#include<bits/stdc++.h>
#include<map>
#define re register
#define int long long
using namespace std;
inline int read(){
	re int t=0,f=0;
	re char v=getchar();
	while(v<'0')f|=(v=='-'),v=getchar();
	while(v>='0'){
		t=(t<<3)+(t<<1)+v-48;
		v=getchar();
	}
	return f?-t:t;
}
int n,t,x,ans,mx,mn;
char s[100002];
int mp[200002];
int cnt0,cnt1;
signed main(){
	t=read();
	while(t--){
		n=read();
		mx=0;
		mn=0;
		x=read();
		memset(mp,0,sizeof(mp));
		cnt0=cnt1=ans=0;
		scanf("%s",s+1);
		for(re int i=1;i<=n;++i){
			if(s[i]=='0')++cnt0;
			else ++cnt1;
			
		}
		int tmp=cnt0-cnt1;
		cnt0=cnt1=0;
		if(tmp==0){
			bool ia=0;
			for(re int i=1;i<=n;++i){
			if(s[i]=='0')++cnt0;
			else ++cnt1;
			if(cnt0-cnt1==x){
				puts("-1");
				ia=1;
				break;
			}
			
		}
		if(!ia)
		puts("0");
		continue;
		}
		if(x==0)++ans;
		for(re int i=1;i<=n;++i){
			if(s[i]=='0')++cnt0;
			else ++cnt1;
			if((x-cnt0+cnt1)*tmp>=0){
				if((x-cnt0+cnt1)%tmp==0)++ans;
			}
		}
		printf("%lld\n",ans);
	}
}