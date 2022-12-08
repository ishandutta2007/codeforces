#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10,mod=998244353;
int jp[maxn][20],a[maxn],c[maxn];
int main() {
	srand(time(0));
	int q,opt,v,w;
	scanf("%d%d%d",&q,a,c);
	for(int i=1;i<=q;i++) {
		scanf("%d",&opt);
		if(opt==1) {
			scanf("%d%d%d",jp[i],a+i,c+i);
			for(int j=1;j<20;j++)
				jp[i][j]=jp[jp[i][j-1]][j-1];
		} else {
			scanf("%d%d",&v,&w);
			long long ans1=0,ans2=0;
			while(w&&a[v]) {
				int p=v;
				for(int i=19;i>=0;i--)
					if(a[jp[p][i]])p=jp[p][i];
				int t=min(w,a[p]);
				w-=t,a[p]-=t;
				ans1+=t;
				ans2+=1ll*t*c[p];
			}
			cout<<ans1<<' '<<ans2<<endl;
		}
	}
	return 0;
}