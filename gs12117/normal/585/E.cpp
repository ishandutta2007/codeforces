#include<stdio.h>
int n;
int a[500100];
int pf[500100][10];
int pfn[500100];
int ers[10001000];
int cnt[10001000];
int srs[10001000];
int pp[1000];
int mod=1000000007;
int ans;
int ppf[10];
int mpw(int x){
	if(x==0)return 1;
	long long int z=mpw(x/2);
	z*=z;
	z%=mod;
	if(x%2==1){
		z*=2;
		z%=mod;
	}
	return z;
}
int main(){
	int i,j,k,v;
	for(i=2;i<10000100;i++){
		if(ers[i]==0){
			ers[i]=i;
			if(10000100/i/i==0)continue;
			for(j=i*i;j<10000100;j+=i){
				ers[j]=i;
			}
		}
	}
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
		j=a[i];
		while(j!=1){
			for(k=0;k<pfn[i];k++){
				if(pf[i][k]==ers[j])break;
			}
			if(k==pfn[i]){
				pf[i][pfn[i]]=ers[j];
				pfn[i]++;
			}
			j/=ers[j];
		}
		pp[0]=1;
		cnt[1]++;
		for(j=0;j<pfn[i];j++){
			for(k=0;k<(1<<j);k++){
				pp[k+(1<<j)]=pp[k]*pf[i][j];
				cnt[pp[k+(1<<j)]]++;
			}
		}
	}
	for(i=2;i<10000100;i++){
		if(cnt[i]!=0){
			j=i;
			int ppn=0;
			while(j!=1){
				for(k=0;k<ppn;k++){
					if(ppf[k]==ers[j])break;
				}
				if(k==ppn){
					ppf[ppn]=ers[j];
					ppn++;
				}
				j/=ers[j];
			}
			pp[0]=1;
			srs[i]=0;
			for(j=0;j<ppn;j++){
				for(k=0;k<(1<<j);k++){
					pp[k+(1<<j)]=-pp[k]*ppf[j];
				}
			}
			for(j=0;j<(1<<ppn);j++){
				if(pp[j]>0){
					srs[i]+=cnt[pp[j]];
				}
				else{
					srs[i]-=cnt[-pp[j]];
				}
			}
		}
	}
	for(i=10000100;i>=2;i--){
		if(cnt[i]!=0){
			cnt[i]=mpw(cnt[i]);
			cnt[i]+=mod-1;
			cnt[i]%=mod;
			for(j=i*2;j<10000100;j+=i){
				cnt[i]+=mod-cnt[j];
				cnt[i]%=mod;
			}
			ans+=(long long int)cnt[i]*srs[i]%mod;
			ans%=mod;
		}
	}
	printf("%d",ans);
}