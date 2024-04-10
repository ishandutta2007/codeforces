
#include<bits/stdc++.h>
using namespace std;
int n,a[100],sum=0,b[100];
vector<int> ans[105];
int main() {
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	while(1){
		vector<int> tmp;
		int pos=0;
		for(int i=n;i>=1;i--)if(a[i]^i)pos=i;
		if(!pos)break;
		tmp.push_back(0);
		for(int i=1,f=0;i<=n&&!f;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]==a[j]+1){
					//cout<<i<<' '<<j<<endl;
					if(i>1)tmp.push_back(i-1);
					for(int k=i;k<j;k++){
						if(a[k]<a[k+1])continue;
						tmp.push_back(k);
						break;
					}
					f=1,tmp.push_back(j);
					if(j<n)tmp.push_back(n);
					break;
				}
			}
		}
		++sum;
		for(int i=1;i<tmp.size();i++)ans[sum].push_back(tmp[i]-tmp[i-1]);
		for(int i=tmp.size()-1,w=0;i>=1;i--){
			for(int j=tmp[i-1]+1;j<=tmp[i];j++)b[++w]=a[j];
		}
		for(int i=1;i<=n;i++)a[i]=b[i];
		//cout<<endl;
		//int s=0;
		//for(int i=1;i<n;i++)if(a[i]+1==a[i+1])s++;
		//cout<<s<<endl;
	}
	cout<<sum<<endl;
	for(int i=1;i<=sum;i++){
		cout<<ans[i].size()<<' ';
		for(int j:ans[i])cout<<j<<' ';
		cout<<endl;
	}
}