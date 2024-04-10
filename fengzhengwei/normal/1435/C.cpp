#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e5+5;
const int M=2e5+5;
int lowbit(int i){return i&(-i);}
int n,op[M][2],vis[M];
int a[N],b[N],c[M][6],d[M],sum[M];
int maxx[M];
signed main(){
	for(int i=0;i<6;i++)scanf("%lld",&a[i]);
	sort(a,a+6);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)scanf("%lld",&b[i]);
	sort(b+1,b+n+1);
	int m=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<6;j++)c[i][j]=b[i]-a[j];
		swap(c[i][0],c[i][5]);swap(c[i][1],c[i][4]);swap(c[i][2],c[i][3]);
		//for(int j=0;j<6;j++)cout<<c[i][j]<<" ";
		//cout<<endl;
	}
//	cout<<endl;
	int ans=2e9+5;
	for(int i=0;i<6;i++){
		memset(sum,0,sizeof(sum));
		memset(maxx,0,sizeof(maxx));
		memset(op,0,sizeof(op));
	//	cout<<endl;	
		m=0;
		int tmp=0;
		for(int j=2;j<=n;j++){
			int panda=0;
			for(int k=0;k<6;k++){
				if(c[j][k]==c[1][i]){
					op[j][0]=op[j][1]=0;
					break;
				}
				if(c[j][k]>c[1][i]){
					if(k==0){
						op[j][0]=op[j][1]=c[j][0]-c[1][i];
						tmp=max(tmp,op[j][0]); 
						break;
					}
					op[j][0]=c[j][k-1]-c[1][i];op[j][1]=c[j][k]-c[1][i];
					d[++m]=-op[j][0];
					//cout<<op[j][0]<<" "<<op[j][1]<<endl;
					break;
				}
			}
		}	
		//cout<<tmp<<endl<<endl;
		if(m==0){
			ans=min(ans,tmp);
			continue;
		}		
		sort(d+1,d+m+1);
		m=unique(d+1,d+m+1)-(d+1);
		for(int j=2;j<=n;j++){
			if(op[j][0]>=0)continue;
			int l=lower_bound(d+1,d+m+1,-op[j][0])-d;
			maxx[l]=max(maxx[l],op[j][1]);
		}
		int mx=tmp;
		for(int j=m;j>=0;j--){
			ans=min(ans,mx+d[j]);
			mx=max(mx,maxx[j]);	
		}
	}
	cout<<ans<<endl;
	return 0;
}