#include<bits/stdc++.h>
using namespace std;
string s;
int len,n,num,a[105],mindp[105][55][2],maxdp[105][55][2];
int main(){
	memset(mindp,0x3f,sizeof(mindp));
	memset(maxdp,-0x3f,sizeof(maxdp));
	mindp[1][0][1]=0;
	maxdp[1][0][1]=0;
	string tmp;
	cin>>tmp;
	len=tmp.length();
	s="#";s+=tmp;
	scanf("%d",&n);
	for(int i=1;i<=len;i++){
		for(int j=0;j<=n;j++){
			for(int k=0;k<=1;k++){
				//F
				int dep=(k==1? 1:-1);
				int kk=k;
				int jj=(s[i]=='F'? 0:1);
				mindp[i+1][jj+j][kk]=min(mindp[i+1][jj+j][kk],mindp[i][j][k]+dep);
				maxdp[i+1][jj+j][kk]=max(maxdp[i+1][jj+j][kk],maxdp[i][j][k]+dep);
				//T
				dep=0;
				kk=k^1;
				jj=(s[i]=='T'? 0:1);
				mindp[i+1][jj+j][kk]=min(mindp[i+1][jj+j][kk],mindp[i][j][k]+dep);
				maxdp[i+1][jj+j][kk]=max(maxdp[i+1][jj+j][kk],maxdp[i][j][k]+dep);
			}
		}
	}
//	for(int i=1;i<=len;i++){
//		for(int j=0;j<=n;j++){
//			for(int k=0;k<=1;k++){
//				cout<<i<<" "<<j<<" "<<k<<":"<<mindp[i][j][k]<<endl;
//				cout<<i<<" "<<j<<" "<<k<<":"<<maxdp[i][j][k]<<endl;
//			}
//		}
//	}
	int minrec=0x3f3f3f3f,maxrec=-0x3f3f3f3f;
	for(int j=n%2;j<=n;j+=2){
		for(int k=0;k<=1;k++){
			minrec=min(minrec,mindp[len+1][j][k]);
			maxrec=max(maxrec,maxdp[len+1][j][k]);
		}
	}
	printf("%d\n",max(maxrec,abs(minrec)));
	return 0;
}