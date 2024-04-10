#include<cstdio>
#include<cstring>
using namespace std;

const int N=2e5+100;
int a[N],Cnt[N],qz[N];

int main()
{
	
	int T;
	scanf("%d",&T);
	while(T--){
		int n,K;
		scanf("%d%d",&n,&K);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) Cnt[i]=0;
		for(int i=1;i<=n;i++) Cnt[a[i]]++;
		qz[0]=0;for(int i=1;i<=n;i++) qz[i]=qz[i-1]+Cnt[i];
		int id=0,Ans=1e9,Ans1;
		for(int i=1;i<=n;i++){
			while(id<i&&2*(qz[i]-qz[id+1])-qz[n]>=K) id++;
			if(2*(qz[i]-qz[id])-qz[n]>=K){
				if(Ans>i-id) Ans=i-id,Ans1=i;
			}
		}
		printf("%d %d\n",Ans1-Ans+1,Ans1);
		int L=Ans1-Ans+1,R=Ans1,Sum=0,las=0;
		for(int i=1;i<=n;i++){
			if(a[i]>=L&&a[i]<=R) Sum++;
			else Sum--;
			if(Sum==1){
				Sum=0;
				if(K==1){
					printf("%d %d\n",las+1,n);
					break;
				}
				else{
					printf("%d %d\n",las+1,i);
					las=i;
				}
				K--;
			}
		}
	}
	
	return 0;
}