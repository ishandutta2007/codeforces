#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 10000010
#define upp (mx+1)/2
#define low mx/2
#define nwc cnt[mx]
ll n,k,i,nw,mx,ans,cnt[N];
inline int rd(){int t;scanf("%d",&t);mx=max(mx,0ll+t);return t;}
int main(){
	//freopen("1.in","r",stdin);
	n=rd(),k=rd(),mx=0;
	for (i=1;i<=n;i++) ++cnt[rd()];
	for (nw=cnt[ans=mx];nw<k&&ans!=0;nw+=cnt[--ans]){
		while (mx>=2 && upp>=ans-1) {
			cnt[upp]+=nwc,cnt[low]+=nwc,nw-=nwc,cnt[mx]=0,mx--;
		}
	} 
	cout<<(ans?ans:-1)<<"\n";
	return 0;
}