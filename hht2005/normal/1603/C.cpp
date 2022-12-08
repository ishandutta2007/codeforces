#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,mod=998244353;
int a[N];
struct node {
	int val,sum,siz;
	node(int V,int Sum,int Siz) {
		val=V,sum=Sum,siz=Siz;
	}
};
vector<node>S,T;
int main() {
	int T_T,n;
	scanf("%d",&T_T);
	while(T_T--) {
		int ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",a+i);
		S.clear();
		S.push_back(node(a[n],0,1));
		for(int i=n-1;i>=1;i--) {
			T.clear();
			int las=a[i];
			T.push_back(node(a[i],0,1));
			for(node j:S) {
				int k=(a[i]-1)/j.val+1,val=a[i]/k;
				if(las==val) {
					T[T.size()-1].sum=(T.back().sum+j.sum+1ll*j.siz*(k-1))%mod;
					T[T.size()-1].siz=(T.back().siz+j.siz)%mod;
				} else T.push_back(node(las=val,(j.sum+1ll*j.siz*(k-1))%mod,j.siz));
			}
			for(node j:T)
				ans=(ans+j.sum)%mod;
			S=T;
		}
		printf("%d\n",ans);
	}
	return 0;
}