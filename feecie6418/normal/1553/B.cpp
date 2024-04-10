#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
char a[1005],b[1005];
int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>a+1>>b+1;
		int n=strlen(a+1),m=strlen(b+1),flag=0;
		for(int i=1;i<=n&&!flag;i++){
			for(int j=i;j<=n&&!flag;j++){
				if(j-i+1>m||a[j]!=b[j-i+1])break;
				bool f=0;
				for(int k=j-1;k>=j-(m-(j-i+1));k--){
					if(a[k]!=b[(j-k)+(j-i+1)])f=1;
				}
				if(!f)flag=1;
			}
		}
		if(flag)puts("YES");
		else puts("NO");
	}
}