#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
using namespace std;
const int mod=998244353,B=1000,T=(100000+B-1)/B;
typedef pair<int,int> pr;
typedef long long ll;
int n,a[100005],b[100005],ans=1,A[100005],C[100005];
inline void Sort(int A[],const int n){
	register int *i,j,ma[65536]={0},mb[65536]={0};
	for(i=A+n;i!=A;--i)++ma[(*i)&65535],++mb[(*i)>>16&65535];
	for(j=1;j<65536;++j)ma[j]+=ma[j-1],mb[j]+=mb[j-1];
	for(i=A+n;i!=A;--i)C[ma[(*i)&65535]--]=*i;
	for(i=C+n;i!=C;--i)A[mb[(*i)>>16&65535]--]=*i;
}
int main(){
	scanf("%d",&n);
	//n=1e5;
	for(int i=1;i<=n;i++){
		//a[i]=(i%(T-1)+1)*(B+1);
		scanf("%d",&a[i]);
	}
	for(int i=-B;i<=B;i++){
		for(int j=1;j<=n;j++)b[j]=a[j]-j*i+B*n;
		Sort(b,n);
		//sort(b+1,b+n+1);
		for(int j=1,k;j<=n;j=k+1){
			k=j;
			while(k<n&&b[k+1]==b[j])k++;
			ans=max(ans,k-j+1);
		}
	}
	//puts("PP");
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=i+T&&j<=n;j++){
			int t=(a[j]-a[i])/(j-i);
			if(t*(j-i)!=a[j]-a[i]||abs(t)<=B)continue;
			int x=i,y=a[i],s=1;
			while(x>1&&y-t>=1&&y-t<=100000)x--,y-=t,s+=a[x]==y;
			x=i,y=a[i];
			while(x<n&&y+t<=100000&&y+t>=1)x++,y+=t,s+=a[x]==y;
			ans=max(ans,s);
		}
	}
	cout<<n-ans;
}