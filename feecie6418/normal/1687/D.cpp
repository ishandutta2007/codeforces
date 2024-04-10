#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7,N=2000000;
int n,pre[2000005],nxt[2000005];
ll a[1000005];
int main(){
	scanf("%d",&n),pre[0]=-1;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		pre[a[i]-a[1]]=nxt[a[i]-a[1]]=a[i]-a[1];
	}
	for(int i=1;i<=N;i++)if(!pre[i])pre[i]=pre[i-1];
	nxt[N+1]=N+1;
	for(int i=N;i>=0;i--)if(!nxt[i])nxt[i]=nxt[i+1];
	for(int i=1;;i++){
		if(1ll*i*i+i<a[1])continue;
		ll l=max(a[1],1ll*i*i),r=1ll*i*(i+1);
		ll kl=l,kr=r,lstr=0,ok=1;
		for(int j=i;;j++){
			//cout<<j<<' '<<ok<<' '<<'\n';
			ll tl=1ll*j*j,tr=tl+j;
			ll nl=max(0ll,tl-r),nr=tr-l;
			if(nl>N)break;
			if(lstr<nl){
				if(pre[nl-1]>lstr){
					ok=0;
					break;
				}
			}
			lstr=nr,nr=min(nr,(ll)N);
			//cout<<nl<<' '<<nr<<'\n';
			if(pre[nr]<nl)continue;
			nl=nxt[nl],nr=pre[nr];
			kr=min(kr,tr-nr);
			kl=max(kl,tl-nl);
			if(kl>kr){
				ok=0;
				break;
			}
			//cout<<"kl kr"<<kl<<' '<<kr<<'\n';
		}
		if(ok){
			cout<<kl-a[1]<<'\n';
			break;
		}
	}
}