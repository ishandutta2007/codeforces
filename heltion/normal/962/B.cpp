#include<bits/stdc++.h>
using namespace std;
int read(){int x;scanf("%d",&x);return x;}

int main(){
	int n=read(),a=read(),b=read();
	char*s=new char[n+1];
	scanf("%s",s);
	int i=0;
	int ans=0;
	vector<int> v;
	while(i<n){
		int j=i;
		while(j<n&&s[j]=='.')j++;
		v.push_back(j-i);
		i=j+1;
	}
	sort(v.begin(),v.end());
	for(auto&k:v){
		if(a>b)swap(a,b);
		ans+=min(b,(k+1)/2)+min(a,k/2);
		b-=min(b,(k+1)/2),a-=min(a,k/2);
	}
	cout<<ans<<endl;
}