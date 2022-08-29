#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#define re register
#define int long long
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
int n,a[66],m,x,cnt,sum,ans,b[66],c[66];
signed main(){
	int t=read();
	while(t--){
		n=read();m=read();
		ans=0;
		memset(c,0,sizeof(c));
		for(re int i=1;i<=m;++i){
			x=read();
			cnt=0;
			while(x){
				x>>=1;
				++cnt;
			}
			--cnt;
			++c[cnt];
		}
		bool ia=0;
		for(re int i=0;i<=62;++i){
			if(n&(1ll<<i)){
			
			if(!c[i]){
				for(re int j=i+1;j<=62;++j){
					if(c[j]){
						c[i]+=1ll<<(j-i);
						ans+=j-i;
						--c[j];
						break;
					}
				}
			}
			if(!c[i]){
				ia=1;
				puts("-1");
				break;
			}--c[i];}
			c[i+1]+=c[i]/2;
		}
		if(!ia)printf("%lld\n",ans);
	}
}