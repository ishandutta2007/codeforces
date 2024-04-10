#include<bits/stdc++.h>
using namespace std;
int f[2][3];
int n;
string s;
int change(char c){
	if (c=='C')return 0;
	return c=='Y'?1:2;
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n;
	cin>>s;
	if (s[0]=='?'){
		f[0][0]=f[0][1]=f[0][2]=1;
	}else	f[0][change(s[0])]=1;
	bool bz=0,bz1=1;
	for (int i=1;i<n;i++,swap(bz,bz1)){
		if (s[i]=='?'){
			f[bz1][0]=min(f[bz][1]+f[bz][2],2);
			f[bz1][1]=min(f[bz][0]+f[bz][2],2);
			f[bz1][2]=min(f[bz][0]+f[bz][1],2);
		}else{
			for (int j=0;j<3;j++)
				if (j!=change(s[i]))
					f[bz1][change(s[i])]+=f[bz][j];
			f[bz1][change(s[i])]=min(f[bz1][change(s[i])],2);
		}
		f[bz][0]=f[bz][1]=f[bz][2]=0;
	}
	min(f[bz][0]+f[bz][1]+f[bz][2],2)==2?cout<<"Yes":cout<<"No";
	return 0;
}