#include<cstdio>
#include<algorithm>
#include<vector>
#include<cmath>
using namespace std;
#define pb push_back

const int st=2005;
int t[st],wa[st];
int n,k,MA;


bool test(int roz)
{
	if(roz==0){
		for(int i=1;i<=n;++i){
			int licz=0;
			for(int j=1;j<=n;++j)
				if(wa[i]==wa[j])licz++;
			if(n-licz<=k)return 1;
		}
		return 0;
	}
	t[0]=0;
	int pom=MA/roz;
	for(int i=1;i<=n;++i){
		t[i]=i-1;
		for(int j=1;j<i;++j)
			if(abs(wa[i]-wa[j])<=roz*(i-j) || i-j>pom)
				t[i]=min(t[i],t[j]);
		for(int j=0;j<i;++j)t[j]++;
	}
	for(int i=0;i<=n;++i)if(t[i]<=k)return 1;
	return 0;
}

int main()
{
	scanf("%d%d",&n,&k);
	int mini=1e9,maxi=-1e9;
	for(int i=1;i<=n;++i){
		scanf("%d",&wa[i]);
		mini=min(mini,wa[i]);
		maxi=max(maxi,wa[i]);
	}
	MA=maxi-mini;
	int low=0,high=MA;
	while(low!=high){
		long long pom=low;
		pom+=(long long)high;
		pom/=2LL;
		int med=(int)pom;
		if(test(med))high=med;
		else low=med+1;
	}
	printf("%d",low);
	return 0;
}