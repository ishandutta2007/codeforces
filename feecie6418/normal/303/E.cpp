#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector<db> poly;
db ans[85],f[85][85];
int l[85],r[85],a[165],n,m;
int main(){
	//freopen("1.out","w",stdout);
	//n=6;
	cin>>n;
	for(int i=1;i<=n;i++){
		//l[i]=rand(),r[i]=rand();
		//if(l[i]>r[i])swap(l[i],r[i]);
		cin>>l[i]>>r[i];
		a[++m]=l[i],a[++m]=r[i];
	}
	sort(a+1,a+m+1),m=unique(a+1,a+m+1)-a-1;
	for(int i=1;i<=n;i++){
		fill(ans,ans+n+1,0);
		for(int j=1;j<m;j++){
			if(l[i]>=a[j+1]||r[i]<=a[j])continue;
			memset(f,0,sizeof(f));
			f[0][0]=1.0*(a[j+1]-a[j])/(r[i]-l[i]);
			db cnt=0;
			for(int k=1;k<=n;k++){
				if(i==k)continue;
				cnt++;
				db pl=max(0.0,1.0*min(a[j],r[k])-l[k])/(r[k]-l[k]);
				db pr=max(0.0,1.0*min(a[j+1],r[k])-l[k])/(r[k]-l[k]);
				for(int t=cnt;t>=0;t--){
					for(int p=cnt-t;p>=0;p--){
						f[t][p]*=1-pr;
						if(t)f[t][p]+=f[t-1][p]*pl;
						if(p)f[t][p]+=f[t][p-1]*(pr-pl);
					}
				}
			}
			for(int k=0;k<n;k++){
				for(int l=0;l+k<n;l++){
					ans[k]+=1.0/(l+1)*f[k][l];
					ans[k+l+1]-=1.0/(l+1)*f[k][l];
				}
			}
		}
		for(int j=0;j<n;j++){
			if(j)ans[j]+=ans[j-1];
			printf("%.15lf ",ans[j]);
		}
		puts("");
	}
}