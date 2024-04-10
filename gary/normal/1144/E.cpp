#include<bits/stdc++.h>
using namespace std;
int main(){
	int k;
	vector<int> v1,v2;
	scanf("%d",&k);
	char tmp;
	for(int i=1;i<=k;i++){
		cin>>tmp;
		v1.push_back(tmp-'a');
	}
	for(int i=1;i<=k;i++){
		cin>>tmp;
		v2.push_back(tmp-'a');
	}
	int sum[200001];
	for(int i=0;i<k;i++){
		v1[i+1]+=((v1[i]+v2[i])%2)*26;
		sum[i]=(v1[i]+v2[i])/2;
//		cout<<char(sum[i]+'a');
	}      
	for(int i=k-1;i>0;i--){
		if(sum[i]>=26){
			sum[i-1]+=sum[i]/26;
			sum[i]%=26;
		}
//		cout<<char(sum[i]+'a');
	}                          
	    for(int i=0;i<k;i++){
//		v1[i+1]+=((v1[i]+v2[i])%2)*26;
//		sum[i]=(v1[i]+v2[i])/2;
		cout<<char(sum[i]+'a');
	}                                                                                                                               
	return 0;
}