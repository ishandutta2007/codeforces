#include<bits/stdc++.h>
#define pdd pair<double,double>
#define pii pair<int,int>
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
	char c[100005];
	int cnt=0;
	scanf("%s",c);
	int ans=0;
	for(int i =0;c[i]!=0;i++){
		if(c[i]=='x'){
			cnt++;
		}
		else{
			cnt=0;
		}
		if(cnt>=3)
		ans++;
	}
	printf("%d\n",ans);
}