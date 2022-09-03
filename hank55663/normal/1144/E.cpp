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
	int n;
	scanf("%d",&n);
	char c[200005];
	char c2[200005];
	scanf("%s %s",c,c2);
	for(int i=0;i<n;i++){
		c[i]-='a';
		c2[i]-='a';
	}
	for(int i = 0;i<n;i++){
		if((c[i]+c2[i])&1)
		c[i+1]+=26;
		//printf("%d",c[i]+c2[i]);
		c[i]=((c[i])+(c2[i]))/2+'a';
		//printf("%c",(c[i]+c2[i])/2);
	//	printf("%d ",c[i]);
	}
	for(int i = n-1;i>=0;i--){
		if(c[i]>'z'||c[i]<0)c[i]-=26,c[i-1]++;
	}
	printf("%s\n",c);
}