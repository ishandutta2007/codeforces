#include<bits/stdc++.h>
using namespace std;
char str[55],s[8]={0,'a','b','a','c','a','b','a'},b[55];
int n;
bool Judge(char str[],int p){
	for(int i=p,j=7;j;i--,j--){
		if(str[i]^s[j])return 0;
	}
	return 1;
}
bool Can(int p){
	for(int i=p,j=7;j;i--,j--){
		if(b[i]=='?')continue;
		if(b[i]^s[j])return 0;
	}
	return 1;
}
int main(){
	int T;
	cin>>T;
	while(T--){
		int cnt=0;
		cin>>n>>str+1;
		for(int i=7;i<=n;i++){
			if(Judge(str,i))cnt++;
		}
		if(cnt>1){
			puts("No");
			continue;
		}
		if(cnt==1){
			puts("Yes");
			for(int i=1;i<=n;i++){
				if(str[i]=='?')putchar('d');
				else cout<<str[i];
			}
			puts("");
			continue;
		} 
		int tmp=0;
		for(int i=7;i<=n;i++){
			memcpy(b,str,sizeof(b));
			if(Can(i)){
				for(int j=i-6,k=1;j<=i;j++,k++)b[j]=s[k];
				int cc=0;
				for(int j=7;j<=n;j++){
					if(Judge(b,j))cc++;
				}
				if(cc==1){
					memcpy(str,b,sizeof(b));
					tmp=1;
					break;
				}
			}
		}
		if(!tmp){
			puts("No");
			continue;
		}
		puts("Yes");
		for(int i=1;i<=n;i++){
			if(str[i]=='?')putchar('d');
			else cout<<str[i];
		}
		puts("");
	}
}