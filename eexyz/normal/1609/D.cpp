#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define ls k<<1
#define rs k<<1|1
#define mid (l+r>>1)
#define py cout<<"YES\n"
#define pn cout<<"NO\n"
#define ll long long
int n,d,i,j,qwq,ans,c[N],x[N],y[N],f[N]; 
int find(int x){if(f[x]^x)f[x]=find(f[x]);return f[x];}
inline bool cmp(int x,int y){return x>y;}
int main(){
	cin>>n>>d;
	for(i=1;i<=d;++i){
		cin>>x[i]>>y[i];
		for(j=1;j<=n;++j)f[j]=j,c[j]=1;
		qwq=0;
		for(j=1;j<=i;++j){
			int i=j;
			if(find(x[i])!=find(y[i]))c[f[y[i]]]+=c[f[x[i]]],c[f[x[i]]]=0,f[f[x[i]]]=f[y[i]];
			else ++qwq;
		}
//		for(j=1;j<=n;++j)cout<<c[j]<<" ";
		sort(c+1,c+n+1,cmp);
		ans=0;
		for(j=1;j<=qwq+1;++j)ans+=c[j];
		cout<<ans-1<<"\n";
	}
}