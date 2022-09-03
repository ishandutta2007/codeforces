#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
int main(){
	char c[300005];
	scanf("%s",c);
	int n=strlen(c);
	vector<int> v[2];
	int ans[300005];
	fill(ans,ans+n+1,n);
	for(int i = 0;c[i]!=0;i++){
		v[c[i]-'0'].pb(i);
	}
	LL tot=0;
	for(int i = 0;c[i]!=0;i++){
		for(int j = i;j<i+10&&c[j]!=0;j++){
			for(int k = j+1;k<i+10&&c[k]!=0;k++){
				int kk=k-j+k;
				if(kk>=i+10||kk>=n){
					break;
				}
			//	printf("%d %d %d %d\n",i,j,k,kk);
				if(c[j]==c[k]&&c[k]==c[kk]){
					ans[i]=min(ans[i],kk);
				}
			}
		}
	//	printf("%d\n",ans[i]);
		tot+=n-ans[i];
	}
	printf("%lld\n",tot);
}