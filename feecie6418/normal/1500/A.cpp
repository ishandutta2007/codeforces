#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[200005],fx[5000005],fy[5000005],lst;
vector<int> v[2500005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]),v[a[i]].push_back(i);
		if(v[a[i]].size()==4){
			puts("YES");
			for(int j:v[a[i]])cout<<j<<' ';
			return 0;
		}
		if(v[a[i]].size()==2){
			if(lst)printf("YES\n%d %d %d %d\n",v[a[i]][0],v[lst][0],v[a[i]][1],v[lst][1]),exit(0);
			else lst=a[i];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(!fx[a[i]+a[j]])fx[a[i]+a[j]]=i,fy[a[i]+a[j]]=j;
			else {
				if(i!=fx[a[i]+a[j]]&&j!=fx[a[i]+a[j]]&&i!=fy[a[i]+a[j]]&&j!=fy[a[i]+a[j]]){
					printf("YES\n%d %d %d %d\n",i,j,fx[a[i]+a[j]],fy[a[i]+a[j]]);
					return 0;
				}
			}
		}
	}
	puts("NO");
	return 0;
}