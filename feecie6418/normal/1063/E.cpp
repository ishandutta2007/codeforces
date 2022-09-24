#include<bits/stdc++.h>
using namespace std;
int n,p[1005],vst[1005],m;
char a[1005][1005];
int main(){
	cin>>n;
	bool o=1;
	for(int i=1;i<=n;i++)cin>>p[i],o&=(p[i]==i);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)a[i][j]='.';
	if(o){
		cout<<n<<'\n';
		for(int i=1;i<=n;i++){
			cout<<a[i]+1<<'\n';
		}
		return 0;
	}
	cout<<n-1<<'\n';
	for(int i=n;i>=1;i--){
		if(vst[i]||p[i]==i)continue;
		int j=p[i];
		vector<int> vec;
		vec.push_back(i),vst[i]=1;
		while(j!=i)vst[j]=1,vec.push_back(j),j=p[j];
		++m;
		int cur=m,x,y,p=max_element(vec.begin(),vec.end())-vec.begin();
		for(int j=(p+1)%vec.size();j!=p;j=(j+1)%vec.size()){
			x=vec[j],y=vec[(j+1)%vec.size()],++m;
			if(x<y)a[m][x]=a[m][y]='/';
			else a[m][y]=a[m][x]='\\';
		}
		if(vec[p]!=n){
			x=vec[p],y=vec[(p+1)%vec.size()];
			a[m][n]='/';
			a[cur][n]=a[cur][y]='\\';
		}
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]+1<<'\n';
	}
}