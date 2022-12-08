#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10,mod1=1e9+7,mod2=1e9+9;
typedef pair<int,int> pii;
#define mp make_pair
int P1[maxn],P2[maxn],a[maxn],f[maxn],las[maxn],t[maxn],L;
map<pii,vector<int> >pos;
int calc(pii x) {
	if(!pos[x].size())return 0;
	int l=0,r=pos[x].size()-1;
	while(l<=r) {
		int mid=(l+r)>>1;
		if(pos[x][mid]>=L)r=mid-1;
		else l=mid+1;
	}
	return pos[x].size()-r-1;
}
int main() {
	int n,sum1=0,sum2=0;
	long long ans=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	P1[0]=P2[0]=1;
	for(int i=1;i<=n;i++) {
		P1[i]=P1[i-1]*23ll%mod1;
		P2[i]=P2[i-1]*23ll%mod2;
	}//asedfgh
	pos[mp(0,0)].push_back(0);
	for(int i=1;i<=n;i++) {
		las[i]=t[a[i]];
		t[a[i]]=i;
		if(f[a[i]]<2) {
			f[a[i]]++;
			sum1=(sum1+P1[a[i]])%mod1;
			sum2=(sum2+P2[a[i]])%mod2;
		} else {
			f[a[i]]=0;
			sum1=((sum1-2*P1[a[i]])%mod1+mod1)%mod1;
			sum2=((sum2-2*P2[a[i]])%mod2+mod2)%mod2;
		}
		L=max(L,las[las[las[i]]]);
		ans+=calc(mp(sum1,sum2));
		pos[mp(sum1,sum2)].push_back(i);
	}
	printf("%lld\n",ans);
	return 0;
}