#include<bits/stdc++.h>
using namespace std;

const int N=110,maxn=45;
int f[N],a[N],Cnt[N],Cnt2[N];bool bk[N];

bool check(){
	int Max=0;
	for(int i=maxn;i>=0;i--)
		if(Cnt[i]) {Max=i;break;}
	for(int i=0;i<=Max;i++)
		if(Cnt[i]!=1) return false;
	return true;
}

int main()
{
   
	f[0]=f[1]=1;for(int i=2;i<=maxn;i++) f[i]=f[i-1]+f[i-2];
   
	int T;
	scanf("%d",&T);
	while(T--){
   		int n;scanf("%d",&n);
   		memset(Cnt,0,sizeof(Cnt));
   		for(int i=0;i<=maxn;i++) bk[i]=false;
   		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			for(int j=maxn;j>=0;j--){
				if(a[i]>=f[j]){
					if(a[i]==f[j]) bk[j]=true;
					Cnt[j]++;
					a[i]-=f[j];
				}
			}
		}
		
		for(int i=0;i<=maxn;i++) Cnt2[i]=Cnt[i];
		
		bool pd=false;
		if(check()) pd=true;
		for(int i=1;i<=maxn;i+=2)
			if(bk[i]){
				for(int j=0;j<=maxn;j++) Cnt[j]=Cnt2[j];
				Cnt[i]--;
				for(int j=i-1;j>=0;j-=2) Cnt[j]++;
				if(check()) pd=true;
			}
   		
   		if(pd) printf("YES\n");
   		else printf("NO\n");
	}
	
}