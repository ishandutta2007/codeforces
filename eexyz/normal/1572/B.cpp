#include<bits/stdc++.h>
using namespace std;
int T,n,i,pos,las,j,xo,s[1000005],qwq,cc[1000005],tot;
char ch;
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		xo=0;
		for(i=1;i<=n;++i)cin>>ch,s[i]=ch^'0',xo^=s[i];
		if(xo){cout<<"NO\n";continue;}
		s[n+1]=s[n+2]=0;
		pos=tot=0;
		for(las=i=1,qwq=s[i]==1?1:-1;i<=n;++i){
			if(s[i]!=s[i+1]){
				if(s[i]==1){
					if((i-qwq)&1){
						if(i==n&&qwq==1)break;
						if(i==n){
							for(j=qwq;j<i;j+=2)cc[++tot]=j-1;
						}
						else{
							for(j=i;j>qwq;j-=2)cc[++tot]=j-1;
						}
						qwq=-1;
					}
				}
				else{
					if(qwq!=-1&&((i-las+1)&1)){
						for(j=las;j<i;j+=2){
							cc[++tot]=j-1;
						}
						for(j=i-1;j>=qwq;j-=2)cc[++tot]=j;
						if(s[i+2]==0)qwq=-1,++i;
						else qwq=i+2;
					}
					else if(qwq!=-1){
						for(j=las;j<i;j+=2){
							cc[++tot]=j-1;
						}
					}
					else qwq=i+1;
				}
				las=i+1;
			}
		}
		if(qwq==-1){
			cout<<"YES\n";
			cout<<tot<<"\n";
			for(i=1;i<=tot;++i)cout<<cc[i]<<" ";
			cout<<'\n';
		}
		else cout<<"NO\n";
	}
}