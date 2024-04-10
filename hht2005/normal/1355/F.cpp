#include<bits/stdc++.h>
using namespace std;
const int N=794;
int f[N+10],p[N],pri[N];
int main() {
	long long M=1e18+1;
	int cnt=0;
	for(int i=2;i<=N;i++)
		if(!f[i]) {
			p[++cnt]=i;
			for(int j=i;j<=N;j+=i)
				f[j]=1;
		}
	int T;
	scanf("%d",&T);
	while(T--) {
		int cc=0;
		for(int i=1,j=0;i<=cnt;i=j) {
			long long sum=1,g=0;
			for(j=i;j<=cnt;j++)
				if(sum>M/p[j])break;
				else sum*=p[j];
			cout<<"? "<<sum<<endl;
			scanf("%lld",&g);
			for(int k=i;k<j;k++)
				if(g%p[k]==0)pri[++cc]=p[k];
		}
		int ans=1;
		for(int i=1;i<=cc;i++) {
			int j=min(i+5,cc);
			long long S=1,T;
			for(int k=i;k<=j;k++) {
				int sum=1;
				while(sum*pri[k]<=1024)sum*=pri[k];
				S*=sum;
			}
			cout<<"? "<<S<<endl;
			cin>>T;
			for(int k=i;k<=j;k++) {
				int sum=1;
				while(T%pri[k]==0)sum++,T/=pri[k];
				ans*=sum;
			}
			i=j;
		}
		if(ans==0)puts("! 9");
		else printf("! %d\n",2*ans);
	}
	return 0;
}