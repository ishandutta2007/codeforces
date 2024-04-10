#include<bits/stdc++.h>
using namespace std;
int anstot,n,a[200001];
int maxval=-1,maxnum;
map<int,int> m;
vector<int> v1;
vector<int> v2;
vector<int> v3;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		m[a[i]]++;
		if(maxval<=m[a[i]]){
			maxval=m[a[i]];
			maxnum=a[i];
		}
	}
//	cout<<maxnum;
	for(int i=1;i<=n;i++){
		if(a[i]==maxnum){
			int j=i-1;
			while(a[j]!=maxnum&&j>=1){
				v2.push_back(j);
				v3.push_back(j+1); 
				if(a[j]<a[j+1]){
					v1.push_back(1);
				} 
				else{
					v1.push_back(2);
				}
				a[j]=maxnum; 
				j--;
			}
		}
	}
	for(int i=1;i<n;i++){
		if(a[i]==maxnum){
			int j=i+1;
			while(a[j]!=maxnum&&j<=n){
				v2.push_back(j);
				v3.push_back(j-1); 
				if(a[j-1]<a[j]){
					v1.push_back(2);
				} 
				else{
					v1.push_back(1);
				}
				a[j]=maxnum; 
				j++;
			}
		}
	}
	printf("%d\n",v1.size() );
	for(int i=1;i<=v1.size();i++){
		printf("%d %d %d\n",v1[i-1],v2[i-1],v3[i-1]);
	}
	return 0;
}