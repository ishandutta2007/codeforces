#include<bits/stdc++.h>
using namespace std;
int m[2000001];
int Num[2000001];
string s[2000001];
char ans[2000001];
int main(){
	memset(m,-0x3f,sizeof(m));
	memset(ans,'a',sizeof(ans));
	int n,ma=-0x3f3f3f3f;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>s[i];
		int len=s[i].length();
		int t;
		scanf("%d",&t);
		while(t--){
			int st;
			scanf("%d",&st);
			ma=max(ma,st+len-1);
			if(m[st]<len){
				m[st]=len;
				Num[st]=i;
			}
		}
	}
	int next=0;
	for(int i=1;i<=ma;i++){
		if(m[i]+i<=next) continue;
		for(int j=max(next+1,i);j<s[Num[i]].length()+i;j++){
			ans[j]=s[Num[i]][j-i];
		}
		next=i+m[i]-1;
	}
	for(int i=1;i<=ma;i++) printf("%c",ans[i]);
	return 0;
}