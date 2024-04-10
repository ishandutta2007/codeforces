#include<bits/stdc++.h>
using namespace std;
#define N 5005
const int B=5000;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m,cnt[N],ntp[N],p[N],pos[N],pn;
vector<int> d[N];
ll ans;
unordered_set<int> S;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		++cnt[read()];	
	}
	for(int i=2;i<=B;++i){
		if(!ntp[i]){
			p[++pn]=i;
			for(int j=i+i;j<=B;j+=i)ntp[j]=1;
			for(int j=i;j<=B;j*=i){
				for(int k=j;k<=B;k+=j){
					for(int p=k;p<=B;++p)d[p].push_back(i);	
				}
			}
		}
	}
	for(int i=0;i<=B;++i){
		pos[i]=(int)d[i].size()-1;
		ans+=1LL*cnt[i]*d[i].size();
		if(cnt[i]&&pos[i]>=0)S.insert(i);
	}
	int las=B;
	while(true){
		static int c[N];
		for(int i=1;i<=pn;++i)c[p[i]]=0;
		for(auto i:S){
			if(pos[i]>=0)c[d[i][pos[i]]]+=cnt[i];
		}
		bool ok=false;
		for(int i=1;i<=las;++i){
			if(c[i]>n/2){
				ok=true;
				las=i;
				ans-=c[i]-(n-c[i]);
				static vector<int> bin;
				bin.clear();
				for(auto j:S){
					if(pos[j]<0||d[j][pos[j]]!=i)bin.push_back(j);
					else --pos[j];
				}
				for(auto x:bin)cnt[x]=0,S.erase(x);
				break;
			}	
		}
		if(!ok)break;
	}
	printf("%lld\n",ans);
	return 0;
}