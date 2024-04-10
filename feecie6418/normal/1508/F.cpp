#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
int n,a[25005],q,R[25005],prepre[25005],nxtpre[25005],presuc[25005],nxtsuc[25005],ans=0;
void Dd(int x,int y){ans-=nxtpre[x]==y&&presuc[y]==x;}
void Dx(int x,int y){ans-=nxtsuc[x]==y&&prepre[y]==x;}
int main(){
	scanf("%d%d",&n,&q),a[n+1]=n+1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),R[i]=i,presuc[i]=nxtsuc[i]=n+1;
	for(int i=1,l,r;i<=q;i++){
		scanf("%d%d",&l,&r);
		int j=l;
		while(j<r&&R[j+1]<r)j++;
		for(;j>=l;j--){
			while(R[j]<r){
				R[j]++;
				if(a[R[j]]<a[j]){
					if(a[R[j]]>a[nxtpre[j]]){
						Dd(j,nxtpre[j]),nxtpre[j]=R[j];
						if(a[j]<a[presuc[R[j]]])Dd(presuc[R[j]],R[j]),presuc[R[j]]=j,ans++;
					}
				}
				else {
					if(a[R[j]]<a[nxtsuc[j]]){
						Dx(j,nxtsuc[j]),nxtsuc[j]=R[j];
						if(a[j]>a[prepre[R[j]]])Dx(prepre[R[j]],R[j]),prepre[R[j]]=j,ans++;
					}
				}
			}
		}
		cout<<ans<<'\n';
	}
}