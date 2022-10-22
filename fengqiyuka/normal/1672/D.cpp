#include<bits/stdc++.h>
using namespace std;

const int N=2e5+100;
int a[N],b[N],sta1[N],sta2[N],Cnt1[N],Cnt2[N];bool bk[N];

int main()
{
	int T;scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++) scanf("%d",&b[i]);
		
		for(int i=1;i<=n;i++) Cnt1[i]=Cnt2[i]=0;
		for(int i=1;i<=n;i++) Cnt1[a[i]]++;
		int id=n;bool pd=true;b[n+1]=0;
		for(int i=n;i>=1;i--){
			if(b[i]!=b[i+1]){
				while(id&&b[i]!=a[id]){
					if(Cnt2[a[id]]==0) {pd=false;break;}
					Cnt2[a[id]]--;
					id--;
				}
				if(!id) pd=false;
				if(!pd) break;
				id--;
				Cnt1[b[i]]--;
			}
			else{
				Cnt1[b[i]]--;Cnt2[b[i]]++;
			}
		}
		
		/*for(int i=1;i<=n;i++) bk[i]=true,Cnt1[i]=Cnt2[i]=0;
		int tot1=0,tot2=0;
		for(int i=n;i>=1;i--){
			if(bk[a[i]]) sta1[++tot1]=a[i];
			bk[a[i]]=false;
		}
		for(int i=1;i<=n;i++) bk[i]=true;
		for(int i=n;i>=1;i--){
			if(bk[b[i]]) sta2[++tot2]=b[i];
			bk[b[i]]=false;
		}
		bool pd=true;a[n+1]=b[n+1]=0;
		for(int i=n;i>=1;i--){
			if(a[i]!=a[i+1]) Cnt1[a[i]]++;
			if(b[i]!=b[i+1]) Cnt2[b[i]]++;
			if(Cnt1[a[i]]<Cnt2[a[i]])
				pd=false;
			if(Cnt1[b[i]]<Cnt2[b[i]])
				pd=false;
		}
		for(int i=1;i<=tot1;i++)
			if(sta1[i]!=sta2[i]) {pd=false;break;}*/
		if(pd) printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}