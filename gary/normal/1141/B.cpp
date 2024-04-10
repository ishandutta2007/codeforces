#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	string s="";
	scanf("%d",&n);
	char c;
	for(int i=1;i<=n;i++){
		cin>>c;
		s+=c;
	}
	s+=s;
	int sum=0;
	int ans=0;
	n*=2;
	for(int i=0;i<n;i++){
		if(s[i]=='0') sum=0;
		else sum++;
//		cout<<s[i];
		ans=max(ans,sum);
	}
	
	printf("%d\n",ans);
	return 0;
}