#include<bits/stdc++.h>
using namespace std;
#define N 300030
int a[N],n,Q;
vector<int> pos[N];
mt19937 rnd(time(0));
inline int rd(int l,int r){
	return l+rnd()%(r-l+1);
}
int main(){
	scanf("%d %d",&n,&Q);
	for(int i=1;i<=n;++i){
		scanf("%d",a+i);
		pos[a[i]].push_back(i);
	}
	while(Q--){
		int l,r;
		scanf("%d %d",&l,&r);
		int mx=0;
		for(int i=1;i<=40;++i){
			int x=rd(l,r);
			int w=a[x];
			mx=max(mx,(int)(upper_bound(pos[w].begin(),pos[w].end(),r)-lower_bound(pos[w].begin(),pos[w].end(),l)));
		}
		int len=r-l+1;
		printf("%d\n",mx>(len+1)/2?mx-(len-mx+1)+1:1);
	}
	return 0;
}