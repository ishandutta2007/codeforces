#include<bits/stdc++.h>
using namespace std;
int n,m;string zl;string s[60];int to[4]={0,1,2,3};
int bj(){
	int dqi,dqj;
	for(int i=0;i<n;++i)for(int j=0;j<m;++j)if(s[i][j]=='S')dqi=i,dqj=j;
	for(int i=0;i<zl.length();++i){
		if(to[zl[i]-'0']==0){
			if(dqi==0)return 0;
			dqi--;
			if(s[dqi][dqj]=='#')return 0;
			if(s[dqi][dqj]=='E')return 1;
		}
		if(to[zl[i]-'0']==1){
			if(dqi==n-1)return 0;
			dqi++;
			if(s[dqi][dqj]=='#')return 0;
			if(s[dqi][dqj]=='E')return 1;
		}
		if(to[zl[i]-'0']==2){
			if(dqj==0)return 0;
			dqj--;
			if(s[dqi][dqj]=='#')return 0;
			if(s[dqi][dqj]=='E')return 1;
		}
		if(to[zl[i]-'0']==3){
			if(dqj==m-1)return 0;
			dqj++;
			if(s[dqi][dqj]=='#')return 0;
			if(s[dqi][dqj]=='E')return 1;
		}
		
		//cout<<dqi<<dqj<<endl;
	}
	return 0;
}
int main(){
	
	cin>>n>>m;
	for(int i=0;i<n;++i)cin>>s[i];
	//for(int i=0;i<n;++i)cout<<s[i]<<endl;
	cin>>zl;
	//cout<<zl;
	int kk=0;
	for(int i=0;i<24;++i){
		kk+=bj();
		next_permutation(to,to+4);
	}
	cout<<kk;
}