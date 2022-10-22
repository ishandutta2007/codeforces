#include<bits/stdc++.h>
using namespace std;

const int N=1e5+100;
int a[N],Cnt[N],sta[N],tot;
bool cmp(int n1,int n2) {return (n1<n2);}

map<int,int> B;

int main()
{
	
	int T;scanf("%d",&T);
	while(T--){
		int n,K;
		scanf("%d%d",&n,&K);
		
		for(int i=1;i<=n;i++) scanf("%d",&a[i]),B[a[i]]++;
		sort(a+1,a+n+1,cmp);
		
		for(int i=0;i<=n;i++) Cnt[i]=0;
		
		int las=0,Sum3=0;a[n+1]=-1;
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]){
				Cnt[i-las]++;
				las=i;Sum3++;
			}
		}
		
		tot=0;
		for(int i=1;i<=n;i++)
			if(Cnt[i]) sta[++tot]=i;
		
		int Sum=0,all=n,Ans=1e9;
		for(int i=0;i<=n;i++){
			if(Sum<=K){
				int e=K,Sum2=0;
				for(int j=1;j<=tot;j++){
					int t=Cnt[sta[j]]*sta[j];
					if(e>t) e-=t,Sum2+=Cnt[sta[j]];
					else {Sum2=Sum2+(e/sta[j]);break;}
				}
				if(Ans>Sum3-Sum2) Ans=Sum3-Sum2;
			}
			if(B[i]==0) Sum++;
			all-=B[i];
			if(B[i]) Cnt[B[i]]--,Sum3--;
		}
		
		printf("%d\n",Ans);
		
		B.clear();
	}
	
	return 0;
}