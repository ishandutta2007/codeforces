#include<bits/stdc++.h>
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define cpii const pii
#define cpdd const pdd
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define sqr(x) ((x)*(x))
#define LL long long 
using namespace std;
int main(){
	char c[100005];
	scanf("%s",c);
	int cnt[11];
	fill(cnt,cnt+11,0);
	LL tot=0;
	for(int i =0;c[i]!=0;i++){
		//cnt[c[i]-'0']++;
		int temp[11];
		fill(temp,temp+11,0);
		for(int j=c[i]-'0'+1;j<11;j++){
			temp[(j*(j-1)/2+c[i]-'0'+10)%11]+=cnt[j];
		}
		if(c[i]!='0')
		temp[c[i]-'0']++;
		for(int j =0;j<11;j++){
			tot+=temp[j];
			cnt[j]=temp[j];
		//	printf("%d ",temp[j]);
		}
		//printf("%lld\n",tot);
	}
	printf("%lld\n",tot);
}
//y-x^2 = bx+c
// A= Bb+Cc
// D= Eb+Fc