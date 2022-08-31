#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int nd[35];
int main(){
	int t;
	cin>>t;
	while(t--){
		memset(nd,0,sizeof(nd));
		string s1,s2;
		cin>>s1>>s2;
		bool N=0;
		for(int i=s2.size()-1,j=s1.size()-1;i>=0;i--){
			while(j>=0&&s1[j]!=s2[i]){
				j--;
			}
			if(j<0){
				N=1;
				break;
			}
			nd[j]=1;
			for(int k=j+1;k<s1.size();k++){
				if(s1[j]==s1[k]&&!nd[k]){
					N=1;
					break;
				}
			}
			if(N)break;
			j--;
		}
		if(N)puts("NO");
		else puts("YES");
	}
}