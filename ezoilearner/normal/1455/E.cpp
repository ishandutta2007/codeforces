#include<bits/stdc++.h>
using namespace std;
typedef pair<int,bool> pib;
typedef long long ll;
int n;
#define FR first
#define SE second 
#define cout cerr

int x[4],y[4];
pib b[4],c[4];

pib calc(pib h1,pib h2){
	if(h1.SE==h2.SE)return pib(abs(h1.FR-h2.FR),0);
	if(h1.SE>h2.SE)return pib(h1.FR-h2.FR,1);
	else return pib(h2.FR-h1.FR,1);
}

inline void rd(int &x){
	x=0;char ch=getchar();int f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

int main(){
	int T;rd(T);
	while(T--){
		for(int i=0;i<4;++i){
			rd(x[i]);rd(y[i]);
		}
		ll Ans=1000000000000ll;
		for(int i=0;i<4;++i)
			for(int j=0;j<4;++j)
				if(j!=i)
					for(int k=0;k<4;++k)
						if(k!=j&&k!=i)
						for(int l=0;l<4;++l)
							if(l!=i&&l!=j&&l!=k){
							b[0]=pib(x[i],0);b[1]=pib(x[j],0);b[2]=pib(x[k],1);b[3]=pib(x[l],1);
							c[0]=pib(y[i],0);c[1]=pib(y[k],0);c[2]=pib(y[j],1);c[3]=pib(y[l],1);
							for(int t1=0;t1<4;++t1)
								for(int t2=0;t2<4;++t2){
									ll res=0;
									int h[20],cnt=0;
									for(int t=0;t<4;++t){
										pib tmp=calc(b[t1],b[t]);
										if(!tmp.SE)res+=tmp.first;
										else h[++cnt]=tmp.first;
										tmp=calc(c[t2],c[t]);
										if(!tmp.SE)res+=tmp.first;
										else h[++cnt]=tmp.first;
									}
									sort(h+1,h+cnt+1);
									for(int t=1;t<=cnt;++t)res+=abs(h[t]-h[(cnt+1)/2]);
									Ans=min(Ans,res);
								}
						}
		printf("%lld\n",Ans);
	}
	return 0;
}