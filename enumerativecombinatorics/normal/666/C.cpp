#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<queue>
#include<string>
#include<string.h>
#include<vector>
#include<set>
#include<map>
#include<stdlib.h>
using namespace std;
const long long mod=1000000007;
const long long inf=mod*mod;
char in[110000];
int n;
int sz=0;
pair<pair<int,int>,int>p[110000];
int ans[110000];
int SQ=300;
long long fact[110000];
long long inv[110000];
long long finv[110000];
long long C(int a,int b){
	return fact[a]*finv[b]%mod*finv[a-b]%mod;
}
long long val[110000];
long long sum[110000];
long long p26[110000];
long long p25[110000];
int main(){
	fact[0]=finv[0]=1;
	p26[0]=1;
	p25[0]=1;
	inv[1]=1;
	for(int i=2;i<110000;i++)inv[i]=(mod-(mod/i)*inv[mod%i]%mod)%mod;
	for(int i=1;i<110000;i++){
		fact[i]=fact[i-1]*i%mod;
		finv[i]=finv[i-1]*inv[i]%mod;
		p26[i]=p26[i-1]*26%mod;
		p25[i]=p25[i-1]*25%mod;
	}
	int a;scanf("%d",&a);
	scanf("%s",in);
	n=strlen(in);
	while(a--){
		int t;scanf("%d",&t);
		if(t==1){
			scanf("%s",in);
			n=strlen(in);
		}else{
			int b;scanf("%d",&b);
			p[sz]=make_pair(make_pair(b,n),sz);
			sz++;
		}
	}
	std::sort(p,p+sz);
	int at=0;
	for(int i=0;i<340;i++){
		long long ks=1;
		for(int j=i*SQ;j>=0;j--){
			val[j]=C(i*SQ,j)*ks;
			ks=ks*25%mod;
		}
		for(int j=0;j<=i*SQ;j++){
			sum[j]=val[j];
			if(j)sum[j]=(sum[j]+sum[j-1])%mod;
		}
		while(at<sz&&p[at].first.first<(i+1)*SQ){

			if(p[at].first.first<p[at].first.second){
				at++;continue;
			}
			long long now=sum[min(i*SQ,p[at].first.second-1)];

			int r=min(i*SQ,p[at].first.second-1);
			for(int j=0;j<p[at].first.first%SQ;j++){
				if(r==p[at].first.second-1){
					now=now*26%mod;
					now=(now+mod-C(i*SQ+j,r)*p25[i*SQ+j-r]%mod)%mod;
				}else{
					now=now*26%mod;
					r++;
				}
			}

			ans[p[at].second]=(p26[p[at].first.first]+mod-now)%mod;
			at++;
		}
	}
	for(int i=0;i<sz;i++)printf("%d\n",ans[i]);
}