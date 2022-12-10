#include<cstdio>
#include<string>
#include<iostream>
#include<cstring>
using namespace std;
char p[1000000+1],s[200+1];
int n,m,k,longest[2010];
string adds[2010],needs[2010];
string go(int cnt){
	for(int i=0;i<k;i++){
		adds[i]="";
		for(int pos=i;pos<n;pos+=k)adds[i]+=p[pos];
	}
	for(int i=0;i<cnt;i++){
		needs[i]="";
		for(int pos=i;pos<m;pos+=cnt)needs[i]+=s[pos];
	}
/*	cout<<k<<" ";
	for(int i=0;i<k;i++)cout<<adds[i]<<",";cout<<endl;
	cout<<cnt<<" ";
	for(int i=0;i<cnt;i++)cout<<needs[i]<<",";cout<<endl;*/
	longest[k]=0;
	for(int i=k-1;i>=0;i--){
		longest[i]=longest[i+1];
		if(longest[i]<cnt&&adds[i]==needs[cnt-1-longest[i]])++longest[i];
//		printf("%d -> %d\n",i,longest[i]);
	}
//	cout<<cnt<<" "<<longest[0]<<endl;
	if(longest[0]<cnt)return "";
	int pos=0,left=cnt;
	string ans="";
	for(int i=0;i<k;i++){
		if(longest[pos+1]>=left)ans+="0",++pos;else{
			ans+="1";
			--left;
			++pos;
		}
	}
//	cout<<ans<<endl;
	return ans;
}
main(){
	gets(p);
	gets(s);
	scanf(" %d",&k);
	n=strlen(p);
	m=strlen(s);
	string ans;
	for(int cnt=1;cnt<=k&&cnt<=m;cnt++){
		string tmp=go(cnt);
		if(tmp.size()&&(!ans.size()||tmp<ans))ans=tmp;
	}
	if(!ans.size())ans="0";
	printf("%s\n",ans.c_str());
}