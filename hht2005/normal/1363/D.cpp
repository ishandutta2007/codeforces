#include<bits/stdc++.h>
using namespace std;
const int N=10010;
int f[N],ans[N];
vector<int>pos[N];
int main() {
	int T,n,k,M,x;
	scanf("%d",&T);
	while(T--) {
		memset(ans,0,sizeof(ans));
		scanf("%d%d",&n,&k);
		for(int i=1;i<=k;i++) {
			cin>>M;
			pos[i].clear();
			for(int j=1;j<=M;j++) {
				cin>>x;
				pos[i].push_back(x);
			}
		}
		cout<<"? "<<n;
		for(int i=1;i<=n;i++)
			cout<<' '<<i;
		cout<<endl;
		cin>>M;
		int l=1,r=n-1;
		while(l<=r) {
			int mid=(l+r)>>1;
			cout<<"? "<<mid;
			for(int i=1;i<=mid;i++)
				cout<<' '<<i;
			cout<<endl;
			cin>>x;
			if(x==M)r=mid-1;
			else l=mid+1;
		}
		r++;
		for(int i=1;i<=k;i++) {
			int fl=0;
			for(int j:pos[i])
				if(j==r)fl=1;
			if(fl==1) {
				cout<<"? "<<n-pos[i].size();
				memset(f,0,sizeof(f));
				for(int j:pos[i])f[j]=1;
				for(int i=1;i<=n;i++)
					if(!f[i])cout<<' '<<i;
				cout<<endl;
				cin>>ans[i];
				break;
			}
		}
		cout<<"!";
		for(int i=1;i<=k;i++) {
			if(!ans[i])cout<<' '<<M;
			else cout<<' '<<ans[i];
		}
		cout<<endl;
		scanf("%*s");
	}
	return 0;
}