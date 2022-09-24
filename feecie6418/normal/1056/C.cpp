#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pr;
int A[2005],B[2005],n,m,a[2005],used[2005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=2*n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>A[i]>>B[i];
	int t;
	cin>>t;
	if(t==1){
		for(int i=1;i<=m;i++){
			if(a[A[i]]<a[B[i]])swap(A[i],B[i]);
			cout<<A[i]<<endl;
			int x;
			cin>>x;
			used[A[i]]=used[x]=1;
		}
		for(int i=1;i<=n-m;i++){
			int mx=0,mxp=0;
			for(int j=1;j<=2*n;j++)if(!used[j]){if(a[j]>mx)mx=a[j],mxp=j;}
			cout<<mxp<<endl;
			int x;
			cin>>x;
			used[mxp]=used[x]=1;
		}
	}
	if(t==2){
		for(int i=1;i<=n;i++){
			int x;
			cin>>x;
			used[x]=1;
			int mx=0,mxp=0;
			for(int j=1;j<=m;j++){
				if(x==A[j]&&!used[B[j]])mxp=B[j];
				if(x==B[j]&&!used[A[j]])mxp=A[j];
			}
			if(!mxp){
				for(int j=1;j<=m;j++){
					if(!used[B[j]]&&!used[A[j]]){
						if(a[A[j]]>a[B[j]])mxp=A[j];
						else mxp=B[j];
					}
				}
			}
			if(!mxp){
				for(int j=1;j<=2*n;j++)if(!used[j]){if(a[j]>mx)mx=a[j],mxp=j;}
			}
			cout<<mxp<<endl;
			used[mxp]=1;
		}
	}
}