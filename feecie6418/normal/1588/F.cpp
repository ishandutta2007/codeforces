#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f,B=500;
int O[200005],A[200005],C[200005],is[200005],is2[200005],vst[200005];
int n,p[200005],q,bel[200005],to[1505],ins[200005];
ll s[200005],cnt[1505][1505],tag[1505],a[200005];
void Solve(int tl,int tr){
	for(int i=tl;i<=tr;i++){
		if(O[i]==1)is[A[i]]=is[C[i]+1]=1;
		if(O[i]==2)is2[A[i]]=1;
		if(O[i]==3)is2[A[i]]=is2[C[i]]=1;
	}
	int Bcnt=0,scnt=0;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		if(is[i]||i==1)++Bcnt;
		bel[i]=Bcnt;
	}
	for(int i=1;i<=n;i++){
		if(!is2[i])continue;
		++scnt;
		int j=p[i];
		cnt[scnt][bel[j]]++,ins[j]=scnt;
		while(!is2[j])j=p[j],cnt[scnt][bel[j]]++,ins[j]=scnt;
	}
	for(int i=1;i<=n;i++)if(is2[i])to[ins[i]]=ins[p[i]];
	for(int i=1;i<=scnt;i++)for(int j=1;j<=Bcnt;j++)cnt[i][j]+=cnt[i][j-1];
	for(int i=tl;i<=tr;i++){
		if(O[i]==1){
			ll sum=s[C[i]]-s[A[i]-1];
			int b1=bel[C[i]],b2=bel[A[i]-1];
			for(int j=1;j<=scnt;j++)sum+=tag[j]*(cnt[j][b1]-cnt[j][b2]);
			printf("%lld\n",sum);
		}
		if(O[i]==2){
			int x=ins[A[i]];
			tag[x]+=C[i],x=to[x];
			while(x!=ins[A[i]])tag[x]+=C[i],x=to[x];
		}
		if(O[i]==3){
			swap(to[ins[A[i]]],to[ins[C[i]]]),swap(p[A[i]],p[C[i]]);
		}
	}
	for(int i=1;i<=n;i++)a[i]+=tag[ins[i]],is[i]=is2[i]=ins[i]=0;
	for(int i=1;i<=scnt;i++){
		tag[i]=0;
		for(int j=1;j<=Bcnt;j++)cnt[i][j]=0;
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&p[i]);
	scanf("%d",&q);
	for(int i=1,lst=0;i<=q;i++){
		scanf("%d%d%d",&O[i],&A[i],&C[i]);
		if(i==q||i%B==0)Solve(lst+1,i),lst=i;
	}
}