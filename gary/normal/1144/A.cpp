#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	char c[105];
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		bool OK=1;
		map<char,int> m;
		string s;
		cin>>s;
		int len=s.length();
		for(int i=0;i<len;i++){
			c[i+1]=s[i];
			if(m[s[i]]) {
				OK=0;
				break;
			}
			m[s[i]]=1;
		}
		if(!OK) printf("No\n");
		else{
			sort(c+1,c+1+len);
			for(int i=1;i<len;i++){
				if(c[i+1]!=c[i]+1){
					OK=0;
				}
			}
			if(OK){
				printf("Yes\n");
			}
			else{
				printf("No\n");
			}
		}
	}
	return 0;
}