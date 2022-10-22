#include<bits/stdc++.h>
using namespace std;
int cnt[42][42][42];
int month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
int main(){
	int res=0;
	int ans1,ans2,ans3;
	string s;
	cin>>s;
	int len=s.length();
	for(int i=0;i+9<len;i++){
		if(s[i+2]!='-'||s[i+5]!='-') continue;
		int OK=1;
		for(int j=0;j<10;j++){
			if(j!=2&&j!=5&&s[i+j]=='-') OK=0;
		}
		if(!OK) continue;
		int dd=(s[i]^48)*10+(s[i+1]^48),mm=(s[i+3]^48)*10+(s[i+4]^48),yy=(s[i+6]^48)*1000+(s[i+7]^48)*100+(s[i+8]^48)*10+(s[i+9]^48);
		if(mm<1||mm>12) continue;
		if(dd<1||dd>month[mm]) continue;
		if(yy<2013||yy>2015) continue;
		cnt[dd][mm][yy-2010]++;
		if(cnt[dd][mm][yy-2010]>res){
			res=cnt[dd][mm][yy-2010];
			ans1=dd;
			ans2=mm;
			ans3=yy-2010;
		}
	}
	printf("%d%d-%d%d-%d",ans1/10,ans1%10,ans2/10,ans2%10,ans3+2010);
	return 0;
}